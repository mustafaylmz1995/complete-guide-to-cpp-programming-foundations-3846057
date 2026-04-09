#pragma once

#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
#include <string>

class Item
{
    // Members
    protected:
        std::string name;
        int weight;


    private:

    public:

    // Methods
    protected:

    private:

    public:
    Item(const std::string& itemName, int itemWeight) : name(itemName), weight(itemWeight) {};

    virtual ~Item() {};

    std::string getName(void) const 
    { return name; };

    int getWeight(void) const 
    { return weight; };

    virtual void use() const 
    { std::cout << "Using" << name << "...\n" ; };

    virtual void display() const 
    { std::cout << "Item: " << name << ", Weight: " << weight << std::endl; };



};


#endif //__ITEM_HPP__