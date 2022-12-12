#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void print(const std::variant<int, std::string, std::vector<int>>& val)
{
	if (auto vInt = std::get_if<int>(&val))
	{
		std::cout << (*vInt * 2) << std::endl;
	}
	else if (auto pStr = std::get_if<std::string>(&val))
	{
		std::cout << (*pStr) << std::endl;
	}
	else if (auto pVec = std::get_if<std::vector<int>>(&val))
	{
		auto vec = *pVec;
		std::for_each(vec.begin(), vec.end(), [](auto x) { std::cout << x << " "; });
		std::cout << std::endl;
	}

}

int main()
{
	print(get_variant());

    return 0;
}
