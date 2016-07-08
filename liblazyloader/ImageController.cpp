#include "stdafx.h"
#include "ImageController.h"


lload::CImageController::CImageController()
{
	m_imageLoader = std::make_unique<CImageLoader>(L"./images/");
	m_imageLoader->SetImagePageSize(m_pageSize);

	//load first page
	m_collections.push_back({});
	m_imageLoader->Load(m_collections.back(), 0);
	m_currentCollection = m_collections.begin();
	m_currentCollectionIndex = 0;
	UpdateCollections(false);//load next page
}

bool lload::CImageController::NeedUpdate()
{
	return m_needUpdate;
}

void lload::CImageController::NextPage()
{
	if(m_currentCollection != m_collections.end())
	{
		
		m_currentCollectionIndex++;
		m_currentCollection++;
		
		UpdateCollections(false);
	}
}

void lload::CImageController::PrevPage()
{
	if (m_currentCollectionIndex > 0)
	{
		m_currentCollectionIndex--;
		m_currentCollection--;
		UpdateCollections(true);
	}	
}

lload::CImageCollection & lload::CImageController::GetPage()
{
	return *m_currentCollection;
}

void lload::CImageController::UpdateCollections(bool left)
{
	if (left)
	{
		//load left page
		if (m_currentCollectionIndex > 0)
		{
			m_collections.push_front({});
			m_imageLoader->Load(m_collections.front(), (m_currentCollectionIndex - 1) * m_pageSize);
			if (m_collections.size() > 3 && m_currentCollectionIndex != 0)
			{
				m_collections.pop_back();
			}
		}
	}
	else if (m_currentCollectionIndex * m_pageSize < m_imageLoader->GetFileNumber())
	{
		std::cout << m_currentCollectionIndex * m_pageSize << " " << m_imageLoader->GetFileNumber() << '\n';
		//load right page
		m_collections.push_back({});
		try
		{
			m_imageLoader->Load(m_collections.back(), (m_currentCollectionIndex + 1) * m_pageSize);
		}
		catch (...)
		{
			m_collections.pop_back();
		}
		

		if (m_collections.size() > 3)
		{
			m_collections.pop_front();
		}
	}
}
