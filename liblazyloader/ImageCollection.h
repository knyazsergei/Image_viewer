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

	void AddFront(std::unique_ptr<IImage> image);
	void AddBack(IImage && image);

	void PopBack();
	void PopBack(size_t size);
	void PopFront();
	void PopFront(size_t size);

	void Clear();
private:
	std::deque<std::unique_ptr<IImage>> m_images;
};
}