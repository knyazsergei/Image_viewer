#pragma once

namespace lload
{
class IImage
{
public:
	IImage() = default;
	~IImage() = default;
	virtual void Resize(unsigned width, unsigned height) {};
	virtual Gdiplus::Bitmap & GetBitmap() const { return *image; };
private:
	Gdiplus::Bitmap *  image;
};
}
