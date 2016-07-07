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

	size_t endIndex = startIndex + m_pageSize;
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

size_t lload::CImageLoader::GetFileNumber()
{
	return m_files.size();
}

void lload::CImageLoader::ReadFileList()
{
	auto path = m_path;
	path += '*';
	m_files.clear();

	WIN32_FIND_DATA file_data;
	HANDLE h_file = FindFirstFile(path.c_str(), &file_data);
	if (h_file == INVALID_HANDLE_VALUE)
	{
		return;
	}
	do
	{
		auto fileName = std::wstring(file_data.cFileName);
		auto extention = fileName.substr(fileName.find_last_of(L".") + 1);
		auto isImageExtention = [](const std::wstring & ext)->bool {
			if  ((ext == L"jpeg")||
				(ext == L"jpg")||
				(ext == L"png")||
				(ext == L"bmp")||
				(ext == L"gif"))
			{
				return true;
			}
			return false;
		};
		if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && isImageExtention(extention))
		{
			Gdiplus::Bitmap image((m_path + fileName).c_str());
			//auto name = std::string(std::begin(file_data.cFileName), std::end(file_data.cFileName));
			auto status = image.GetLastStatus();
			if (status == Gdiplus::Status::Ok)
			{
				m_files.push_back(fileName);
			}
		}
	} while (FindNextFile(h_file, &file_data));
	FindClose(h_file);
	
}
