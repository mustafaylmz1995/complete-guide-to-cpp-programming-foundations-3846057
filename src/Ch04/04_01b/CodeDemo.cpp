// Complete Guide to C++ Programming Foundations
// Exercise 04_01
// Arrays, by Eduardo Corpeño 

#include <iostream>

int main(){

    const size_t NUMBER_OF_ENEMIES = 4;

    int enemies[NUMBER_OF_ENEMIES];
    float healthofEnemies[] = {77.0, 16.5, 21.8, 67.3};

    enemies[0] = 25;
    enemies[1] = 10;
    enemies[2] = 15;
    enemies[3] = 20;

    std::cout << "The level of enemies_0 is " << enemies[0] << std::endl;
    std::cout << "The level of enemies_1 is " << enemies[1] << std::endl;
    std::cout << "The level of enemies_2 is " << enemies[2] << std::endl;
    std::cout << "The level of enemies_3 is " << enemies[3] << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "The health of enemies_0 is " << healthofEnemies[0] << std::endl;
    std::cout << "The health of enemies_1 is " << healthofEnemies[1] << std::endl;
    std::cout << "The health of enemies_2 is " << healthofEnemies[2] << std::endl;
    std::cout << "The health of enemies_3 is " << healthofEnemies[3] << std::endl;


    std::cout << std::endl << std::endl;
    return 0;
}
