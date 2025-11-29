#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data* original = new Data;
    original->n = 2;
    original->name = "mahdi";
    std::cout << "Original address: " << original << std::endl;

    uintptr_t raw = Serializer::serialize(original);
    Data* back = Serializer::deserialize(raw);
 
    std::cout << "Deserialized address: " << back << std::endl;
    std::cout << "Same pointer: " << (original == back) << std::endl;
    std::cout << "n: " << back->n << std::endl;
    std::cout << "name: " << back->name << std::endl;

    delete original;
    return 0;
}