// Complete Guide to C++ Programming Foundations
// Exercise 07_02
// Data Members, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

class Inventory
{
    // data
    public:

    private:
        //containers
        std::vector<std::string> *items; // Pointer to a vector of items
        int capacity; // Maximum number of items allowed

    protected:


    // functions
    public:

    // Default Constructor
    Inventory() : capacity(10)
    {
        items = new std::vector<std::string>();
    }

    // Overloaded Constructor
    Inventory(int capacity_i) : capacity(capacity_i)
    {
        items = new std::vector<std::string>();
    }

    // Destructor
    ~Inventory()
    {
        delete items; // Prevent memory leak by deallocating the dynamic vector
    }

    // Add item to inventory
    void addItem(const std::string& item)
    {
        if(items->size() < capacity)
            items->push_back(item);
        else
            std::cout << "Inventory is full, cannot add" << item << std::endl;
    }

    // Remove item from inventory
    void removeItem(const std::string& item)
    {
        auto it = std::find(items->begin(), items->end(), item);

        if(it != items->end())
            items->erase(it);
        else
            std::cout << "Item " << item << " not found in inventory" << std::endl;
    }

    // Access item by index
    std::string getItem(int index) const
    {
        if(index >= 0 && index < items->size())
            return (*items)[index];
        else
            return "Index out of bounds";
    }

    // Get number of items in the inventory
    int getItemCount() const
    {
        return items->size();
    }

    // Display inventory contents
    void displayInventory() const
    {
        std::cout << "Inventory: [ ";
        for(size_t i =0; i < items->size(); i++)
        {
            std::cout << (*items)[i];
            if(i < items->size() - 1) 
                std::cout << ", ";
        }
        std::cout << " ] " << std::endl;
    }


    private:

    protected:


};


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
    std::cout << "The inventory now contains " << myInventory.getItemCount() << " items." << std::endl;
    // Access item by index
    std::cout << "Item at index 2 is " << myInventory.getItem(2) << "." << std::endl;

    // Display final state of inventory
    myInventory.displayInventory();

    std::cout << std::endl << std::endl;
    return 0;
}

/*

C++ Sınıfları ve Nesneleri Notları
1. Sınıf (class) Nedir?
- Sınıf, programda nesneler oluşturmak için bir şablondur.
- Nesneler, sınıfın çalışma zamanında oluşturulan somut örnekleridir.
Örnek: "Potion" sınıfı, iksirlerin yapısını ve davranışını tanımlar.

2. Sınıf Üyeleri
- Veri üyeleri: Nesnenin durumunu tutan değişkenler (örneğin, iksir gücü, süre).
- Fonksiyon üyeleri (metotlar): Nesnenin davranışlarını tanımlayan fonksiyonlar (örneğin, iri kullanma, etkisini gösterme).

3. Nesne Oluşturma ve Bellek Yönetimi
- Nesneler stack (yığın) veya heap (yığın dışı) bellekte oluşturulabilir.
- Stack'te oluşturulan nesneler otomatik yönetilir ve kapsam dışına çıkınca yok edilir.
- Heap'te oluşturulan nesneler için new ve delete operatörleri kullanılır, yönetim manueldir.

4. Erişim Belirleyiciler (Access Specifiers)
- public: Her yerden erişilebilir.
- private: Sadece sınıfın içinden erişilebilir.
- protected: private gibidir, ancak türetilmiş sınıflardan da erişilebilir.

5. Kapsülleme (Encapsulation)
- Nesnenin durumu ve davranışı bir arada gruplanır.
- Duruma erişim kontrollü yapılır, dışarıdan doğrudan değiştirilmez.

6. Yapıcı (Constructor) ve Yıkıcı (Destructor)
- Constructor: Nesne oluşturulurken otomatik çağrılır, nesneyi başlatır.
- Constructor aşırı yüklenebilir (farklı parametrelerle birden fazla constructor olabilir).
- Destructor: Nesne yok edilirken çağrılır, kaynakları temizler.
- Heap'te oluşturulan nesnelerde kaynak yönetimi için önemlidir.

7. Operatör Aşırı Yükleme
- Fonksiyonlar gibi, operatörler de aşırı yüklenebilir.
- Böylece +, -, == gibi operatörler nesneler için anlam kazanır.

Özet:
C++ sınıfları, nesnelerin durumunu ve davranışını tanımlayan şablonlardır. 
Bellek yönetimi, erişim kontrolü ve yaşam döngüsü yönetimi (constructor/destructor) önemli kavramlardır. 
Operatör aşırı yükleme ile sınıflar dilin doğal parçaları gibi kullanılabilir.

*/