// Complete Guide to C++ Programming Foundations
// Exercise 06_04
// Writing Functions, by Eduardo Corpeño 

#include <iostream>
#include <string>

std::string getPlayerName();
int calculateScore(int baseScore, int multiplier);
void displayScore(const std::string&, int);


int main(){
    std::string playerName = getPlayerName(); //"Alex";
    int score = calculateScore(75,2);

    displayScore(playerName, score);
    
    std::cout << std::endl << std::endl;
    return 0;
}


std::string getPlayerName()
{
    return "Alex";
}

int calculateScore(int baseScore, int multiplier)
{
    return baseScore * multiplier;
}

void displayScore(const std::string& name, int Score)
{
    std::cout << name << " scored " << Score << " points." << std::endl;
}
