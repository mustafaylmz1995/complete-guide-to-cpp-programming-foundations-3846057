// Complete Guide to C++ Programming Foundations
// Exercise 04_04
// Using Objects with Pointers, by Eduardo Corpeño 

#include <iostream>
#include <string>
#include <chrono>
/*
// Type aliases for chrono classes
using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

int main(){
    TimePoint *start, *end;
    Duration *elapsed_seconds = new Duration();;
    std::string input;

    start = new TimePoint(Clock::now());

    std::cout << "Type 'start' as quickly as you can and hit ENTER: " << std::flush;
    std::cin >> input;

    end = new TimePoint(Clock::now());
    *elapsed_seconds = *end - *start;

    std::cout << "Reaction time: " << elapsed_seconds->count() << "s" << std::endl;
    
    std::cout << std::endl << std::endl;

    delete start;
    delete end;
    delete elapsed_seconds;


    return 0;
}
*/

#include <memory>

struct character_t 
{
    std::string name;
    int health;
    int strength;
};


character_t *createCharacter(std::string name, int health, int strength)
{
    character_t * newCharacter = new character_t;
    newCharacter->name = name;
    newCharacter->health = health;
    newCharacter->strength = strength;

    return newCharacter;
}

void createMonster() 
{
    int health = 100;
    std::cout << "Monster's health : " << health << std::endl;
}

void printCharacterValues(character_t *Character)
{
    std::cout << Character->name << "'s health : "<< Character->health << std::endl;
    std::cout << Character->name << "'s strength : "<< Character->strength << std::endl;
}
/*
void printCharacterValues(std::unique_ptr<character_t> &Character)
{
    std::cout << Character->name << "'s health : "<< Character->health << std::endl;
    std::cout << Character->name << "'s strength : "<< Character->strength << std::endl;
}
*/
int main()
{
    createMonster();
    std::cout << std::endl << std::endl;
    character_t *Hero = createCharacter("Hero", 100, 50);
    printCharacterValues(Hero);

    std::cout << std::endl << std::endl;

    std::unique_ptr<character_t> Boss = std::make_unique<character_t>();
    Boss->health = 200;
    Boss->strength = 40;
    Boss->name = "Boss";

    printCharacterValues(Boss.get());
    std::cout << std::endl << std::endl;


    delete Hero;
    return 0;

}

/*
Pointer'lar:
Belleğe doğrudan erişim sağlar, 
özellikle dinamik (heap) belleği yönetmek için gereklidir.
Bellek modeli:
 - Stack: Fonksiyon içi otomatik değişkenler burada tutulur, 
   hızlı ama sınırlı.
 - Heap: Dinamik olarak ayrılan bellek, 
   manuel yönetim gerektirir (new/delete).

Scope (Kapsam): 
Değişkenler sadece tanımlandıkları blokta geçerlidir, 
fonksiyon dışına çıkınca yok olurlar.
Bellek sorunları:
 - Memory leak: Heap belleği serbest bırakılmazsa oluşur.
 - Dangling pointer: Serbest bırakılmış belleğe işaret eden pointer.

Smart pointer'lar: 
Smart pointerlar, C++'ta dinamik bellek yönetimini otomatikleştirerek 
bellek sızıntısı ve dangling pointer gibi sorunları önler. 

 - std::unique_ptr: Tek bir sahiplik modeli uygular; 
   yani bir nesneye sadece bir unique_ptr sahip olabilir. 
   Nesne, unique_ptr kapsam dışına çıktığında otomatik olarak silinir. 
   Bu, manuel delete çağrısına gerek kalmadan güvenli bellek yönetimi 
   sağlar.

 - std::shared_ptr: Birden fazla shared_ptr aynı nesneyi paylaşabilir. 
   Nesne, son shared_ptr yok edildiğinde veya nullptr yapıldığında 
   otomatik olarak silinir. Bu, paylaşılan kaynakların yönetiminde 
   kullanışlıdır.

*/