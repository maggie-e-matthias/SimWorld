#pragma once

#include <iostream> 
#include <string>
#include "base.h"
using namespace std;


// Survivor Class (Base class provides generic survivor that has no special skills)
class survivor: public living{
    private: 
        int XPLevel;
    public:
        survivor(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        survivor(const survivor &c);
        virtual ~survivor();

        int getXPLevel() const;
        void setXPLevel(int);

        void getAction() const override;
};

// Special survivors classes

// Doctor survivor (has the skill to make meds and heal other survivors)
class doctor: public survivor{
    public: 
        doctor(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        doctor(const doctor &c);
        virtual ~doctor();

        void heal(survivor &s);
        void makeMeds();

};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{
    public: 
        scout(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        scout(const scout &c);
        virtual ~scout();

        void gatherResources();
};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{
    public: 
        engineer(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        engineer(const engineer &c);
        virtual ~engineer();

        void build();
        void repair();
};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{
    public: 
        farmer(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        farmer(const farmer &c);
        virtual ~farmer();

        void breed();
        void growCrops();
};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{
    public: 
        hunter(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false);
        hunter(const hunter &c);
        virtual ~hunter();

        void hunt();
        void fendOff();
}; 