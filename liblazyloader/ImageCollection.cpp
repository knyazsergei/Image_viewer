#include "stdafx.h"
#include "ImageCollection.h"


lload::CImageCollection::CImageCollection(std::vector<std::wstring> filesNames)
{
	GdiInit();
	for(const auto & fileName:filesNames)
	{
		m_images.push_back(CImage(fileName));
	}
}

lload::CImageCollection::CImageCollection(std::vector<std::wstring>::iterator filesNamesBegin, std::vector<std::wstring>::iterator filesNamesEnd)
{
	GdiInit();
	for(auto fileName = filesNamesBegin; fileName != filesNamesEnd; fileName++)
	{
		m_images.push_back(CImage(*fileName));
	}
}

lload::CImageCollection::~CImageCollection()
{
	GdiplusShutdown(m_gdiToken);
}

size_t lload::CImageCollection::Size() const
{
	return m_images.size();
}

lload::CImage const& lload::CImageCollection::GetImage(size_t i) const
{
	if(i > m_images.size())
	{
		throw std::out_of_range("The index exceeds the upper limit");
	}
	return m_images[i];
}

void lload::CImageCollection::GdiInit()
{
	GdiplusStartupInput input;
	GdiplusStartup(&m_gdiToken, &input, 0);
}
