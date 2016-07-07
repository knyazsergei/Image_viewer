#pragma once
#include <list>
#include <map>
#include <iterator>
#include "ImageCollection.h"
#include "GdiPlus.h"

namespace lload
{
	class CImageLoader
	{
		enum class Diraction
		{
			left,
			right
		};
	public:
		CImageLoader(std::wstring const& path);
		~CImageLoader();
		
		void SetImagePageSize(size_t size);
		size_t GetImagePageSize() const; // return 30;

		void NextPage();
		void PrevPage();
	private:
		void Load(Diraction dir);
		void Load(size_t startIndex);
		void ReadFileList(std::wstring path);
	private:
		std::list<CImageCollection> m_collections;
		std::list<CImageCollection>::iterator m_currentCollection;
		size_t m_currentCollectionIndex = 0;

		CGdiPlus m_initGdiPlus;

		size_t m_imagePageSize = 5;
		size_t m_lastIndex = 0;

		std::vector<std::wstring> m_files;

		const static size_t MAXIMUM_COLLECTIONS_NUMBER = 6;
	};
}
