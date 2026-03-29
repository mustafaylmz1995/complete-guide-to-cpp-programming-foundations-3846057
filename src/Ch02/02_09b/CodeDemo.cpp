// Complete Guide to C++ Programming Foundations
// Exercise 02_09
// Structures, by Eduardo Corpeño 

#include <iostream>
#include <string>

enum class character_role {protagonist, antagonist, sidekick, npc};

struct game_character{
    std::string name;
    int level;
    character_role role;
};

int main(){
    
    game_character character;
    character.name = "Tony";
    character.level = 10;
    character.role = character_role::sidekick;

    std::cout << character.name << " has " << character.level << " level and its role is " << (int)character.role << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
