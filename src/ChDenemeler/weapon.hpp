#pragma once

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include "item.hpp"

class Weapon : public Item 
{

    // Members
    protected:

    private:
        int damage;

    public:

    // Methods
    protected:

    private:

    public:
        Weapon(const std::string& weaponName, int weaponWeight, int weaponDamage) : Item(weaponName, weaponWeight), damage(weaponDamage) 
        {};

    ~Weapon() {};

    void use() const override
    { std::cout << "Swinging the weapon " << name << " with damage " << damage << std::endl; }

    void display() const override
    { std::cout << "Weapon: " << name << ", Weight: " << weight << ", Damage: " << damage << std::endl; };



};

#endif // __WEAPON_HPP__