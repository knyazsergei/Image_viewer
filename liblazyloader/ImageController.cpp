#include "stdafx.h"
#include "ImageController.h"


lload::CImageController::CImageController(std::vector<std::wstring> && files):
	m_files(files)
{	
}

void lload::CImageController::UpdateScrollPosition(size_t position)
{
	if (position > m_scrollPosition)
	{
		LoadBack(position);
	}
	else
	{
		LoadUp(position);
	}
	m_scrollPosition = position;
}

lload::CImageCollection & lload::CImageController::GetPage()
{
	return m_currentCollection;
}

void lload::CImageController::LoadUp(size_t position)
{
	for (size_t i = 0; (i < m_scrollPosition - position) && (m_fileFramePosition > 0); i--, m_fileFramePosition--)
	{
		m_currentCollection.AddFront(std::make_unique<CImage>(m_files[m_fileFramePosition]));
	}
	CorrectCollectionSize();
}

void lload::CImageController::LoadBack(size_t position)
{
	for (size_t i = 0;
		(i < m_scrollPosition - position) && (m_fileFramePosition + m_currentCollection.GetSize() < m_files.size());
		i++, m_fileFramePosition++)
	{
		m_currentCollection.AddBack(CImage(m_files[m_fileFramePosition + m_currentCollection.GetSize()]));
	}
	CorrectCollectionSize();
}

void lload::CImageController::CorrectCollectionSize()
{
	if (m_currentCollection.GetSize() > MAX_COLLECTION_SIZE)
	{
		m_currentCollection.PopBack();
	}
}
