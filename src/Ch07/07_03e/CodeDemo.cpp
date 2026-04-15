// Complete Guide to C++ Programming Foundations
// Exercise 07_03
// Function Members, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
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
C++ Inventory Sınıfı Notları
1. Sınıf Tanımı
- "class" anahtar kelimesi ile başlar, ardından sınıf adı (Inventory) gelir.
- Sınıf, bir nesnenin yapısını ve davranışını tanımlar.
- Sınıfın tanımı süslü parantezler içinde yapılır ve noktalı virgül ile biter.
2. Kapsülleme (Encapsulation) ve Erişim Belirleyiciler
- Veriler (data members) dışarıdan gizlenir, bu yüzden "private" olarak tanımlanır.
- "private" üyeler sadece sınıfın içinden erişilebilir.
- Bu, verilerin dışarıdan doğrudan değiştirilmesini engeller ve güvenliği artırır.
3. Veri Üyeleri (Data Members)
- items: string tipinde öğeler tutan dinamik olarak ayrılmış bir vector işaretçisi (pointer).
Bu, envanterdeki öğeleri saklamak için kullanılır.
- capacity: inventory'nin taşıma kapasitesini tutan bir int değişkeni.
Bu, karakterin taşıyabileceği maksimum öğe sayısını temsil eder.
4. Dinamik Bellek Kullanımı
- items, dinamik olarak oluşturulmuş bir vector işaretçisidir, bu sayede öğeler çalışma anında yönetilir.
- Dinamik yapı, envanterin boyutunun esnek olmasını sağlar.
5. Örnek Senaryo
- Bu sınıf, bir aksiyon-macera oyunundaki envanteri temsil eder.
- Oyuncu farklı kategorilerde (yiyecek, silah, büyüsel öğeler vb.) öğeler toplayabilir.
- Oyuncu bu öğeleri kullanabilir, tüketebilir veya bırakabilir.
6. İleriki Adımlar
- Şu an sadece veri üyeleri tanımlandı, fonksiyonlar ve erişim metotları daha sonra eklenebilir.
- Private üyeler olduğu için, dışarıdan erişim için public fonksiyonlar (getter/setter) gereklidir.

Özet: Bu sınıf, oyun içi envanteri modellemek için temel bir yapı sağlar. Kapsülleme sayesinde veriler korunur ve dinamik vector kullanımı ile esnek bir öğe yönetimi sağlanır.

Inventory Sınıfı Fonksiyonları Notları
1. addItem Fonksiyonu
- Amaç: Envantere yeni bir öğe eklemek.
- Parametre: const std::string& item (eklenecek öğe)
- İşlem: Önce kapasite kontrolü yapılır. Eğer envanter dolu değilse, öğe vector'a push_back ile enir.
- push_back: STL vector sınıfının öğe ekleme fonksiyonudur.
- this->items: items bir pointer olduğu için, arrow (->) operatörü ile erişilir.
- Eğer kapasite doluysa, "Envanter dolu" mesajı yazdırılır.
2. removeItem Fonksiyonu
- Amaç: Envanterden belirli bir öğeyi silmek.
- Parametre: const std::string& item (silinecek öğe)
- İşlem: STL'nin find fonksiyonu ile öğe aranır.
- find: algorithm kütüphanesinden, başlangıç ve bitiş iterator'ları ile öğe arar.
- Eğer öğe bulunursa, vector'un erase fonksiyonu ile silinir.
- Bulunamazsa, "Öğe bulunamadı" mesajı yazdırılır.
3. getItem Fonksiyonu
- Amaç: Envanterdeki belirli bir indeksteki öğeyi okumak.
- Parametre: int index (okunacak öğenin indeksi)
- const fonksiyon: Fonksiyon nesnenin durumunu değiştirmez, bu yüzden const ile işaretlenir.
- İşlem: Index kontrol edilir (0 <= index < size).
- Geçerli ise, vector'dan öğe döndürülür.
- Geçersiz ise, "Geçersiz indeks" mesajı döndürülür.
4. getItemCount Fonksiyonu
- Amaç: Envanterde kaç öğe olduğunu döndürmek.
- Parametre yok, dönüş tipi int.
- Basit getter fonksiyonudur, vector'un size fonksiyonunu çağırır.
Genel Notlar:
- Fonksiyonlar, private veri üyelerine erişim sağlar ve veri gizliliğini korur.
- Setter fonksiyonları veri değiştirir, getter fonksiyonları veri okur.
- const kullanımı, fonksiyonların nesne durumunu değiştirmemesini garanti eder.
- STL fonksiyonları (push_back, find, erase) kodu basitleştirir ve performans sağlar.
- İyi programlama için, veri üyeleri private tutulur, erişim fonksiyonları public olarak tanımlanır.

Bu fonksiyonlar, C++'da nesne yönelimli programlama ve veri kapsüllemeyi gösteriyor.

*/