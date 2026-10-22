#include "include/base.h"
#include <iostream>
#include <string>
using namespace std;

// Sim Entity

// Constructors & Destructor

// Static member count declared to generate unique id based on how many entities were created
// despite how many are still there and how many were destroyed


int simEntity::count = 0;

simEntity::simEntity(string name = "NPC", bool isActive = true): isActive(isActive), daysItLasted(0) {
    count++;
    ID = count;
    this->name = new string(name);
}

simEntity::simEntity(simEntity &c): isActive(c.isActive), daysItLasted(c.daysItLasted) {
    count++;
    ID = count;
    name = new string(*c.name);
}

simEntity::~simEntity() {
    delete name;
    cout << "simEntity destroyed" << endl;
}

// Getters and Setters

int simEntity::getID() {
    return ID;
}

string* simEntity::getName() const {
    return name;
}

void simEntity::setName(string name) {
    *this->name = name;
}

bool simEntity::getisActive() const {
    return isActive;
}

void simEntity::setActive(bool isActive) {
    this->isActive = isActive;
}

int simEntity::getDaysLasted() const {
    return daysItLasted;
}

void simEntity::setDaysLasted(int days) {
    this->daysItLasted = days;
}


// Living 

// Constructors & Destructor

living::living(int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 0, int maxHungerLevel = 100, bool isSick = false): simEntity(), healthLevel(healthLevel), maxHealthLevel(maxHealthLevel), hungerlevel(hungerLevel), maxHungerLevel(maxHungerLevel), isSick(isSick) {
    cout << "Living entity created" << endl;
    
}

living::living(living &c): simEntity(c), healthLevel(c.healthLevel), maxHealthLevel(c.maxHealthLevel), hungerlevel(c.hungerlevel), maxHungerLevel(c.maxHungerLevel), isSick(c.isSick) {
    cout << "Living entity created" << endl;
}

living::~living() {
    simEntity::~simEntity();
    cout << "Living entity destroyed" << endl;
}


// Getters and Setters

int living::getHealthLevel() const {
    return healthLevel;
}

void living::setHealthLevel(int healthLevel) {
    this->healthLevel = healthLevel;
}

bool living::getIsSick() const {
    return isSick;
}

void living::setIsSick(bool isSick) {
    this->isSick = isSick;
}

int living::getMaxHealthLevel() const {
    return maxHealthLevel;
}   

// void living::setMaxHealthLevel(int maxHealthLevel) {
//     this->maxHealthLevel = maxHealthLevel;
// }

// void living::setMaxHungerLevel(int maxHungerLevel) {
//     this->maxHungerLevel = maxHungerLevel;
// }

int living::getHungerLevel() const {
    return hungerlevel;
}

void living::setHungerLevel(int hungerLevel) {
    this->hungerlevel = hungerLevel;
}

int living::getMaxHungerLevel() const {
    return maxHungerLevel;
}


// Builds

// Constructors & Destructor

builds::builds(int durability = 100, int maxDurability = 100, int upgradeLevel = 0): simEntity(), durability(durability), maxDurability(maxDurability), upgradeLevel(upgradeLevel) {
    cout << "Build entity created" << endl;
}

builds::builds(builds &c): simEntity(c), durability(c.durability), maxDurability(c.maxDurability), upgradeLevel(c.upgradeLevel) {
    cout << "Build entity created" << endl;
}

builds::~builds() {
    simEntity::~simEntity();
    cout << "Build entity destroyed" << endl;
}

// Getters and Setters

int builds::getDurability() const {
    return durability;
}

void builds::setDurability(int durability) {
    this->durability = durability;
}

int builds::getMaxDurability() const {
    return maxDurability;
}

// void builds::setMaxDurability(int maxDurability) {
//     this->maxDurability = maxDurability;
// }

int builds::getUpgradeLevel() const {
    return upgradeLevel;
}

void builds::setUpgradeLevel(int upgradeLevel) {
    this->upgradeLevel = upgradeLevel;
}