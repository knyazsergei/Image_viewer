#include "stdafx.h"
#include <guiddef.h>
#include <atlbase.h>
#include <string>
#include <memory>
#include "Image.h"
#include "LLException.h"

lload::CImage::CImage(const std::wstring & fileName):
	m_image(std::make_shared<Gdiplus::Bitmap>(fileName.c_str()))
{
	if(m_image == nullptr || m_image->GetLastStatus() != Gdiplus::Status::Ok)
	{
		throw std::runtime_error("Image loading error");
	}
}

lload::CImage::CImage(const CImage & img):
	m_image(img.m_image)
{
}

Gdiplus::Bitmap & lload::CImage::GetBitmap() const
{
	if (m_image == nullptr)
	{
		throw std::runtime_error("Image is absent");
	}
	return (*m_image.get());
}

lload::CImage::CImage(CImage && img):
	m_image(std::move(img.m_image))
{
}

void lload::CImage::Resize(unsigned width, unsigned height)
{
	if (m_image == nullptr)
	{
		return;
	}

	UINT o_height = m_image->GetHeight();
	UINT o_width = m_image->GetWidth();

	INT n_width = width;
	INT n_height = height;

	double ratio = ((double)o_width) / ((double)o_height);
	if (o_width > o_height)
	{
		n_height = static_cast<UINT>(((double)n_width) / ratio);
	}
	else
	{
		n_width = static_cast<UINT>(n_height * ratio);
	}

	auto newBitmap = std::make_shared<Gdiplus::Bitmap>(n_width, n_height, m_image->GetPixelFormat());
	Gdiplus::Graphics graphics(newBitmap.get());
	graphics.Clear(Gdiplus::Color::White);
	graphics.DrawImage(m_image.get(), Gdiplus::Rect({ 0, 0, n_width, n_height }));
	m_image.swap(newBitmap);
}