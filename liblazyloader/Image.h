#pragma once
#include <Gdiplus.h>

#include <guiddef.h>
#include <atlbase.h>
#include <memory>
#include <string>
#include "LLException.h"

namespace lload {
	using namespace Gdiplus;
	class CImage
	{
	public:
		CImage() = default;
		CImage(const std::wstring & fileName);
		Bitmap & GetBitmap() const;
		std::wstring GetFileName() const;
		void Resize(unsigned width, unsigned height);
		void Resize(unsigned size);
		~CImage() = default;
	private:
		std::unique_ptr<Bitmap> m_image;
		std::wstring m_imageName;
	};
}