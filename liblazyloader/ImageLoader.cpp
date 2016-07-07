#include "stdafx.h"
#include "ImageLoader.h"


lload::CImageLoader::CImageLoader(const std::wstring & path):
	m_path(path)
{
	ReadFileList();
}

size_t lload::CImageLoader::GetImagePageSize() const
{
	return m_pageSize;
}

void lload::CImageLoader::SetImagePageSize(size_t size)
{
	m_pageSize = size;
}

void lload::CImageLoader::Load(CImageCollection & images, size_t startIndex)
{

}

void lload::CImageLoader::ReadFileList()
{
	auto path = m_path;
	path += '*';
	m_files.clear();

	WIN32_FIND_DATA file_data;
	HANDLE h_file = FindFirstFile(path.c_str(), &file_data);
	if (h_file != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				m_files.push_back(file_data.cFileName);
			}

		} while (FindNextFile(h_file, &file_data));
		FindClose(h_file);
	}
}
