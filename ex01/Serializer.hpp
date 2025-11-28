#pragma once
#include <iostream>
#include <typeinfo>
#include <stdint.h> 
struct Data
{
	int n;
};


class Serializer{
	public:
		Serializer();
		Serializer(const Serializer& other);
		const Serializer& operator=(const Serializer& other);
		~Serializer();
		
		
		static uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};