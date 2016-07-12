#include "stdafx.h"
#include "ImageController.h"


lload::CImageController::CImageController(std::vector<std::wstring> && files):
	m_files(files)
{	
}

bool lload::CImageController::NeedUpdate()
{
	return m_needUpdate;
}

void lload::CImageController::UpdateScrollPosition(size_t position)
{
	if (position > m_scrollPosition)
	{
		for (size_t i = 0;
			(i < m_scrollPosition - position) && (m_fileFramePosition + m_currentCollection.GetSize() < m_files.size());
			i++, m_fileFramePosition++)
		{
			m_currentCollection.AddBack(CImage(m_files[m_fileFramePosition + m_currentCollection.GetSize()]));
			if (m_currentCollection.GetSize() > 10)
			{
				m_currentCollection.PopFront();
			}
		}
	}
	else
	{
		for (size_t i = 0; (i < m_scrollPosition - position) && (m_fileFramePosition > 0); i--, m_fileFramePosition--)
		{
			m_currentCollection.AddFront(CImage(m_files[m_fileFramePosition]));
			if (m_currentCollection.GetSize() > 10)
			{
				m_currentCollection.PopBack();
			}
		}
	}
	m_scrollPosition = position;
}

lload::CImageCollection & lload::CImageController::GetPage()
{
	return m_currentCollection;
}