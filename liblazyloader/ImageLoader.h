#pragma once
#include "ImageCollection.h"

namespace lload
{
class CImageLoader
{
public:
	CImageLoader(std::wstring const& path);
	~CImageLoader() = default;

	void Load(CImageCollection& images, size_t startIndex);
private:
	size_t m_pageSize;
	std::wstring m_path;
};
}
