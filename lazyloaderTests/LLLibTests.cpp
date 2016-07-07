#include "stdafx.h"

#include "../liblazyloader/Image.h"
#include "../liblazyloader/GdiPlus.h"
BOOST_AUTO_TEST_SUITE(Check_class_CImage)
CGdiPlus gdiInit;
BOOST_AUTO_TEST_CASE(constructor_wchar)
{
	CGdiPlus gdiInit;
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
}
BOOST_AUTO_TEST_SUITE_END()