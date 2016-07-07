#include "stdafx.h"
#include "GdiPlus.h"
#include <gdiplus.h>


CGdiPlus::CGdiPlus()
{
	Gdiplus::GdiplusStartupInput input;
	GdiplusStartup(&m_token, &input, 0);
}


CGdiPlus::~CGdiPlus()
{
	Gdiplus::GdiplusShutdown(m_token);
}
