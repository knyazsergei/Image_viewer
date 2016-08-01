#pragma once
#include <vector>
#include "ImageCollection.h"
#include "GdiPlus.h"

namespace lload
{
class CImageController
{
public:
	CImageController(std::vector<std::wstring> && files);
	~CImageController() = default;

	void UpdateScrollPosition(size_t position);

	CImageCollection & GetPage();
private:
	void LoadUp(size_t position);
	void LoadBack(size_t position);
	
	void CorrectCollectionSize();
private:
	CGdiPlus m_gdiplus;
	
	lload::CImageCollection m_currentCollection;
	
	std::vector<std::wstring> m_files;

	size_t m_fileFramePosition = 0;
	size_t m_scrollPosition = 0;
	static const size_t MAX_COLLECTION_SIZE = 10;
};
}
