#include "stdafx.h"
#include "../liblazyloader/GdiPlus.h"
#include "../liblazyloader/Image.h"


BOOST_AUTO_TEST_SUITE(Check_class_CImage)
CGdiPlus gdiInit;
BOOST_AUTO_TEST_CASE(constructor)
{
	BOOST_CHECK_NO_THROW(lload::CImage(L"./images/0.png"));
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
	lload::CImage original(L"./images/0.png");
	auto copy(original);
	BOOST_CHECK(std::addressof(original.GetBitmap()) == std::addressof(copy.GetBitmap()));
}

BOOST_AUTO_TEST_CASE(check_image_resize)
{
	lload::CImage image(L"./images/0.png");


	auto width = image.GetBitmap().GetWidth();
	auto height = image.GetBitmap().GetHeight();

	image.Resize(100, 200);
	BOOST_CHECK(width != image.GetBitmap().GetWidth());
	BOOST_CHECK(height != image.GetBitmap().GetHeight());

	image.Resize(321, 123);
	//BOOST_CHECK(321 == image.GetBitmap().GetWidth());
	//BOOST_CHECK(123 == image.GetBitmap().GetHeight());
}

BOOST_AUTO_TEST_SUITE_END()

/*
BOOST_AUTO_TEST_SUITE(Check_class_CImageCollection)
CGdiPlus gdiInit;
BOOST_AUTO_TEST_CASE(collection_constructor)
{
	BOOST_CHECK_NO_THROW(lload::CImageCollection({ L"./images/0.png" }));
	std::vector<std::wstring> vec({ L"./images/0.png" });
	BOOST_CHECK_NO_THROW(lload::CImageCollection(vec.begin(), vec.end()));
}

BOOST_AUTO_TEST_CASE(get_image)
{
	lload::CImageCollection imageCollection({ L"./images/0.png" });
	BOOST_CHECK_EQUAL(imageCollection.GetImage(0).GetFileName().c_str(), L"./images/0.png");
	BOOST_CHECK_EQUAL(imageCollection[0].GetFileName().c_str(), L"./images/0.png");
}

BOOST_AUTO_TEST_CASE(get_size)
{
	lload::CImageCollection imageCollection({ L"./images/0.png" });
	BOOST_CHECK_EQUAL(imageCollection.GetSize(), 1);
}

BOOST_AUTO_TEST_CASE(Emplace_image)
{
	lload::CImageCollection imageCollection({ L"./images/0.png" });
	lload::CImage img(L"./images/1.png");
	imageCollection.EmplaceImage(img);
	BOOST_CHECK_EQUAL(imageCollection.GetSize(), 2);
	BOOST_CHECK_EQUAL(imageCollection.GetImage(1).GetFileName().c_str(), L"./images/1.png");
}

BOOST_AUTO_TEST_CASE(clear)
{
	lload::CImageCollection imageCollection({ L"./images/0.png", L"./images/1.png" });
	imageCollection.Clear();
	BOOST_CHECK_EQUAL(imageCollection.GetSize(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Check_class_CImageLoader)
CGdiPlus gdiInit;

BOOST_AUTO_TEST_CASE(set_and_get_image_page_size)
{
	lload::CImageLoader loader(L"./images/");
	BOOST_CHECK_EQUAL(loader.GetImagePageSize(), 10);
	loader.SetImagePageSize(0);
	BOOST_CHECK_EQUAL(loader.GetImagePageSize(), 0);
	loader.SetImagePageSize(30);
	BOOST_CHECK_EQUAL(loader.GetImagePageSize(), 30);
}

BOOST_AUTO_TEST_CASE(load_images_into_own_collection)
{
	CGdiPlus init;
	lload::CImageLoader loader(L"./images/");
	lload::CImageCollection collection;

	loader.Load(collection, 0);
	BOOST_CHECK_EQUAL(collection.GetSize(), 8);

	loader.SetImagePageSize(5);
	collection.Clear();
	loader.Load(collection, 0);
	BOOST_CHECK_EQUAL(collection.GetSize(), 5);

	collection.Clear();
	loader.Load(collection, 2);
	BOOST_CHECK_EQUAL(collection.GetImage(0).GetFileName().c_str(), L"./images/2.png");
}

BOOST_AUTO_TEST_CASE(change_path)
{
	CGdiPlus init;
	lload::CImageLoader loader(L"./images/");
	lload::CImageCollection collection;
	loader.ChangePath(L"./images/icons/");

	loader.Load(collection, 0);
	BOOST_CHECK_EQUAL(collection.GetSize(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
*/