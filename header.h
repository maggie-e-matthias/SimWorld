#include <iostream> 

// ------ Survivor Island ------
// (Where you either make it back to civilization or die trying)

/* Apparently your nice little cruise trip turned into a holy disaster and the ship crashes on an 
   abandoned island! Your goal is to survive the harsh conditions on the island until you manage to 
   get help! Or die trying.. */


// The Base for all other entities

// non-type template parameter used as a counter for total no. of entities created 
// (despite the number of entities destroyed), the counter will serve as a unique ID generator
class simEntity{ // Abstract base class
    private: 
        int ID;
        string* name;
        bool isActive;
        int daysItLasted;
    public: 
        // Constructors & Destructor
        simEntity(); 
        simEntity(simEntity &c);
        ~simEntity();

        void howLongDidItLast();
        void virtual getAction() const = 0;
};


// Living Entities base Class 
class living: public simEntity{};

// Survivor Class (Base class provides generic survivor that has no special skills)
class survivor: public living{};

// Special survivors classes

// Doctor survivor (has the skill to make meds and heal other survivors)
class doctor: public survivor{};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{}; 

// Animals class, user can spawn (create) whatever animal they want the
// survivors to breed 
class animal: public living{};

// Rabbit class, has minimal health and minimal meat drop
class rabbit: public animal{}; 

// Goat class, has the ability to give milk, meat, and leather
class goat: public animal{}; 

// Pigs class, drops most meat but no leather
class pig: public animal{};


// Builds class, contains all buildings survivors can make, 
// only on condition they have enough resources to build them, plus it invokes build and repair events

class builds: public simEntity{};

// Specific builds classes

// Hut class, most basic build where survivors spend the night
class hut: public builds{};

// Fence class, the main protector of survivors camp
class fence: public builds{};

// Farm class, where farmer survivors can grow crops 
class farm: public builds{}; 

// Storage class, where survivors can keep their resources
class storage: public builds{};

// Animal Pen class, where breeded animals can live
class animalPen: public builds{};

// General functions

void printUI();