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
        survivor();
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
        doctor();
        doctor(const doctor &c);
        virtual ~doctor();

        void heal(survivor &s);
        void makeMeds();

};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{
    public: 
        scout();
        scout(const scout &c);
        virtual ~scout();

        void gatherResources();
};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{
    public: 
        engineer();
        engineer(const engineer &c);
        virtual ~engineer();

        void build();
        void repair();
};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{
    public: 
        farmer();
        farmer(const farmer &c);
        virtual ~farmer();

        void breed();
        void growCrops();
};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{
    public: 
        hunter();
        hunter(const hunter &c);
        virtual ~hunter();

        void hunt();
        void fendOff();
}; 