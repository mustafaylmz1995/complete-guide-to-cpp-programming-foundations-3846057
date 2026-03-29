// Complete Guide to C++ Programming Foundations
// Exercise 02_05
// Using Variables, by Eduardo Corpeño 

#include <iostream>

int a, b = 5;


int main(){
    
    bool my_flag;

    a = 7;
    my_flag = false;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "my_flag = " << my_flag << std::endl;
    std::cout << std::endl << std::endl;

    my_flag = true;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "b - a = " << b - a << std::endl;
    std::cout << "my_flag = " << my_flag << std::endl;
    std::cout << std::endl << std::endl;

    unsigned int positive;
    positive = b - a;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "b - a (positive) = " << positive << std::endl;
    std::cout << "my_flag = " << my_flag << std::endl;
    std::cout << std::endl << std::endl;


    int octal_b = 015; // 8^1 * 1 + 8^0 *5 = 8 + 5 = 13 
    int octal_a = 017; // 8^1 * 1 + 8^0 *7 = 8 + 7 = 15
    int bin_a = 0b011; 
    int bin_b = 0b01010;

    std::cout << "octal_b = " << octal_b << std::endl;
    std::cout << "octal_a = " << octal_a << std::endl;
    std::cout << "bin_a = " << bin_a << std::endl;
    std::cout << "bin_b = " << bin_b << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}


/* 
    Qualifiers

   const:
   İlk atamadan sonra programda değişmeyecek sabit değerler için kullanırız. (kilitli bir kasa gibi)
 
   Örnek
   Bir 3D data modelimiz var ve bunu bir fonksiyona göndereceğiz ama fonksiyon içerisinde değiştirilip bozulmasında korkuyoruz o zaman fonksiyon parametresine const yazarak gönderirir böylece fonksiyonun onu bozmayacağından emin oluruz. (Read-Only)

   void generate3DShape(const std::string& ThreeDimensionShape);


   mutable:
   const olarak tanımlanmış olan bir object member'ının mantıksal yapısını bozmadan değiştirmek istediğimizde kullanırız.

   inline: 
   Normalde fonksiyon çağırılmak yerine fonksiyonun kod kopyasının o noktaya yapıştırılmasını böylece function call overhead'inden kurtulmaya yarayan qualifier.

   Ornek:
   set-vet methodlarında çok basit bir kaç satırlık işlemler yapılır bu durumda sürekli olarak function call yaparak sistemde overhead oluşturmak yerine başlarına inline yazılabilir.

   constexpr: 
   kullanıldığı fonksiyon veya değişken için derleme esnasında değerin başlatılıp sabitlenmesini sağlar. Eğer bir değişkenin veya fonksiyonun değerini, programı çalıştırmadan (derleme tuşuna bastığım an) kesin olarak biliyorsam constexpr kullanmalıyım.

   static: 
   Local bir değere uygulandığında program ömrü boyunca yaşamasını sağlar ve her kullanım var olan tek değeri etkiler.
   Static olan bir fonksiyon sadece o dosya içerisinde kullanılır diğer dosyalardan erişilemez.

   Sınıf üyesi olarak tanımlanan bir değişken static ise object üzerinde değil sınıf üzerinden scope resolution kullanılarak değer değiştirilebilir erişilebilir.

   Ornek: 
   class Veritabani {
    public:
        static int baglantiSayisiniAl() {
            static int sayac = 0; // Hem yerel, hem static!
            sayac++;
            return sayac;
        }
    }
    Bu metodu çağırmak için herhangi bir nesne üretmene gerek yoktur (Veritabani::baglantiSayisiniAl() şeklinde çağırırsın). İçindeki sayac değişkeni ise program ilk çalıştığında bellekte yaratılır ve program kapanana kadar yaşar.

    Bu kombinasyon,  Singleton (Tekil Nesne) tasarım deseninin temelini oluşturur. Ortak bir aksiyonun (sınıf metodu), kendi içinde ortak ve kalıcı bir hafıza (yerel static) tutmasını sağlar.

    Ornek:
    static void gizliCarpismaHesapla() {
        static int toplamCarpisma = 0;
        toplamCarpisma++;
    }

    projedeki diğer dosyalar (grafik.cpp vb.) gizliCarpismaHesapla fonksiyonunu asla göremez ve çağıramaz (Güvenlik). Bu fonksiyon, kendi içinde her çağrıldığında toplamCarpisma değerini unutmadan saymaya devam eder (Kalıcı Hafıza).

    Ornek: 
    static member'ı, sadece o dosyaya özel (gizli) yapabilir miyiz?
    Bir sınıfa static x; yazdığında, derleyici bunu sadece "tüm nesneler paylaşır" olarak algılar. Bu değişkeni "dosyaya özel" yapmaz. Eğer public ise, başka bir dosyadan OyunSinifi::x diyerek o ortak değişkene herkes ulaşabilir. C++'ta bir sınıfı veya sınıfın statik üyesini tamamen bir dosyaya hapsetmek (internal linkage) istiyorsak, static kelimesini kullanmayız; bunun yerine o sınıfı İsimsiz Kapsam (Anonymous Namespace) dediğimiz bir bloğun içine yazarız: 
    namespace {
    class SadeceBuDosyayaOzel {
        static int ortakDegisken; 
    };
}
*/
