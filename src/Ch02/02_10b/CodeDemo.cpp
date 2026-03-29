// Complete Guide to C++ Programming Foundations
// Exercise 02_10
// Type Casting, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

int main(){

    float type1;
    int32_t type2;
    uint32_t type3;

    type1 = -153.44;
    type2 = type1; // implicit type casting 
    type3 = type2;

    std::cout << "type1 is " << type1 << std::endl;
    std::cout << "type2 is " << type2 << std::endl;
    std::cout << "type3 is " << static_cast<int32_t>(type3) << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
