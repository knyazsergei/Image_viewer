#include "stdafx.h"
#include "ImageCollection.h"


size_t lload::CImageCollection::GetSize() const
{
	return m_images.size();
}

lload::IImage const & lload::CImageCollection::GetImage(size_t i) const
{
	if(i >= m_images.size())
	{
		throw std::out_of_range("The index exceeds the upper limit");
	}
	return *m_images[i];
}


void lload::CImageCollection::AddFront(std::unique_ptr<IImage> image)
{
	m_images.emplace_front(image.release());
}

void lload::CImageCollection::AddBack(IImage && image)
{
	//m_images.emplace_back(image);
}

void lload::CImageCollection::PopBack()
{
	m_images.pop_back();
}

void lload::CImageCollection::PopBack(size_t size)
{
	m_images.erase(m_images.end() - size, m_images.end());
}

void lload::CImageCollection::PopFront()
{
	m_images.pop_front();
}

void lload::CImageCollection::PopFront(size_t size)
{
	m_images.erase(m_images.begin(), m_images.begin() + size);
}

void lload::CImageCollection::Clear()
{
	m_images.clear();
}