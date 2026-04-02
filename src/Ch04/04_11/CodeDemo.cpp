// Complete Guide to C++ Programming Foundations
// Challenge 04_11
// Vector Manipulation, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>

std::vector<int> SelectKeyPoints(std::vector<int> distances, int checkpointIndex){
    std::vector<int> result;

    // Write your code here
    //result.push_back(distances.front());
    result.push_back(*distances.begin());
    result.push_back(distances.at(checkpointIndex));
    result.push_back(distances.at(distances.size()-1));

    
    return result;
}

int main(){
    std::vector<int> distances = {3, 5, 4, 6, 7, 8};
    int checkpointIndex = 4;

    std::vector<int> learnerResult = SelectKeyPoints(distances, checkpointIndex);
    std::cout << "Your code returned: { ";
    auto vectPtr = learnerResult.begin();
    while (vectPtr != learnerResult.end()){
        std::cout << *vectPtr << " ";
        vectPtr = next(vectPtr, 1);
    }
    std::cout << "}" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
