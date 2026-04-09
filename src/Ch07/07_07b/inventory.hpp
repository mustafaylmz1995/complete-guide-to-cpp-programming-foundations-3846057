#pragma once 

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <string>
#include <iostream>
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
    Inventory();

    // Overloaded Constructor
    Inventory(int capacity_i);

    // Destructor
    ~Inventory();
    
    // Add item to inventory
    void addItem(const std::string& item);

    // Remove item from inventory
    void removeItem(const std::string& item);

    // Access item by index
    std::string getItem(int index) const;

    // Get number of items in the inventory
    int getItemCount() const;

    // Display inventory contents
    void displayInventory() const;


    private:

    protected:


};


#endif // INVENTORY_HPP