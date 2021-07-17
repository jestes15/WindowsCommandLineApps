/*
#include <any>
#include <iostream>
#include <vector>

namespace EightBall
{
	[[nodiscard]] auto static getPhrase(std::any magicWords) -> std::string
	{
		return std::any_cast<std::vector<std::string>>(magicWords).at(rand() % 6);
	}
}

auto main() -> int
{
	srand(static_cast<unsigned int>(time(nullptr)));
	std::vector<std::string> const static magicWords = {
		"No",
		"Yes",
		"Perhaps",
		"Most definitely yes",
		"Almost positively not",
		"I think so..."
	};

	std::cout << EightBall::getPhrase(magicWords) << std::endl;

	return 0;
}
*/