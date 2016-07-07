#include "stdafx.h"
#include "ImageController.h"


lload::CImageController::CImageController(std::wstring const& path)
{
	ReadFileList(path);
}

lload::CImageController::~CImageController()
{
}

void lload::CImageController::SetImagePageSize(size_t size)
{
	m_imagePageSize = size;
}

size_t lload::CImageController::GetImagePageSize() const
{
	return m_imagePageSize;
}


void lload::CImageController::NextPage()
{
	if (m_collections.size() == 0)
	{
		return;
	}

	if (m_currentCollectionIndex == m_collections.size() - 1)
	{
		m_currentCollectionIndex = 0;
		m_currentCollection = begin(m_collections);
	}
	else
	{
		m_currentCollectionIndex++;
		m_currentCollection++;
	}
	Load(Diraction::right);
}

void lload::CImageController::PrevPage()
{
	if(m_collections.size() == 0)
	{
		return;
	}

	if (m_currentCollectionIndex == 0)
	{
		m_currentCollectionIndex = m_collections.size() - 1;
		m_currentCollection = end(m_collections);
	}
	else
	{
		m_currentCollectionIndex--;
		m_currentCollection--;
	}
	Load(Diraction::left);
}

void lload::CImageController::Load(Diraction dir)
{
	switch (dir)
	{
	case lload::CImageController::Diraction::left:
		break;
	case lload::CImageController::Diraction::right:
		break;
	default:
		break;
	}
}

void lload::CImageController::Load(size_t startIndex)
{
	if(m_files.size() == 0)
	{
		return;
	}
	if (startIndex >= m_files.size())
	{
		throw std::out_of_range("The index exceeds the upper limit");
	}

	//Build range
	auto endIndex = startIndex + m_imagePageSize;
	if (endIndex >= m_files.size())
	{
		endIndex = endIndex - m_files.size() + startIndex;
	}

	m_collections.push_back({ begin(m_files) + startIndex, begin(m_files) + endIndex });
	
	//Remove old collections
	if (m_collections.size() > MAXIMUM_COLLECTIONS_NUMBER)
	{
		if (m_currentCollectionIndex > ceil(m_collections.size() % 2))
		{
			m_collections.pop_front();
		}
		else
		{
			m_collections.pop_front();
		}
	}
}

void lload::CImageController::ReadFileList(std::wstring path)
{
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