#include "stdafx.h"
#include "ImageController.h"


lload::CImageController::CImageController()
{
	m_imageLoader = std::make_unique<CImageLoader>(L"./images/");
	m_imageLoader->SetImagePageSize(m_pageSize);

	m_collections.push_back({});
	m_imageLoader->Load(m_collections.back(), 0);
	m_currentCollection = m_collections.begin();
}

bool lload::CImageController::NeedUpdate()
{
	return m_needUpdate;
}

void lload::CImageController::NextPage()
{
	if (m_currentCollectionIndex == m_collections.size() - 1)
	{
		m_currentCollectionIndex = 0;
		m_currentCollection = std::begin(m_collections);
	}
	else if(m_collections.size() != 0)
	{
		m_currentCollectionIndex++;
		m_currentCollection++;
	}

	UpdateCollections(false);
}

void lload::CImageController::PrevPage()
{
	if (m_currentCollectionIndex == 0)
	{
		if (m_collections.size() != 0)
		{
			m_currentCollectionIndex = m_collections.size() - 1;
		}
		m_currentCollection = std::end(m_collections);
	}
	else
	{
		m_currentCollectionIndex--;
		m_currentCollection--;
	}
	
	UpdateCollections(true);
}

lload::CImageCollection & lload::CImageController::GetPage()
{
	return *m_currentCollection;
}

void lload::CImageController::UpdateCollections(bool left)
{
	if (left)
	{
		if (m_currentCollectionIndex > 0)
		{
			m_collections.push_front({});
			m_imageLoader->Load(m_collections.front(), (m_currentCollectionIndex - 1) * m_pageSize);
			if (m_collections.size() > 3)
			{
				m_collections.pop_back();
			}
			else if (m_collections.size() == 1)
			{
				m_currentCollection = m_collections.begin();
			}
		}
	}
	else
	{
		if (m_currentCollectionIndex * m_pageSize < m_imageLoader->GetFileNumber())
		{
			m_collections.push_back({});
			m_imageLoader->Load(m_collections.back(), (m_currentCollectionIndex + 1) * m_pageSize);
			if (m_collections.size() > 3)
			{
				m_collections.pop_front();
			}
			else if (m_collections.size() == 1)
			{
				m_currentCollection = m_collections.begin();
			}
		}
	}
}
