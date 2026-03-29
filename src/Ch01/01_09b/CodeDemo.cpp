// Complete Guide to C++ Programming Foundations
// Challenge 01_09
// Terminal Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::string userName;

    std::cout << "Please Write Your Name!" << std::endl;
    std::cin >> userName;
    std::cout << std::endl << std::endl;
    
    std::cout << "The User name is : " << userName << std::endl;
    std::cout << std::endl << std::endl;


    return 0;
}