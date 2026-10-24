
#pragma once

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

// Base class for buildings
class builds : public simEntity {
private:
    int durability;
    const int maxDurability;
    int upgradeLevel;

public:
   builds(int durability = 100, int maxDurability = 100,
       int upgradeLevel = 0);

    builds(const builds& c);
    virtual ~builds();

    int getDurability() const;
    void setDurability(int durability);

    int getMaxDurability() const;

    int getUpgradeLevel() const;
    void setUpgradeLevel(int upgradeLevel);
};

// Resource items
enum class item {
    WATER, FRUITS, COCONUTS, MEAT, FISH,
    MEDS, WOOD, LEATHER, METAL, STONE
};
