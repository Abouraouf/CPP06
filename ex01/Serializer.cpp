#include "Serializer.hpp"

// Serializer();
// 		Serializer(const Serializer& other);
// 		const Serializer& operator=(const Serializer& other);
// 		~Serializer();

		
// 		static uintptr_t serialize(Data* ptr);
// 		Data* deserialize(uintptr_t raw);
Serializer::Serializer()
{}

const Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize()
{
	
}