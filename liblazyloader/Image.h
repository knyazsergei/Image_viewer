#pragma once
#include <Gdiplus.h>
#include <memory>
#include <string>
#include "IImage.h"


namespace lload 
{
class CImage: public IImage
{
public:
	CImage(const std::wstring & fileName);
	CImage(const CImage & img);

	void Resize(unsigned width, unsigned height) override final;
	Gdiplus::Bitmap & GetBitmap() const override final;

	~CImage() = default;
private:
	CImage(CImage && img);
private:
	std::shared_ptr<Gdiplus::Bitmap> m_image;
};
}