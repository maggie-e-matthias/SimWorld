#include "include/base.h"
#include <iostream>
#include <string>
using namespace std;

// Sim Entity

// Constructors & Destructor

// Static member count declared to generate unique id based on how many entities were created
// despite how many are still there and how many were destroyed


int simEntity::count = 0;

simEntity::simEntity(string name, bool isActive): isActive(isActive), daysItLasted(0) {
    count++;
    ID = count;
    this->name = new string(name);
}

simEntity::simEntity(const simEntity &c): isActive(c.isActive), daysItLasted(c.daysItLasted) {
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

// Some values like health level, hunger level, etc, are set to default values (listed in header file)
// that are only changed if the derived class requires otherwise
living::living(string name, bool isActive, int healthLevel, int maxHealthLevel, int hungerLevel, int maxHungerLevel, bool isSick): simEntity(name, isActive), healthLevel(healthLevel), maxHealthLevel(maxHealthLevel), hungerlevel(hungerLevel), maxHungerLevel(maxHungerLevel), isSick(isSick) {
    cout << "Living entity created" << endl;
    
}

living::living(const living &c): simEntity(c), healthLevel(c.healthLevel), maxHealthLevel(c.maxHealthLevel), hungerlevel(c.hungerlevel), maxHungerLevel(c.maxHungerLevel), isSick(c.isSick) {
    cout << "Living entity created" << endl;
}

living::~living() {
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

template <int N>
builds<N>::builds(string name, bool isActive,int durability, int maxDurability, int upgradeLevel, item buildRequirements[], item upgradeRequirements): simEntity(name, isActive),
 durability(durability), maxDurability(maxDurability), upgradeLevel(upgradeLevel), buildRequirements(buildRequirements), upgradeRequirements(upgradeRequirements) {
    cout << "Build entity created" << endl;
}

template <int N>
builds<N>::builds(const builds &c): simEntity(c), durability(c.durability), maxDurability(c.maxDurability), upgradeLevel(c.upgradeLevel),
    buildRequirements(c.buildRequirements), upgradeRequirements(c.upgradeRequirements) {
    cout << "Build entity created" << endl;
}

template <int N>
builds<N>::~builds() {
    cout << "Build entity destroyed" << endl;
}

// Getters and Setters

template <int N>
int builds<N>::getDurability() const {
    return durability;
}

template <int N>
void builds<N>::setDurability(int durability) {
    this->durability = durability;
}

template <int N>
int builds<N>::getMaxDurability() const{
    return maxDurability;
}

template <int N>
void builds<N>::setMaxDurability(int maxDurability) {
    this->maxDurability = maxDurability;
}

template <int N>
int builds<N>::getUpgradeLevel() const {
    return upgradeLevel;
}

template <int N>
void builds<N>::setUpgradeLevel(int upgradeLevel) {
    this->upgradeLevel = upgradeLevel;
}