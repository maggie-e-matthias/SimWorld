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
        simEntity(); 
        simEntity(simEntity &c);
        virtual ~simEntity();

        int getID();
        string* getName() const;
        void setName(string);
        bool getisActive() const;
        void setActive(bool);
        int getDaysLasted() const;

        void howLongDidItLast();
        void virtual getAction() const = 0;
};

int simEntity::count = 0;

// Living Entities base Class 
class living: public simEntity{ // Abstract base class
    private:
        int healthLevel;
        const int maxHealthLevel;
        bool isSick; 
    public: 
        living();
        living(living &c);
        virtual ~living();

        int getHealthLevel() const;
        void setHealthLevel(int);
        bool getIsSick() const;
        void setIsSick(bool);
        int getMaxHealthLevel() const;
};

// Builds class, contains all buildings survivors can make, 
// only on condition they have enough resources to build them, plus it invokes build and repair events

class builds: public simEntity{
    private:
        int durability;
        const int maxDurability;
    public: 
        builds();
        builds(builds &c);
        virtual ~builds();

        int getDurability() const;
        void setDurability(int);
        int getMaxDurability() const;
};