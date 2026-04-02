// Complete Guide to C++ Programming Foundations
// Exercise 04_07
// Using Objects with Vectors, by Eduardo Corpeño 

#include <vector>
#include <iostream>
#include <complex>

int main(){

    std::vector<std::complex<double>> viktor;

    viktor.push_back(std::complex<double>(3.5, 4.7));
    viktor.push_back(std::complex<double>(1.0, -2.2));
    viktor.push_back(std::complex<double>(-5.3, 6.4));
    viktor.push_back(std::complex<double>(-7.1, -1.6));

    std::cout << "The first real part : "<< viktor.begin()->real() << std::endl;
    std::cout << "The imaginary part of index 1 : "<< viktor.at(1).imag() << std::endl;
    std::cout << "Next to last real : "<< prev(viktor.end(), 2)->real() << std::endl;
    std::cout << "Last Imaginary : "<< (viktor.end()-1)->imag() << std::endl;

    
    std::cout << std::endl << std::endl;
    return 0;
}
/*
Complex Sayılar
Karmaşık sayılar, gerçek (real) ve sanal (imaginary) kısımlardan oluşur 
ve STL'nin complex sınıfı ile temsil edilir. 

Kompleks sayılar ile Vektor kullanımı
Vektorler herhangi bir obje tipi tutabilir buna complex sayılar da dahildir.
std::vector<std::complex<double>> points;
push_back fonksiyonu ile elemanlar eklenir.

Vektör elemanına erişim
begin() ilk elemana, 
end() ise son elemandan sonraki konuma işaret eder; 
son elemana ulaşmak için end()-1 veya prev() fonksiyonu kullanılır. 
Ayrıca, indeksleme ile doğrudan erişim mümkündür. 
Bu yöntemler, vektör içindeki karmaşık sayıların gerçek ve sanal kısımlarına farklı şekillerde erişim sağlar.

Not
Iteratorler pointer gibi davrandığı için üyelere erişim -> ile sağlanır.


C++ Referanslar (References) Özeti

1. Referans Nedir?

Referanslar, mevcut bir değişkenin takma adlarıdır (alias).
Bir referans, değişkenle aynı şekilde kullanılır, pointer gibi dereference edilmesi gerekmez.

2. Referans ve Pointer Arasındaki Farklar

Referanslar pointer değildir ve adresleri yoktur.
Referanslar mutlaka tanımlanırken başlatılmalıdır, pointerlar ise isteğe bağlıdır.
Referanslar bir kez bağlandıkları değişkenden başka bir değişkene yönlendirilemez, pointerlar ise farklı değişkenleri işaret edebilir.
Pointerlar çok seviyeli gösterim (indirection) yapabilir, referanslar sadece tek seviyelidir.
Referanslar değişken gibi değil, sadece başka bir değişkenin takma adıdır.

3. Referansların Kullanım Alanları

Fonksiyon parametreleri referans olarak geçilerek, fonksiyon içinde orijinal değişken üzerinde değişiklik yapılabilir.
Büyük veri yapılarının kopyalanmasını önleyerek performans artışı sağlar.
For döngülerinde veri kopyalamadan elemanlara erişim sağlar.

*/