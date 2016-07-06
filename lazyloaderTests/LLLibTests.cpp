#include "stdafx.h"
#include "../liblazyloader/Image.h"

BOOST_AUTO_TEST_SUITE(Check_class_CImage)
BOOST_AUTO_TEST_CASE(constructor_wchar)
{
	BOOST_CHECK_NO_THROW(lload::CImage(L"./images/0.png"));
}
BOOST_AUTO_TEST_SUITE_END()