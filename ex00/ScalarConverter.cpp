#include "ScalarConverter.hpp"

// class ScalarConverter
// {
// 	public:
// 		static void convert();
// 		ScalarConverter();
// 		ScalarConverter(const ScalarConverter& other);
// 		const ScalarConverter& operator=(const ScalarConverter& other);
// 		~ScalarConverter();
// };

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}
const ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const char* str)
{
	std::cout << static_cast<char>(*str) << std::endl;
	std::cout << static_cast<int>(std::atoi(str)) << std::endl;
	std::cout << static_cast<double>(std::atof(str)) << std::endl;
	std::cout << static_cast<float>(std::atof(str)) << std::endl;
}
