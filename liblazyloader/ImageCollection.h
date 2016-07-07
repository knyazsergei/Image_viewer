#pragma once
#include "Image.h"
#include <vector>

namespace lload
{
	class CImageCollection
	{
	public:
		CImageCollection() = default;
		CImageCollection(std::vector<std::wstring> filesNames);
		CImageCollection(std::vector<std::wstring>::iterator filesNamesBegin, std::vector<std::wstring>::iterator filesNamesEnd);
		~CImageCollection() = default;

		size_t GetSize() const;
		CImage const& GetImage(size_t i) const;
		void EmplaceImage(CImage & image);
		void Clear();
	private:
		std::vector<CImage> m_images;
	};
}