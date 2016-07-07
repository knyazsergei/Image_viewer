#pragma once
#include "Image.h"
#include <vector>

namespace lload
{
	class CImageCollection
	{
	public:
		CImageCollection(std::vector<std::wstring> filesNames);
		CImageCollection(std::vector<std::wstring>::iterator filesNamesBegin, std::vector<std::wstring>::iterator filesNamesEnd);
		~CImageCollection();

		size_t Size() const;
		CImage const& GetImage(size_t i) const;

	private:
		std::vector<CImage> m_images;
	};
}