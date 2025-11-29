#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <iostream>

Base * generate(void)
{
	srand(time(0));
	int randomNum = rand() % 3;
	if (randomNum == 0)
		return (new A);
	else if (randomNum == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	std::cout << typeid(*p).name() << std::endl;
}

int main()
{
	Base* mahdi = new A;

	identify(mahdi);
}