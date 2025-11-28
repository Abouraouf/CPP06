#pragma once
#include <iostream>
#include <typeinfo>
#include <cstdlib>


class ScalarConverter
{
	public:
		// static void convert(const char* str);
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		const ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

int checking_int(const std::string& str);
int check_float(const std::string& str);
int checker(const std::string& str);
void converter(const std::string& str, int type);
void impossible();

enum type
{
	ERROR = -1,
	SPEC,
	CHAR,
	INT,
	DOUBLE, 
	FLAOT
};
