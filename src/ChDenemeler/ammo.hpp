#pragma once

#ifndef __AMMO_HPP__
#define __AMMO_HPP__

#include "item.hpp"

class Ammo : public Item
{
    //Members
    protected:

    private:
    int rounds;

    public:


    //Methods
    protected:

    private:

    public:
    Ammo(const std::string& ammoName, int ammoWeight, int ammoRounds) : Item(ammoName, ammoWeight), rounds(ammoRounds) {};

    ~Ammo() {};

    void use() const override
    { std::cout << "Reloading " << rounds << " rounds of " << name << std::endl; };

    void display() const override
    { std::cout << "Ammo: " << name << ", Weight: " << weight << ", Rounds: "<< rounds << std::endl; };

};



#endif // __AMMO_HPP__