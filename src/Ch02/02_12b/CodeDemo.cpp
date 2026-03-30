// Complete Guide to C++ Programming Foundations
// Exercise 02_12
// Type Inference with auto, by Eduardo Corpeño 

#include <iostream>
#include <typeinfo>

int main(){
    auto score = 8;
    auto points = 123456789123456789;
    auto height = 6.2f;
    auto duration = 90.0;
    auto is_active = true;
    auto initial = 'P';
    auto title = "Soccer Champions";

    std::cout << "The type of score is " << typeid(score).name() << std::endl;
    std::cout << "The type of points is " << typeid(points).name() << std::endl;
    std::cout << "The type of height is " << typeid(height).name() << std::endl;
    std::cout << "The type of duration is " << typeid(duration).name() << std::endl;
    std::cout << "The type of is_active is " << typeid(is_active).name() << std::endl;
    std::cout << "The type of initial is " << typeid(initial).name() << std::endl;
    std::cout << "The type of title is " << typeid(title).name() << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}

/*      
    Type Inference
    CPP11 den sonra type inference denilen bir özellik geldi. 
    Değişkeni istediğimiz uygun tipe dönüştüren bir özellik.
    typeid fonksiyonu typeinfo header'ında bulunur ve verilen 
    değişkenin tipini döndürür.
    auto keyword'u ile tanımlanan değişkenler başlatılmalıdır.

    i --> int
    l --> long
    f --> float
    d --> double
    b --> bool
    c --> char
    PKc --> Pointer Const Char (String)

*/