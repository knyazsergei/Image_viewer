#pragma once
#include <list>
#include <iterator>
#include "ImageLoader.h"
#include "ImageCollection.h"
#include "GdiPlus.h"

namespace lload
{
class CImageController
{
public:
	CImageController();
	~CImageController() = default;

	bool NeedUpdate();
	
	void NextPage();
	void PrevPage();

	CImageCollection & GetPage();
private:
	void UpdateCollections(bool left);
private:
	std::list<CImageCollection> m_collections;
	std::list<CImageCollection>::iterator m_currentCollection;
	size_t m_currentCollectionIndex = 0;


	CGdiPlus m_gdiplus;
	std::unique_ptr<CImageLoader> m_imageLoader;

	bool m_needUpdate = true;
	size_t m_pageSize = 2;
};
}
