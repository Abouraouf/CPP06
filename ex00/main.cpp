#include "ScalarConverter.hpp"
#include <iostream>

int main (int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "Wrong argument count" << std::endl;
		return 1;
	}
	converter(av[1], checker(av[1]));
}
