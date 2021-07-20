#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace touch
{
	auto exist(std::string const &path) -> bool
	{
		std::ifstream fin;
		fin.open(path.c_str());	
		return fin.is_open();
	}
}

auto main(int const argc, char const *argv[]) -> int
{	try {
		if (argc < 2)
		{
			std::cout << "Error: No argument given" << std::endl;
			return -1;
		}
		for (auto index = 1; index < argc; index++)
		{	
			if (touch::exist(argv[index]))
				std::cout << argv[index] << " could not be created. Maybe this file already exists?" << std::endl;
			else
			{
				std::ofstream file(argv[index]);
				if (file.is_open())
					std::cout << argv[index] << " was created" << std::endl;
				else
					std::cout << argv[index] << " could not be created. Maybe this file already exists?" << std::endl;
				file.close();
			}
		}
	}
	catch (...)
	{
		std::cout << "An exception was thrown: " << std::endl;
	}
}