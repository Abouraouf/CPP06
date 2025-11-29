#include "ScalarConverter.hpp"
#include <iomanip>
void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void print(char c)
{
	if (isprint(c))
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl; // why the ()
	std::cout << "float: "  << std::fixed << std::setprecision(2) << static_cast<float>(c)<<"f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::fixed << std::setprecision(2) << std::endl;
}

void print_else(double i)
{
	char c = static_cast<char>(i); // protect the overflow
	if (isprint(c) && i < 128)
		std::cout << "char: " << "\'" << c << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl; // why the ()
	std::cout << "float: " << std::fixed << std::setprecision(2)<< i << "f"<< std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2)<< i << std::endl;
}

void	Special(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void converter(const std::string& str, int type)
{
	if (type == ERROR)
		return (impossible());
	else if (type == SPEC)
		return(Special(str));
	else if (type == CHAR || type == INT || type == FLAOT || type == DOUBLE)
	{ //add soome protection
		if (type == CHAR)
		{
			char c = static_cast<char>(str[0]);
			print(c);
		}
		else{
			char *end;
			double value = std::strtod(str.c_str(), &end);	
			print_else(value);
		}
	}
}
