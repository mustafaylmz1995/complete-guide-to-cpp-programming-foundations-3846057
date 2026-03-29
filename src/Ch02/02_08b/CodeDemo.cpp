// Complete Guide to C++ Programming Foundations
// Exercise 02_08
// Enumerations, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

enum class asset_type {texture, sound, animation, script};
enum class menu_section {background, music, sound, controls, texture};

int main(){
    asset_type asset_value;
    int sound = 5;

    asset_value = asset_type::sound;

    std::cout << "asset_value = " << (int) asset_value << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
/*
    Enum vs Enum class
    enum içerisinde tanımlı kelimelere integer değerler atar yada biz atarız.
    Genellikle global tanımlandıkları için kodda başka enum objeleri ile karışıp değerleri bozulabilir takibi ve düzenlenmesi zordur.
    Enum class(Scoped Enums, Strongly typed enums) kullanarak enum içinde tanımlı objectleri belirli scope'lar altına alıp scope resolution 
    ile ulaşabilir yaparız bu karışıklığı çözeriz.

*/