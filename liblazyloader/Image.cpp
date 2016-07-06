#include "stdafx.h"
#include "Image.h"


using namespace Gdiplus;


lload::CImage::CImage(const std::wstring & fileName):
	m_imageName(fileName)
{
	m_image = std::make_unique<Bitmap>(fileName.c_str());
	GUID guidFileFormat;

	m_image->GetRawFormat(&guidFileFormat);
	if (guidFileFormat != ImageFormatJPEG &&
		guidFileFormat != ImageFormatPNG &&
		guidFileFormat != ImageFormatBMP &&
		guidFileFormat != ImageFormatTIFF &&
		guidFileFormat != ImageFormatIcon) 
	{
		throw CLLException("Invalid image format");
	}
}

Bitmap & lload::CImage::GetBitmap() const
{
	if (m_image == nullptr)
	{
		throw std::runtime_error("Image is absent")
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

	Rect rect(0, 0, n_width, n_height);
	auto newBitmap = std::make_unique<Gdiplus::Bitmap>(n_width, n_height, m_image->GetPixelFormat());
	Graphics graphics(newBitmap.get());
	graphics.Clear(Color::White);

	graphics.DrawImage(m_image.get(), rect);
	m_image.swap(newBitmap);
}

void lload::CImage::Resize(unsigned size)
{
	Resize(size, size);
}
