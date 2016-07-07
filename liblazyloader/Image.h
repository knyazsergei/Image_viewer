#pragma once
#include <Gdiplus.h>
#include <memory>
#include <string>

namespace lload 
{
class CImage
{
public:
	CImage(const CImage & img);
	CImage(CImage && img);
	CImage(const std::wstring & fileName);

	Gdiplus::Bitmap & GetBitmap() const;
	std::wstring GetFileName() const;
	void Resize(unsigned size);

	~CImage();
private:
	void Resize(unsigned width, unsigned height);
private:
	std::unique_ptr<Gdiplus::Bitmap> m_image;
	std::wstring m_imageName;
};
}