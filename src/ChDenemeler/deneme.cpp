#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>

int main() {
    std::vector<int> viktor;
    int sizeOfTheVector;
    
    std::cin >> sizeOfTheVector;
    for(int i=0; i<sizeOfTheVector; i++)
    {
        int addThis = 0;
        std::cin >> addThis;
        viktor.push_back(addThis);
    }
    
    std::sort(viktor.begin(), viktor.end());
    
    for(size_t i=0; i<viktor.size(); i++)
    {
        std::cout << viktor.at(i) << " ";
    }

    std::cout << std::endl;
        
    return 0;
}

