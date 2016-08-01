#pragma once

namespace lload
{
class IImage
{
public:
	IImage() = default;
	virtual ~IImage() = default;
	virtual void Resize(unsigned width, unsigned height) {};
	virtual Gdiplus::Bitmap & GetBitmap() const = 0;
private:
	Gdiplus::Bitmap * image;
};
}
