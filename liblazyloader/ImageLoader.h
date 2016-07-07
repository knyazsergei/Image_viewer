#pragma once
#include "ImageCollection.h"

namespace lload
{
class CImageLoader
{
public:
	CImageLoader(const std::wstring & path = L"./", size_t pageSize = 10);
	~CImageLoader() = default;

	size_t GetImagePageSize() const;
	void SetImagePageSize(size_t size);

	void Load(CImageCollection & collection, size_t startIndex);
	void ChangePath(const std::wstring & path);
private:
	void ReadFileList();
private:
	size_t m_pageSize;
	std::wstring m_path;

	std::vector<std::wstring> m_files;
};
}
