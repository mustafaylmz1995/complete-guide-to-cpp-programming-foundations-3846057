// Complete Guide to C++ Programming Foundations
// Exercise 05_01
// If Statements, by Eduardo Corpeño 

#include <iostream>

int main(){
    int score = 1023;
    bool gamePaused = false;
    char action = 'x';
    
    std::cout << std::endl << std::endl;
    return 0;
}

/*

ITERATOR 
C'deki pointer (gösterici) mantığının C++'taki nesne yönelimli ve 
daha güvenli halidir. Diziler, vektörler ve listeler gibi veri yapılarının 
elemanları üzerinde gezinmemizi sağlar.
v.begin(): Vektörün İLK elemanını gösteren iterator'ı döndürür.
v.end(): DİKKAT! Vektörün son elemanını DEĞİL, son elemandan bir sonraki 
(boş) bellek bölgesini gösterir. Döngü bitiş şartı olarak kullanılır.
Kullanımı: Pointerlar gibi '*' operatörü ile (dereference) gösterdiği 
değere ulaşırız.

Örnek Kod:
std::vector<int> v = {10, 20, 30};
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " "; // Çıktı: 10 20 30
}


2. 'auto' 
Derleyicinin (compiler) atanan değere bakarak değişkenin veri tipini 
otomatik olarak tahmin etmesidir. (Çalışma zamanında değil, derleme zamanında
çalışır, yani performans kaybı yaratmaz).
C'den Farkı: C'deki 'auto' (lokal değişken bildirimi) ile alakası yoktur.
Özellikle 'std::vector<int>::iterator' gibi upuzun tip isimlerini yazmaktan kurtarır.

Örnek Kod:
// std::vector<int>::iterator it ...
// Uzun yazım yerine:
auto it = v.begin(); 
// Derleyici 'it'nin bir vector<int>::iterator olduğunu anlar.


3. std::next ve std::prev 
<iterator> başlık dosyasında bulunur.
Bir iterator'ı orijinalini değiştirmeden ileri (next) veya geri 
(prev) götürüp o konumu döndüren fonksiyonlardır.
C'deki pointer aritmetiğine (ptr + 1) benzer. Ancak C++'ta 
her veri yapısı '+' operatörünü desteklemez (örneğin std::list). std::next 
ve std::prev tüm standart veri yapılarıyla güvenle çalışır.
  
Örnek Kod:
auto it = v.begin();             // it 10'u gösteriyor
auto ileri = std::next(it, 2);   // it hala 10'u gösterir, 'ileri' 30'u gösterir
auto geri = std::prev(ileri, 1); // 'geri' 20'yi gösterir


4. Range-based for loop 
Vektörün içindeki tüm elemanları baştan sona dönmek için iterator 
yazmaya bile gerek bırakmaz.

Örnek Kod:
std::vector<int> sayilar = {1, 2, 3};
for (int sayi : sayilar) {
    std::cout << sayi; // Sırayla 1, 2, 3 yazdırır.
}
    
// Eğer elemanları döngüde değiştirmek istersen referans (&) kullan:
// for (int &sayi : sayilar) { sayi *= 2; }

*/
