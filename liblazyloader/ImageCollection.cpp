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
	return m_images[i];
}


void lload::CImageCollection::AddFront(IImage && image)
{
	m_images.emplace_front(std::move(image));
}

void lload::CImageCollection::AddBack(IImage && image)
{
	m_images.emplace_back(std::move(image));
}

void lload::CImageCollection::PopBack()
{
	m_images.pop_back();
}

void lload::CImageCollection::PopFront()
{
	m_images.pop_front();
}

void lload::CImageCollection::Clear()
{
	m_images.clear();
}

lload::IImage & lload::CImageCollection::operator[](size_t n)
{
	if (n >= m_images.size())
	{
		throw std::out_of_range("The index exceeds the upper limit");
	}
	return m_images[n];
}

const lload::IImage & lload::CImageCollection::operator[](size_t n) const
{
	return GetImage(n);
}