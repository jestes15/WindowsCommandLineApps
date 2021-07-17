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

	auto permissions(fs::perms const perms) -> std::vector<std::string>
	{
		std::vector<std::string> permissions;
		permissions.emplace_back((perms & fs::perms::owner_read) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::owner_write) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::owner_exec) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::group_read) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::group_write) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::group_exec) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::others_read) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::others_write) != fs::perms::none ? "r" : "-");
		permissions.emplace_back((perms & fs::perms::others_exec) != fs::perms::none ? "r" : "-");
		return permissions;
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
			for (auto const &x : touch::permissions(fs::status(".").permissions()))
				std::cout << x << std::endl;
			
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