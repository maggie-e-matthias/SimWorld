#pragma once // To solve the issue of multiple includes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class for all entities
class simEntity {
private:
    static int count;
    int ID;
    string* name;
    bool isActive;
    int daysItLasted;

public:
    simEntity(string name = "NPC", bool isActive = true);
    simEntity(const simEntity& c);
    virtual ~simEntity();

    int getID() const;
    string* getName() const;
    void setName(string name);

    bool getisActive() const;
    void setActive(bool active);

    int getDaysLasted() const;
    void setDaysLasted(int days);

    virtual void getAction() const = 0;
    virtual simEntity* clone() const = 0;

    // Used when undoing a deletion or modification
    void setIDForUndo(int id);
};

// Base class for living entities
class living : public simEntity {
private:
    int healthLevel;
    const int maxHealthLevel;
    int hungerlevel;
    const int maxHungerLevel;
    bool isSick;

public:
    living(string name = "NPC", bool isActive = true,
           int healthLevel = 100, int maxHealthLevel = 100,
           int hungerLevel = 100, int maxHungerLevel = 100,
           bool isSick = false);

    living(const living& c);
    virtual ~living();

    int getHealthLevel() const;
    void setHealthLevel(int healthLevel);

    bool getIsSick() const;
    void setIsSick(bool isSick);

    int getMaxHealthLevel() const;

    int getHungerLevel() const;
    void setHungerLevel(int hungerLevel);

    int getMaxHungerLevel() const;
};

// Builds class, contains all buildings survivors can make, 
// only on condition they have enough resources to build them, plus it invokes build and repair events

class builds: public simEntity{
    private:
        int durability;
        int maxDurability;
        int upgradeLevel;
        vector<item> buildRequirements; // Array of required resources to create the build
        item upgradeRequirements;
        vector<string> features;
    public: 
        builds(string name = "New Build", bool isActive = true, int durability = 100, int maxDurability = 100,
             vector<item> buildRequirements = {item::WOOD}, item upgradeRequirements = item::WOOD, vector<string> features = {"Just a build"});
        builds(const builds &c);
        virtual ~builds();

        int getDurability() const;
        void setDurability(int);
        int getMaxDurability() const;
        void setMaxDurability(int); // Max durabitlity is modifiable as it can increase with upgrades
        int getUpgradeLevel() const;
        void setUpgradeLevel(int);
};


/* --- Resource Items --- */

/* Items have been defined explicitly as an enum class rather than a class since they are 
   far simpler than needing a class of their own*/

enum class item {NONE, WATER, FRUITS, COCONUTS, MEAT, FISH, MEDS, WOOD, LEATHER, METAL, STONE};


