// Complete Guide to C++ Programming Foundations
// Exercise 04_06
// The Vector Class, by Eduardo Corpeño 


#include <iostream>
#include <string>
#include <vector>


int main(){
    std::vector<std::string> checkpoints = { "Start", "Forest", "Castle"};

    checkpoints.push_back("Cave");
    checkpoints.push_back("Finish");

    std::cout << "The game has " << checkpoints.size() << " checkpoints." << std::endl;
    std::cout << "The checkpoint at index 2 is " << checkpoints[2] << std::endl;
    checkpoints[2] = "Dark Castle";
    std::cout << "The checkpoint updated to " << checkpoints[2] << std::endl;


    
    std::cout << std::endl << std::endl;
    return 0;
}


/*
 Vectorler:
Vector:
Dinamik boyutlu, otomatik bellek yöneten bir konteynerdir. 
Yani, boyutunu çalışma zamanında değiştirebilirsin ve 
belleği elle yönetmene gerek kalmaz.

Bellek yönetimi: 
Vector, elemanları ardışık hafızada tutar. Bu sayede erişim hızlıdır 
ve array gibi indeksleme yapılabilir.

Eleman ekleme: 
Elemanlar sadece vector'un arka ucuna push_back metodu ile eklenir. 
Çünkü baştan eklemek, ardışık hafıza düzenini bozacağı için pahalıdır.

Eleman güncelleme: İndeks kullanarak elemanlara erişebilir ve 
değerlerini değiştirebilirsin (örneğin, vector[index] = yeni_deger).

Generic yapı: Vector, hangi türde olursa olsun (int, string, kendi sınıfların) 
eleman tutabilir; bu, template yapısı sayesinde mümkün.

STL'nin parçası: 
Vector, C++ Standard Template Library'nin bir parçasıdır. 
STL, generic programlama için konteynerler, fonksiyonlar ve algoritmalar içerir.

*/