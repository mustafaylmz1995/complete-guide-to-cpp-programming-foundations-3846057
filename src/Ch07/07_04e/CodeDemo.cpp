// Complete Guide to C++ Programming Foundations
// Exercise 07_04
// Constructors and Destructors, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    // Default Constructor
    Inventory(): capacity(10){
        items = new std::vector<std::string>();
    }

    // Overloaded Constructor
    Inventory(int capacity_i): capacity(capacity_i){
        items = new std::vector<std::string>();
    }

    // Destructor
    ~Inventory(){
        delete items; // Prevent memory leak by deallocating the dynamic vector
    }

    // Add item to inventory
    void addItem(const std::string& item){
        if (items->size() < capacity)
            items->push_back(item);
        else
            std::cout << "Inventory is full, cannot add " << item << std::endl;
    }

    // Remove item from inventory
    void removeItem(const std::string& item){
        auto it = std::find(items->begin(), items->end(), item);
        if (it != items->end())
            items->erase(it);
        else
            std::cout << "Item " << item << " not found in inventory" << std::endl;
    }

    // Access item by index
    std::string getItem(int index) const{
        if (index >= 0 && index < items->size())
            return (*items)[index];
        else
            return "Index out of bounds";
    }

    // Get number of items in the inventory
    int getItemCount() const{
        return items->size();
    }

    // Display inventory contents
    void displayInventory() const{
        std::cout << "Inventory: [ ";
        for (size_t i = 0; i < items->size(); ++i){
            std::cout << (*items)[i];
            if (i < items->size() - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }

private:
    std::vector<std::string> *items; // Pointer to a vector of items
    int capacity; // Maximum number of items allowed
};

int main(){
    
    std::cout << std::endl << std::endl;
    return 0;
}


/*
Inventory sınıfı için constructor ve destructor örneği
Constructor: Nesne oluşturulduğunda çağrılır
- Sınıf adıyla aynı isimde olmalı, dönüş tipi yoktur
- Burada capacity üyesini 10 olarak başlatıyoruz
- items için dinamik bellek tahsis ediyoruz (heap üzerinde)
- Bu constructor, parametre almayan "default constructor" olarak adlandırılır
entory() : capacity(10) {
ms = new std::vectorstd::string(); // items için dinamik bellek ayır
Constructor overload: capacity değerini dışarıdan alır
- Parametre olarak capacity_i alıyoruz
- this->capacity ile üye değişkeni, capacity_i ile parametreyi ayırt ediyoruz
entory(int capacity_i) : capacity(capacity_i) {
ms = new std::vectorstd::string(); // items için dinamik bellek ayır
Destructor: Nesne yok edilirken çağrılır
- Sınıf adı önünde ~ işareti olur
- Dinamik olarak ayrılan belleği serbest bırakmak için kullanılır
- Bellek sızıntılarını önlemek için delete kullanılır
ventory() {
ete items; // Dinamik belleği temizle
Notlar:
- Constructorlar nesne oluşturulurken otomatik çağrılır
- Member initializer list (:) ile üye değişkenler hızlı ve net şekilde başlatılır
- this pointer, üye değişken ile parametreyi ayırt etmek için kullanılır
- Destructor, dinamik kaynakları serbest bırakmak için önemlidir
- Bu yapılar, C++'da nesne yönelimli programlamanın temel taşlarıdır
Böylece, Inventory sınıfı nesneleri güvenli ve doğru şekilde oluşturulup yok edilir.
*/