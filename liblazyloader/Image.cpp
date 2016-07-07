#include "stdafx.h"
#include <guiddef.h>
#include <atlbase.h>
#include "Image.h"
#include "LLException.h"
#include <string>
#include <memory>


lload::CImage::CImage(const std::wstring & fileName):
	m_imageName(fileName)	
{

	m_image = std::make_unique<Gdiplus::Bitmap>(fileName.c_str());

	if(m_image == nullptr || m_image->GetLastStatus() != Gdiplus::Status::Ok)
	{
		throw std::runtime_error("Image loading error");
	}
}

lload::CImage::CImage(CImage && img):
	m_imageName(img.GetFileName())
{
	m_image.swap(img.m_image);
}

lload::CImage::CImage(const CImage & img) :
	m_imageName(img.GetFileName())
{
	m_image = std::make_unique<Gdiplus::Bitmap>(img.GetBitmap().GetWidth(), img.GetBitmap().GetHeight(), img.GetBitmap().GetPixelFormat());
}

Gdiplus::Bitmap & lload::CImage::GetBitmap() const
{
	if (m_image == nullptr)
	{
		throw std::runtime_error("Image is absent " + std::string(m_imageName.begin(), m_imageName.end()));
	}
	return (*m_image.get());
}

std::wstring lload::CImage::GetFileName() const
{
	return m_imageName;
}

void lload::CImage::Resize(unsigned width, unsigned height)
{
	if(m_image == nullptr)
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

	Gdiplus::Rect rect(0, 0, n_width, n_height);
	auto newBitmap = std::make_unique<Gdiplus::Bitmap>(n_width, n_height, m_image->GetPixelFormat());
	Gdiplus::Graphics graphics(newBitmap.get());
	graphics.Clear(Gdiplus::Color::White);

	graphics.DrawImage(m_image.get(), rect);
	m_image.swap(newBitmap);
}

lload::CImage::~CImage()
{
	m_image.reset();
}

void lload::CImage::Resize(unsigned size)
{
	Resize(size, size);
}
