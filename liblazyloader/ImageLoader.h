#pragma once
#include "ImageCollection.h"

namespace lload
{
class CImageLoader
{
public:
	CImageLoader(std::wstring const& path);
	~CImageLoader() = default;

	size_t GetImagePageSize() const;
	void SetImagePageSize(size_t size);

	void Load(CImageCollection& images, size_t startIndex);
private:
	void ReadFileList();
private:
	size_t m_pageSize;
	std::wstring m_path;

	std::vector<std::wstring> m_files;
};
}
