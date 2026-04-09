#pragma once 

#ifndef __AID_HPP__
#define __AID_HPP__

#include "item.hpp"
class Aid : public Item
{
    private: 
        int healingPoints;

    public:
    Aid(const std::string& aidName, int aidWeight, int aidHealingPoints) : Item(aidName, aidWeight), healingPoints(aidHealingPoints)
    { };

    ~Aid(){};

    void use() const override
    { std::cout << "Using " << name << " to heal " << healingPoints << " health points" << std::endl;  };

    void display() const override
    { std::cout << "Aid: " << name << ", Weight: " << weight << ", Healing Points: " << healingPoints << std::endl;};


};


#endif // __AID_HPP__