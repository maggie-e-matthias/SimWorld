#include <iostream> 
#include <string>
#include "base.h"
#include "animals.h"
#include "builds.h"
using namespace std;

// Survivor Class (Base class provides generic survivor that has no special skills)
class survivor: public living{
    private: 
        int XPLevel;
    public:
        survivor();
        survivor(survivor &c);
        virtual ~survivor();

        int getXPLevel() const;
        void setXPLevel(int);
};

// Special survivors classes

// Doctor survivor (has the skill to make meds and heal other survivors)
class doctor: public survivor{
    public: 
        doctor();
        doctor(doctor &c);
        virtual ~doctor();

        void heal(survivor &s);
        void makeMeds();

};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{
    public: 
        scout();
        scout(scout &c);
        virtual ~scout();

        void gatherResources();
};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{
    public: 
        engineer();
        engineer(engineer &c);
        virtual ~engineer();

        void build(builds &b);
        void repair(builds &b);
};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{
    public: 
        farmer();
        farmer(farmer &c);
        virtual ~farmer();

        void breed(animal &a);
        void growCrops(farm &f);
};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{
    public: 
        hunter();
        hunter(hunter &c);
        virtual ~hunter();

        void hunt(animal &a);
        void fendOff();
}; 