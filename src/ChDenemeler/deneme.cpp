#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>

int main() {
    int a = 3;
    int b = 999;
    int* p_a = &a;
    int& r_a = a;
    int& r_p_a = *p_a;


    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    a = 5;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;
    
    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    p_a = &b;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    b = 1010;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    a = 555;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    r_a = 25;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    r_p_a = 33;

    std::cout << " a        : " << a << std::endl;
    std::cout << " *p_a     : " << *p_a << std::endl;
    std::cout << " r_a      : " << r_a << std::endl;
    std::cout << " r_p_a    : " << r_p_a << std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    std::cout <<  std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout <<  std::endl;

    return 0;
}

