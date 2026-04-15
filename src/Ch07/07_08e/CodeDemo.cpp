// Complete Guide to C++ Programming Foundations
// Exercise 07_08
// Operator Overload, by Eduardo Corpeño 

#include "inventory.h"
#include <iostream>

int main(){
    // Create an inventory with capacity of 5 items
    Inventory myInventory(5);

    // Add 5 items
    myInventory += "Health Potion";
    myInventory += "Mana Potion";
    myInventory += "Sword";
    myInventory += "Shield";
    myInventory += "Bow";

    // Display current inventory
    myInventory.displayInventory(); 

    // Try to add another item when inventory is full
    myInventory += "Arrow";

    // Remove an item
    myInventory -= "Mana Potion";  

    // Display the item count
    std::cout << "The inventory now contains: " << myInventory.getItemCount() << " items." << std::endl; 

    // Access item by index
    std::cout << "Item at index 2: " << myInventory[2] << std::endl; 

    // Display final state of inventory
    myInventory.displayInventory();

    std::cout << std::endl << std::endl;
    return 0;
}

/*

Bu kısımda C++ dilinde operatör aşırı yüklemeden bahsediyoruz.
Operatör aşırı yükleme, bir sınıfın fonksiyonlarını operatörler gibi kullanmamızı sağlar.
Örneğin, Inventory sınıfımızdaki addItem, removeItem ve getItem fonksiyonlarını sırasıyla +=, ve [] operatörlerine dönüştüreceğiz.
Önemli noktalar:
1. Operatörler unary (tek operandlı), binary (iki operandlı) veya ternary (üç operandlı) bilir.
Buradaki işlemler binary çünkü hem sınıf nesnesi hem de bir argüman kullanılıyor.
2. Operatörler mutlaka bir değer döndürmelidir, void olamazlar.
Bu yüzden += ve -= operatörleri Inventory sınıfının referansını döndürüyor, böylece zincirleme atamalar yapılabilir.
Header dosyasında (inventory.h):
- addItem fonksiyonu yerine "Inventory& operator+=(const ItemType& item);" şeklinde prototip yazılır.
- removeItem fonksiyonu için "Inventory& operator-=(const ItemType& item);" kullanılır.
- getItem fonksiyonu için "std::string operator[](int index) const;" şeklinde dizin operatörü aşırı yüklenir.
Implementation dosyasında (inventory.cpp):
- Fonksiyon isimleri operator+=, operator-= ve operator[] olarak değiştirilir.
- += ve -= operatörlerinde fonksiyon sonunda "return *this;" ifadesi eklenir, böylece nesnenin kendisi döndürülür.
- [] operatörü zaten string döndürdüğü için sadece isim değiştirilir.
Main dosyasında (CodeDemo.cpp):
- addItem çağrıları yerine nesne += item şeklinde kullanılır.
- removeItem çağrıları nesne -= item olarak değiştirilir.
- getItem çağrıları ise nesne[index] şeklinde dizin operatörü ile yapılır.

Bu sayede kod daha okunabilir ve doğal operatör kullanımı gibi olur.
Operatör aşırı yükleme, C++'da nesnelerle daha sezgisel ve etkili çalışmayı sağlar.
Özetle:
- Operatör aşırı yükleme fonksiyonların yerine geçer ve özel anlamlar kazandırır.
- Döndürülen değer genellikle referans olur, böylece zincirleme işlemler yapılabilir.
- Header ve implementation dosyalarında uygun şekilde prototip ve tanımlar yapılmalıdır.
- Main kodda fonksiyon çağrıları yerine operatörler kullanılır.
Bu yöntem, özellikle gömülü sistemlerde ve karmaşık sınıflarda kodun okunabilirliğini ve bakımını artırır.


C++'da Kalıtım (Inheritance) ve Çok Biçimlilik (Polymorphism) Notları
1. Kalıtım Nedir?
- Bir sınıf (Derived Class) başka bir sınıfın (Base Class) özelliklerini ve fonksiyonlarını miras alır.
- Böylece kod tekrarı azalır, ortak özellikler Base Class'ta toplanır.
- Örnek: Item sınıfı temel sınıf, Weapon, Ammo, Aid, Valuable gibi sınıflar ondan türetilir.
2. Item Sınıfı (Base Class)
- name ve weight gibi ortak özellikler protected olarak tanımlanır, böylece türetilen sınıflar erişebilir.
- use() ve display() fonksiyonları virtual olarak tanımlanır, bu sayede türetilen sınıflar kendi versiyonlarını yazabilir.
- virtual fonksiyonlar, çalışma zamanında hangi fonksiyonun çağrılacağını belirler (polimorfizm).
3. Çok Biçimlilik (Polymorphism)
- Base Class pointer'ı ile Derived Class nesneleri işlenebilir.
- virtual fonksiyonlar override edilerek farklı davranışlar sağlanır.
- Örneğin, Weapon sınıfı use() fonksiyonunu "Silah sallanıyor" şeklinde, Ammo sınıfı "Mermi dolduruluyor" şeklinde override eder.
4. Türetilmiş Sınıflar (Derived Classes)
- Weapon, Ammo, Aid, Valuable sınıfları Item'dan public kalıtım ile türetilir.
- Her biri kendine özgü özellikler (damage, rounds, healingPoints, value) ve use() fonksiyonunu override eder.
5. Abstract (Soyut) Sınıflar ve Saf Sanal Fonksiyonlar
- Base Class'taki virtual fonksiyon saf sanal (pure virtual) yapılabilir: virtual void use() const = 0;
- Bu durumda Item soyut sınıf olur, doğrudan nesne oluşturulamaz.
- Türeyen sınıflar bu fonksiyonu mutlaka override etmek zorundadır.
6. Örnek Kullanım
- Item* tipinde bir vector oluşturulur ve içine Weapon, Ammo, Aid, Valuable nesneleri eklenir.
- Döngü ile tüm nesnelerin display() ve use() fonksiyonları çağrılır.
- Çalışma zamanında doğru fonksiyon çağrılır, böylece esnek ve genişletilebilir kod yazılır.

7. En İyi Uygulamalar (Best Practices)
- Kalıtım "is-a" ilişkisi olduğunda kullanılmalı. Örneğin, "Weapon bir Item'dir" doğru bir kalıtım ilişkisidir.
- Base sınıflar, doğrudan nesne oluşturulmaması gereken durumlarda soyut (abstract) sınıf olarak tasarlanmalı.
- Polimorfizm, esnek ve genişletilebilir kod yazmak için kullanılmalı; base sınıf pointer'ları ile farklı derived sınıf nesneleri yönetilmeli.
- Override edilen fonksiyonlarda "override" anahtar kelimesi kullanılmalı, böylece derleyici hata kontrolü yapar.
- Bellek yönetimine dikkat edilmeli; dinamik olarak oluşturulan nesneler uygun şekilde silinmeli (delete edilmeli).

8. Özet
- Kalıtım, ortak özellikleri ve davranışları base sınıfta toplayarak kod tekrarını azaltır.
- Polimorfizm, aynı arayüzü kullanarak farklı nesne türlerinin farklı davranışlar sergilemesini sağlar.
- C++'da virtual fonksiyonlar ve override mekanizması polimorfizmi mümkün kılar.
- Soyut sınıflar (abstract classes) ve saf sanal fonksiyonlar (pure virtual functions) ile arayüzler tanımlanabilir.
- Bu kavramlar, özellikle karmaşık ve genişletilebilir gömülü sistem yazılımlarında kodun bakımını ve genişletilmesini kolaylaştırır.

9. Örnek Kod Parçası (Kısaca)
class Item {
protected:
std::string name;
int weight;
public:
Item(const std::string& n, int w) : name(n), weight(w) {}
virtual ~Item() {}
virtual void use() const = 0; // saf sanal fonksiyon
virtual void display() const {
std::cout << "Item: " << name << ", Weight: " << weight << std::endl;
}
};
class Weapon : public Item {
private:
int damage;
public:
Weapon(const std::string& n, int w, int d) : Item(n, w), damage(d) {}
void use() const override {
std::cout << "Silah sallanıyor: " << name << ", Hasar: " << damage << std::endl;
}
void display() const override {
std::cout << "Weapon: " << name << ", Weight: " << weight << ", Damage: " << damage << std::endl;
}
};

*/