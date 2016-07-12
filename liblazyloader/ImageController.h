#pragma once
#include <vector>
#include <iterator>
#include "ImageCollection.h"
#include "GdiPlus.h"

namespace lload
{
class CImageController
{
public:
	CImageController(std::vector<std::wstring> && files );
	~CImageController() = default;

	bool NeedUpdate();
	
	void UpdateScrollPosition(size_t position);

	CImageCollection & GetPage();
private:
	CGdiPlus m_gdiplus;
	
	lload::CImageCollection m_currentCollection;
	
	std::vector<std::wstring> m_files;
	bool m_needUpdate = false;
	size_t m_fileFramePosition = 0;
	size_t m_scrollPosition = 0;
};
}
