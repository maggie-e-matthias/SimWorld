#pragma once

#include <iostream> 
#include <string>
#include <vector>
#include "base.h"

#include "builds.h"
#include "animals.h"
using namespace std;


// Survivor Class (Base class provides generic survivor that has no special skills)
class survivor: public living{
    private: 
        int XPLevel;
        vector<item> inventory;
        const int maxInventorySize;
    public:
        survivor(string name = "New Survivor", bool isActive = true);
        survivor(const survivor &c);
        virtual ~survivor();

        int getXPLevel() const;
        void setXPLevel(int);

        // Inventory system methods
        void addToInventory(item);
        bool isInventoryEmpty() const;
        vector<item> getInventory() const; // Gets the entire inventory
        item getFromInventory(item) const; // Gets one single item from inventory
        void useFromInventory(item, int); // Actually consumes item from inventory
        

        void getAction() const override;
};

// Special survivors classes

// Doctor survivor (has the skill to make meds and heal other survivors)
class doctor: public survivor{
    public: 
        doctor(string name = "New Doctor", bool isActive = true);
        doctor(const doctor &c);
        virtual ~doctor();

        void heal(survivor &s);
        void makeMeds();

};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{
    public: 
        scout(string name = "New Scout", bool isActive = true);
        scout(const scout &c);
        virtual ~scout();

        void gatherResources();
};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{
    public: 
        engineer(string name = "New Engineer", bool isActive = true);
        engineer(const engineer &c);
        virtual ~engineer();

        void build();
        void repair();
};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{
    public: 
        farmer(string name = "New Farmer", bool isActive = true);
        farmer(const farmer &c);
        virtual ~farmer();

        void breed();
        void growCrops();
};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{
    public: 
        hunter(string name = "New Hunter", bool isActive = true);
        hunter(const hunter &c);
        virtual ~hunter();

        void hunt();
        void fendOff();
}; 