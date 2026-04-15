// Complete Guide to C++ Programming Foundations
// Exercise 07_07
// Using Several Source Files, by Eduardo Corpeño 

#include "inventory.h"
#include <iostream>

int main(){
    // Create an inventory with capacity of 5 items
    Inventory myInventory(5); 
    
    // Add 5 items
    myInventory.addItem("Health Potion"); 
    myInventory.addItem("Mana Potion");
    myInventory.addItem("Sword");
    myInventory.addItem("Shield");
    myInventory.addItem("Bow");

    // Display current inventory
    myInventory.displayInventory(); 

    // Try to add another item when inventory is full
    myInventory.addItem("Arrow");

    // Remove an item
    myInventory.removeItem("Mana Potion");

    // Display the item count
    std::cout << "The inventory now contains: " << myInventory.getItemCount() << " items." << std::endl;

    // Access item by index
    std::cout << "Item at index 2: " << myInventory.getItem(2) << std::endl; 

    // Display final state of inventory
    myInventory.displayInventory();

    std::cout << std::endl << std::endl;
    return 0;
}

/*
C++ Sınıfını Header (.h) ve Implementation (.cpp) Dosyalarına Ayırma Notları ve Örnekleri


C++ projelerinde genellikle sınıflar iki dosyaya ayrılır:

Header dosyası (.h veya .hpp): Sınıf tanımı ve fonksiyon bildirimleri burada olur.
Implementation dosyası (.cpp): Fonksiyonların gerçek kodları burada yazılır.

Bu ayrım, kodun daha düzenli, okunabilir ve yönetilebilir olmasını sağlar.

Header dosyasının başında "#pragma once" veya "include guard" kullanılır:

#pragma once: Dosyanın sadece bir kez dahil edilmesini sağlar.
Include guard: #ifndef, #define, #endif direktifleri ile aynı işlevi yapar ve tüm derleyiciler tarafından desteklenir.

Implementation dosyasında, fonksiyonların sınıfa ait olduğunu belirtmek için "ClassName::FunctionName" şeklinde kapsam belirteci (::) kullanılır.

Derleyici ayarlarında (örneğin VS Code'da tasks.json), hangi dosyaların derleneceği belirtilir. Genellikle tüm .cpp dosyaları derlenir.

Dış kodlar sadece header dosyasını #include eder, implementation dosyasını değil.


Örnek:

// inventory.h
#pragma once // Dosyanın birden fazla kez dahil edilmesini engeller

#ifndef INVENTORY_H
#define INVENTORY_H

#include
#include

class Inventory {
public:
Inventory(); // Constructor
~Inventory(); // Destructor

void addItem(const std::string& item);  // Öğeyi ekle
void removeItem(const std::string& item);  // Öğeyi çıkar
std::string getItem(int index) const;  // İndeksteki öğeyi döndür
int getItemCount() const;  // Öğelerin sayısını döndür
void displayInventory() const;  // Envanteri göster

private:
std::vectorstd::string* items; // Öğeler dinamik olarak tutulur
int capacity; // Maksimum kapasite
};

#endif // INVENTORY_H

// inventory.cpp
#include "inventory.h"
#include
#include // std::find için

// Constructor: capacity'yi 10 olarak başlatır, items için dinamik bellek ayırır
Inventory::Inventory() : capacity(10) {
items = new std::vectorstd::string();
}

// Destructor: Dinamik belleği serbest bırakır
Inventory::~Inventory() {
delete items;
}

void Inventory::addItem(const std::string& item) {
if (items->size() < capacity) {
items->push_back(item); // Öğeyi ekle
} else {
std::cout << "Envanter dolu!" << std::endl; // Kapasite doluysa uyarı ver
}
}


void Inventory::removeItem(const std::string& item) {
// items vektöründe öğeyi ara
auto it = std::find(items->begin(), items->end(), item);
if (it != items->end()) {
items->erase(it); // Öğeyi bulursa sil
} else {
std::cout << "Öğe bulunamadı!" << std::endl; // Bulamazsa uyarı ver
}
}

std::string Inventory::getItem(int index) const {
if (index >= 0 && index < items->size()) {
return (*items)[index]; // Geçerli indeksse öğeyi döndür
} else {
return "Geçersiz indeks!"; // Hatalı indeks için mesaj
}
}

int Inventory::getItemCount() const {
return items->size(); // Öğelerin sayısını döndür
}

void Inventory::displayInventory() const {
std::cout << "Envanterdeki öğeler:" << std::endl;
for (const auto& item : *items) {
std::cout << "- " << item << std::endl; // Tüm öğeleri yazdır
}
}


Notlar:

Fonksiyon tanımları "Inventory::" ile başlar, bu fonksiyonların Inventory sınıfına ait olduğunu belirtir.
items, dinamik olarak ayrılmış std::vector pointer'ıdır, bu yüzden erişim için -> operatörü kullanılır.
addItem fonksiyonu kapasiteyi kontrol eder, doluysa ekleme yapmaz.
removeItem fonksiyonu std::find kullanarak öğeyi arar ve bulursa siler.
getItem ve getItemCount fonksiyonları nesnenin durumunu değiştirmediği için const olarak işaretlenmiştir.
displayInventory fonksiyonu envanterdeki tüm öğeleri ekrana listeler.
Header dosyasında fonksiyonların sadece bildirimi (prototipi) vardır, burada ise gerçek kodları yazılır.
Bu yapı, kodun daha düzenli, okunabilir ve yönetilebilir olmasını sağlar.
Derleyici, tüm .cpp dosyalarını derler ve linker hepsini birleştirerek çalıştırılabilir dosya oluşturur.

 */