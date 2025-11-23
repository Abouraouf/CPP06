#include "ScalarConverter.hpp"

//checking the type -> check first if it is special, check if it is char, check if it is int, double, float

// converting

int checker(const std::string& str)
{
	long numb;
	if (str.c_str() == "nanf" || str.c_str() == "-inff" || str.c_str() == "+inff"
		|| str.c_str() == "-inf" || str.c_str() == "+inf")
		return (SPEC);
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	if (isdigit(str[0]))

}