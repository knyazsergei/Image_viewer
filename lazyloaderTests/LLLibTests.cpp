#include "stdafx.h"

#include "../liblazyloader/Image.h"
#include "../liblazyloader/ImageCollection.h"
#include "../liblazyloader/GdiPlus.h"


BOOST_AUTO_TEST_SUITE(Check_class_CImage)
CGdiPlus gdiInit;
BOOST_AUTO_TEST_CASE(constructor_wchar)
{
	BOOST_CHECK_NO_THROW(lload::CImage(L"./images/0.png"));
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
	lload::CImage original(L"./images/0.png");
	lload::CImage copy(original);
	BOOST_CHECK_EQUAL(original.GetFileName().c_str(), copy.GetFileName().c_str());
	BOOST_CHECK_EQUAL(original.GetBitmap().GetWidth(), copy.GetBitmap().GetWidth());
	BOOST_CHECK_EQUAL(original.GetBitmap().GetHeight(), copy.GetBitmap().GetWidth());
	BOOST_CHECK_EQUAL(original.GetBitmap().GetPixelFormat(), copy.GetBitmap().GetPixelFormat());
	BOOST_CHECK(std::addressof(original.GetBitmap()) != std::addressof(copy.GetBitmap()));
}

BOOST_AUTO_TEST_CASE(move_constructor)
{
	lload::CImage original(L"./images/0.png");
	lload::CImage copy(original);

	lload::CImage move(std::move(original));

	BOOST_CHECK_EQUAL(move.GetFileName().c_str(), copy.GetFileName().c_str());
	BOOST_CHECK_EQUAL(move.GetBitmap().GetWidth(), copy.GetBitmap().GetWidth());
	BOOST_CHECK_EQUAL(move.GetBitmap().GetHeight(), copy.GetBitmap().GetWidth());
	BOOST_CHECK_EQUAL(move.GetBitmap().GetPixelFormat(), copy.GetBitmap().GetPixelFormat());
}

BOOST_AUTO_TEST_CASE(check_image_resize)
{
	lload::CImage image(L"./images/0.png");


	auto width = image.GetBitmap().GetWidth();
	auto height = image.GetBitmap().GetHeight();

	image.Resize(100);
	BOOST_CHECK(width != image.GetBitmap().GetWidth());
	BOOST_CHECK(height != image.GetBitmap().GetHeight());

	image.Resize(100);
	BOOST_CHECK(100 == image.GetBitmap().GetWidth());
	BOOST_CHECK(100 == image.GetBitmap().GetHeight());
}

BOOST_AUTO_TEST_CASE(check_get_file_name)
{
	lload::CImage image(L"./images/0.png");
	BOOST_CHECK_EQUAL(image.GetFileName().c_str(), L"./images/0.png");
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Check_class_CImageCollection)
CGdiPlus gdiInit;
BOOST_AUTO_TEST_CASE(collection_constructor)
{
	BOOST_CHECK_NO_THROW(lload::CImageCollection({ L"./images/0.png" }));
	std::vector<std::wstring> vec({ L"./images/0.png" });
	BOOST_CHECK_NO_THROW(lload::CImageCollection(vec.begin(), vec.end()));
}

BOOST_AUTO_TEST_SUITE_END()