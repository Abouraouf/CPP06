#pragma once
#include <iostream>
#include <typeinfo>
#include <cstdlib>

class ScalarConverter
{
	public:
		static void convert(const char* str);
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		const ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};
