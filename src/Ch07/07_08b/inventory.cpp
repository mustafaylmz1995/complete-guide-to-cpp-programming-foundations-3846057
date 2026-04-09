#include "inventory.h"

// Default Constructor
Inventory::Inventory(): capacity(10){
    items = new std::vector<std::string>();
}

// Overloaded Constructor
Inventory::Inventory(int capacity_i): capacity(capacity_i){
    items = new std::vector<std::string>();
}

// Destructor
Inventory::~Inventory(){
    delete items; // Prevent memory leak by deallocating the dynamic vector
}

// Overloade += operator to Add item to inventory
Inventory& Inventory::operator+=(const std::string& item){
    if (items->size() < capacity)
        items->push_back(item);
    else
        std::cout << "Inventory is full, cannot add " << item << std::endl;

    return *this;
}

// Overloaded -= to Remove item from inventory
Inventory& Inventory::operator-=(const std::string& item){
    auto it = std::find(items->begin(), items->end(), item);
    if (it != items->end())
        items->erase(it);
    else
        std::cout << "Item " << item << " not found in inventory" << std::endl;
    
    return *this;
}

// Overload[] operator to Access item by index
std::string Inventory::operator[](int index) const{
    if (index >= 0 && index < items->size())
        return (*items)[index];
    else
        return "Index out of bounds";
}

// Get number of items in the inventory
int Inventory::getItemCount() const{
    return items->size();
}

// Display inventory contents
void Inventory::displayInventory() const{
    std::cout << "Inventory: [ ";
    for (size_t i = 0; i < items->size(); ++i){
        std::cout << (*items)[i];
        if (i < items->size() - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}
