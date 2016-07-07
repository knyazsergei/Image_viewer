#include "stdafx.h"
#include "ImageLoader.h"
#include "LLException.h"

lload::CImageLoader::CImageLoader(const std::wstring & path, size_t pageSize):
	m_path(path),
	m_pageSize(pageSize)
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

void lload::CImageLoader::Load(CImageCollection & collection, size_t startIndex)
{
	if (m_files.size() == 0)
	{
		throw CLLException("The selected directory files are missing");
	}

	if (startIndex >= m_files.size())
	{
		throw std::out_of_range("The index exceeds the upper limit");
	}

	//Build range
	auto endIndex = startIndex + m_pageSize;
	if (endIndex > m_files.size())
	{
		endIndex = m_files.size();
	}

	for (auto it = begin(m_files) + startIndex; it != begin(m_files) + endIndex; ++it)
	{
		collection.EmplaceImage(CImage(m_path + (*it)));
	}
}

void lload::CImageLoader::ChangePath(const std::wstring & path)
{
	m_path = path;
	ReadFileList();
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
