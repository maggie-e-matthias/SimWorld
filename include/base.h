#pragma once

#include <iostream>
#include <string>
using namespace std;

// The Base for all other entities

// Static member count declared to generate unique id based on how many entities were created
// despite how many are still there and how many were destroyed

class simEntity{ // Abstract base class
    private: 
        static int count;
        int ID;
        string* name;
        bool isActive;
        int daysItLasted;
    public: 
        // Constructors & Destructor
        simEntity(string name = "NPC", bool isActive = true);
        simEntity(const simEntity &c);
        virtual ~simEntity();

        // Getters and Setters
        int getID();
        string* getName() const;
        void setName(string);
        bool getisActive() const;
        void setActive(bool);
        int getDaysLasted() const;
        void setDaysLasted(int);

        void virtual getAction() const = 0;
        virtual simEntity* clone() const = 0;
        void setIDForUndo(int id);

};


// Living Entities base Class 
class living: public simEntity{ // Abstract base class
    private:
        int healthLevel;
        const int maxHealthLevel;
        int hungerlevel;
        const int maxHungerLevel;
        bool isSick; 
    public: 
        living(int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        living(const living &c);
        virtual ~living();

        int getHealthLevel() const;
        void setHealthLevel(int);
        bool getIsSick() const;
        void setIsSick(bool);
        int getMaxHealthLevel() const;
        //void setMaxHealthLevel(int);
        int getHungerLevel() const;
        void setHungerLevel(int);
        int getMaxHungerLevel() const;
        //void setMaxHungerLevel(int);
};

// Builds class, contains all buildings survivors can make, 
// only on condition they have enough resources to build them, plus it invokes build and repair events

class builds: public simEntity{
    private:
        int durability;
        const int maxDurability;
        int upgradeLevel;
    public: 
        builds(int durability = 100, int maxDurability = 100, int upgradeLevel = 0);
        builds(const builds &c);
        virtual ~builds();

        int getDurability() const;
        void setDurability(int);
        int getMaxDurability() const;
        //void setMaxDurability(int);
        int getUpgradeLevel() const;
        void setUpgradeLevel(int);
};