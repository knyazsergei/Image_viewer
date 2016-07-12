#include "stdafx.h"
#include "../liblazyloader/GdiPlus.h"
#include "../liblazyloader/Image.h"
#include "../liblazyloader/ImageCollection.h"

class CTestImage: public lload::IImage
{
public:
	CTestImage()
	{
		image = new Gdiplus::Bitmap(INT(0), INT(0), Gdiplus::PixelFormat());
	}
	~CTestImage()
	{
		delete image;
	}
	std::wstring GetFileName()
	{
		return m_filename;
	}
	void SetFileName(std::wstring filename)
	{
		m_filename = filename;
	}

	Gdiplus::Bitmap & GetImage() const
	{
		return *image;
	}
private:
	Gdiplus::Bitmap *  image;
	std::wstring m_filename;
};

struct SCollection
{
	lload::CImageCollection value;
};

BOOST_FIXTURE_TEST_SUITE(image_collection, SCollection)

CGdiPlus gdiInit;

BOOST_AUTO_TEST_CASE(constructor)
{
	lload::CImageCollection collection;
	BOOST_CHECK(collection.GetSize() == 0);
}

BOOST_AUTO_TEST_CASE(add_image)
{
	CTestImage image;
	image.SetFileName(L"1");
	value.AddBack(std::move(image));
	BOOST_CHECK_EQUAL(value.GetSize(), 1);
	CTestImage * newImage = &value.GetImage(0);
	BOOST_CHECK_EQUAL(fileName, L"1");
}
BOOST_AUTO_TEST_SUITE_END()