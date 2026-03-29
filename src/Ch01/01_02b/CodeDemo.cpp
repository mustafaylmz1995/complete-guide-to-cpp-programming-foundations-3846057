// Complete Guide to C++ Programming Foundations
// Exercise 01_02
// Hello World, by Eduardo Corpeño 

#include <iostream>
#include <cstdio>

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::cout << std::endl << std::endl;

    printf("Hello World\n\n");

    /* 
    Parameter ve Argument 
    
    Parameter fonksiyonlar için yer tutan değişkenler 

    Argument o fonksiyonda yer tutan değişkenler artık bir sabit değer atandıysa argument oluyor

    Ornek
    int add (a, b); --> a ve b birer parametredir
    add(5, 3) --> 5 ve 3 argument olur
    */

    /* 
    Statement ve Expression

    Statement en küçük iş yapan kod birimi ve sonu ; ile bitmelidir. 
    
    Expression eğer bir statement içerisinde bir sonuç içerecek iş yapıyorsa bu expression olur

    Ornek:
    int a = 5; --> Declearation statement

    if(c > 5) --> Conditional statement with an expression

    */


    return 0;
}
