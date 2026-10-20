#include <iostream> 

// ------ Survivor Island ------
// (Where you either make it back to civilization or die trying)

/* Apparently your nice little cruise trip turned into a holy disaster and the ship crashes on an 
   abandoned island! Your goal is to survive the harsh conditions on the island until you manage to 
   get help! Or die trying.. */


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
        simEntity(); 
        simEntity(simEntity &c);
        virtual ~simEntity();

        int getID();
        string* getName();
        void setName(string);
        bool getisActive();
        void setActive(bool);
        int getDaysLasted();

        void howLongDidItLast();
        void virtual getAction() const = 0;
};

int simEntity::count = 0;

// Living Entities base Class 
class living: public simEntity{
    private:
        int healthLevel;
        bool isSick; 
};

// Survivor Class (Base class provides generic survivor that has no special skills)
class survivor: public living{
    private: 
        int xpLevel;
};

// Special survivors classes

// Doctor survivor (has the skill to make meds and heal other survivors)
class doctor: public survivor{
    public: 
        void heal(survivor &s);
        void makeMeds();
};

// Scout survivor (has the skill to bring more resources than others)
class scout: public survivor{
    public: 
        void gatherResources();
};

// Engineer survivor (has the skill to build utilies and repair them)
class engineer: public survivor{
    public: 
        void build(builds &b);
        void repair(builds &b);
};

// Farmer survivor (has the skill to breed animals and grow crops)
class farmer: public survivor{
    public: 
        void breed(animal &a);
        void growCrops(farm &f);
};

// Hunter survivor (has the skill to go on hunting trips and fend off enemies)
class hunter: public survivor{
    public: 
        void hunt(animal &a);
        void fendOff();
}; 

// Animals class, user can spawn (create) whatever animal they want the
// survivors to breed 
class animal: public living{
    public:
        virtual void dropResources() = 0;
};

// Rabbit class, has minimal health and minimal meat drop
class rabbit: public animal{
    public:
        void dropResources();
}; 

// Goat class, has the ability to give milk, meat, and leather
class goat: public animal{
    public:
        void dropResources();
}; 

// Pigs class, drops most meat but no leather
class pig: public animal{
    public:
        void dropResources();
};


// Builds class, contains all buildings survivors can make, 
// only on condition they have enough resources to build them, plus it invokes build and repair events

class builds: public simEntity{
    private:
        int durability;
};

// Specific builds classes

// Hut class, most basic build where survivors spend the night
class hut: public builds{
    public:
        hut();
};

// Fence class, the main protector of survivors camp
class fence: public builds{
    public:
        fence();
};

// Farm class, where farmer survivors can grow crops 
class farm: public builds{
    public:
        farm();
}; 

// Storage class, where survivors can keep their resources
class storage: public builds{
    public:
        storage();
};

// Animal Pen class, where breeded animals can live
class animalPen: public builds{
    public:
        animalPen();
};

// General functions

void printUI();