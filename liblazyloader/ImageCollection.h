#pragma once
#include "Image.h"
#include <deque>

namespace lload
{
class CImageCollection
{
public:
	CImageCollection() = default;
	~CImageCollection() = default;

	size_t GetSize() const;
	IImage const & GetImage(size_t i) const;

	void AddFront(IImage && image);
	void AddBack(IImage && image);

	void PopBack();
	void PopFront();

	void Clear();

	IImage & operator[](size_t n);
	const IImage & operator[](size_t n)const;

private:
	std::deque<IImage> m_images;
};
}