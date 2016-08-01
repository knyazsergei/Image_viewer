#include "stdafx.h"
#include "../liblazyloader/GdiPlus.h"
#include "../liblazyloader/ImageCollection.h"

class CTestImage: public lload::IImage
{
public:
	CTestImage()
	{
	}
	~CTestImage()
	{
	}
	void Resize(unsigned width, unsigned height) override
	{
	}
	Gdiplus::Bitmap & GetBitmap() const override
	{
		 Gdiplus::Bitmap image(L"Test.png");
		 return image;
	};
	void SetFileName(std::wstring fileName)
	{
		m_fileName = fileName;
	}
	std::wstring GetFileName() const
	{
		return m_fileName;
	}
private:
	std::wstring m_fileName;
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
	//BOOST_CHECK_EQUAL(value.GetSize(), 1);
	//BOOST_CHECK_EQUAL(value.GetImage(0), L"1");
}
BOOST_AUTO_TEST_SUITE_END()