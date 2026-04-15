// Complete Guide to C++ Programming Foundations
// Exercise 07_05
// Using Classes, by Eduardo Corpeño 

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

Inventory sınıfını kullanarak nesne oluşturma ve fonksiyonları kullanma örneği

int main() {
// 1. Kapasitesi 5 olan bir inventory (envanter) nesnesi oluşturuyoruz
Inventory inventory(5); // capacity = 5

// 2. Envantere 5 farklı öğe ekliyoruz
inventory.addItem("health potion");  // Sağlık iksiri
inventory.addItem("mana potion");    // Mana iksiri
inventory.addItem("sword");          // Kılıç
inventory.addItem("shield");         // Kalkan
inventory.addItem("bow");            // Yay

// 3. Şu an envanter dolu, içeriği ekrana yazdırıyoruz
inventory.displayInventory();  // 5 öğe gösterilir

// 4. Envanter dolu olduğu için yeni bir öğe eklemeye çalışıyoruz
inventory.addItem("arrow");  // "Envanter dolu!" mesajı yazdırılır

// 5. Bir öğeyi envanterden çıkarıyoruz: mana potion
inventory.removeItem("mana potion");  // Öğeyi kaldırır

// 6. Şu an envanterde kaç öğe olduğunu ekrana yazdırıyoruz
std::cout << "Item count: " << inventory.getItemCount() << std::endl;  // 4 yazdırılır

// 7. İndeks 2'deki öğeyi alıp ekrana yazdırıyoruz
std::cout << "Item at index 2: " << inventory.getItem(2) << std::endl;  // "shield" yazdırılır

// 8. Son olarak envanterin güncel halini ekrana yazdırıyoruz
inventory.displayInventory();  // 4 öğe gösterilir, mana potion yok

return 0;

}

/*
Notlar:

addItem fonksiyonu, kapasite doluysa öğe eklemez ve uyarı verir.
removeItem fonksiyonu, öğe varsa siler, yoksa uyarı verir.
getItemCount fonksiyonu mevcut öğe sayısını döner.
getItem fonksiyonu geçerli indeks için öğeyi döner, değilse hata mesajı verir.
displayInventory fonksiyonu tüm öğeleri listeler.
Bu örnek, nesne yönelimli programlamada sınıf fonksiyonlarının nasıl kullanılacağını gösterir.



C++ Derleyici Araç Zinciri ve Kaynak/Header Dosyaları Hakkında Notlar

C++ kodu, derleyici araç zinciri (compiler tool chain) adı verilen bir dizi programdan geçerek çalıştırılabilir dosyaya dönüştürülür.

Derleyici (Compiler): C++ kaynak dosyalarını (.cpp) alır ve bunları işlemci için anlaşılır olan assembly diline çevirir. Bu aşamada assembly kodu içeren yeni bir dosya oluşur.

Assembler: Assembly kodunu alır ve nesne dosyası (object file) oluşturur. Nesne dosyası, çalıştırılabilir dosyaya çok yakın ama henüz tamamlanmamış koddur.

Linker: Projedeki tüm nesne dosyalarını birleştirerek son çalıştırılabilir programı oluşturur.

Kaynak Kod Dosyaları (.cpp): Fonksiyonların ve sınıfların gerçek kodlarını içerir. Derleyici bu dosyaları derler.

Header Dosyaları (.h veya .hpp): Sadece sınıf tanımları, fonksiyon bildirimleri ve makrolar içerir. İçlerinde çalıştırılabilir kod yoktur.

Implementation (.cpp) dosyaları, kendi header dosyalarını #include ile içermelidir. Böylece derleyici, fonksiyon ve sınıf bildirimlerini görür.

Dış kodlar (sınıfları kullanan diğer kodlar) sadece header dosyalarını dahil etmelidir, implementation dosyalarını değil.

Derleme sırasında tüm implementation dosyaları derlenmeli ve linker'a dahil edilmelidir.

IDE'ler bu işlemleri otomatik yapar, ancak komut satırında çalışırken makefile gibi dosyalarla yönetilir.


// Bu notlar, C++ programlama ve derleyici sürecini ilk defa öğrenenler için temel kavramları sade ve anlaşılır şekilde açıklar.


*/


