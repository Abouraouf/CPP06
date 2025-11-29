#pragma once
#include <iostream>
#include <typeinfo>
#include <stdint.h> 

struct Data
{
	Data(){};
	int n;
	std::string name;
};

class Serializer{
	private:
		Serializer();
		Serializer(const Serializer& other);
		const Serializer& operator=(const Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
