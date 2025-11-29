#include "ScalarConverter.hpp"

//checking the type -> check first if it is special, check if it is char, check if it is int, double, float

// converting

int checking_int(const std::string& str)
{
	long i = 0;
	bool flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && i < 11) || (str[i] && i < 12 && flag))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	if (!str[i])
		return 1;
	return 0;
}

int check_float(const std::string& str)
{
	long i = 0;
	bool flag = false;
	int	dot;
	if (str.find('.') != std::string::npos)
		dot = str.find('.');
	else
	{
		return -1;
	}
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}

	for (int j = (dot - 1); j >= 0; j--)
	{
		if (flag == 1 && j == 0){}
		else if (!isdigit(str[j]))
			return (0);
		j--;
	}
	i = dot + 1;
	if (!str[dot + 1])
		return (0);

	while (str[i])
    {
        if ((str[i] == 'f' || str[i] == 'F') && str[i + 1] == '\0')
            return 1;
		else if ((str[i] == 'f' || str[i] == 'F') && str[i + 1] != '\0')
			return 0;
		else if (!isdigit(str[i]))
            return (0);
		i++;
	}
	if (str[i - 1] == 'f' || str[i - 1] == 'F')
    	return 1;
	return 0;
}

int check_double(const std::string& str)
{
	long i = 0;
	bool flag = false;
	int	dot;
	if (str.find('.') != std::string::npos)
		dot = str.find('.');
	if (str[0] == '-' || str[0] == '+') 
	{
		i++;
		flag = 1;
	}
	for (int j = (dot - 1); j >= 0; j--)
	{
		if (flag == 1 && j == 0){}
		else if (!isdigit(str[j]))
			return (0);
		j--;
	}
	i = dot + 1;
	if (!str[dot + 1])
		return 0;
    while (str[i])
    {
        if(!isdigit(str[i]))
		{
        	return 0;
		}
		i++;
    }
    return 1;
}

int checker(const std::string& str) // there is a segfault when number is too big
{
	if (str.length() == 0)
		return ERROR;
	if (str == "nan" || str == "nanf" || str == "-inff" || str == "+inff"
		|| str == "-inf" || str == "+inf")
		return (SPEC);
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	if (str.length() == 1 && isdigit(str[0]))
		return (INT);
	if (str.length() != 1 && (isdigit(str[0])
		|| (((str[0] == '-' || str[0] == '+')) && isdigit(str[1]))))
		{
			if(checking_int(str))
				return (INT);
		}
	if (str.length() != 1 && (isdigit(str[0])
		|| (((str[0] == '-' || str[0] == '+')) && isdigit(str[1]))))
		{
			int a = check_float(str);
			if (a && a != -1)
				return (FLAOT);
			if (a != -1 && check_double(str))
				return (DOUBLE);
		}
	return (ERROR);
}
