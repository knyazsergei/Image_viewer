// lazyloader.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../liblazyloader/ImageController.h"

int main()
{
	lload::CImageController control;
	std::string command;
	while (command != "quit")
	{
		std::cout << control.GetPage().GetSize() << std::endl;
		auto & images = control.GetPage();
		for (size_t i = 0; i < images.GetSize(); ++i)
		{
			auto & image = images[i];
			std::wcout << images[i].GetFileName() << std::endl;
		}
		std::cout << std::endl;


		std::cin >> command;


		if (command == "up")
		{
			control.PrevPage();
		}
		else if(command == "down")
		{
			control.NextPage();
		}
	}
    return 0;
}

