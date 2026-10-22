#include "include/survivors.h"
#include <iostream>
#include <string>
using namespace std;

// Average survivor class, can be instantiated and has no special skills, but can be used as a base class for other survivors

// Constructors & Destructor
survivor::survivor(string name = "New Survivor", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): living(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick), XPLevel(0) {
    cout << "Survivor created" << endl;
}

survivor::survivor(const survivor &c): living(c), XPLevel(c.XPLevel) {
    cout << "Survivor created" << endl;
}

survivor::~survivor() {
    living::~living();
    cout << "Survivor destroyed" << endl;
}

// Getters and Setters

int survivor::getXPLevel() const {
    return XPLevel;
}

void survivor::setXPLevel(int XPLevel) {
    this->XPLevel = XPLevel;
}

// Other methods 
void survivor::getAction() const {
    // Get the action from the user
    cout << "What do you want to do? (move, attack, heal, quit): ";
}


// Doctor survivor

// Constructors & Destructor

doctor::doctor(string name = "New Doctor", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Doctor created" << endl;
}

doctor::doctor(const doctor &c): survivor(c) {
    cout << "Doctor created" << endl;
}

doctor::~doctor() {
    survivor::~survivor();
    cout << "Doctor destroyed" << endl;
}

// Other methods
void doctor::heal(survivor &s) {
    // Some heal effect
    if(s.getHealthLevel() < s.getMaxHealthLevel()) {
        s.setHealthLevel(s.getMaxHealthLevel());
        cout << "Healed " << *s.getName() << endl;

        setXPLevel(getXPLevel() + 10); // Increase XP level for healing
        // Needs to decrement the meds (consume them)
        
    }
    else{
        cout << s.getName() << " is already at full health!" << endl;
    }


}

void doctor::makeMeds(){
    // Starts a process of making meds, should take some time
    setXPLevel(getXPLevel() + 5); // Increase XP level for making meds
}

// Scout survivor

// Constructors & Destructor

scout::scout(string name = "New Scout", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Scout created" << endl;
}

scout::scout(const scout &c): survivor(c) {
    cout << "Scout created" << endl;
}

scout::~scout() {
    survivor::~survivor();
    cout << "Scout destroyed" << endl;
}

// Other methods
void scout::gatherResources() {
    // Starts a gathering process which should take some time
    // Increases sources in their inventory
    setXPLevel(getXPLevel() + 10); // Increase XP level for gathering resources
}

// Engineer survivor

engineer::engineer(string name = "New Engineer", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Engineer created" << endl;
}

engineer::engineer(const engineer &c): survivor(c) {
    cout << "Engineer created" << endl;
}

engineer::~engineer() {
    survivor::~survivor();
    cout << "Engineer destroyed" << endl;
}

// Other methods 
void engineer::build() {
    // Starts a building process which should take some time
    // e.g. startEvent(Build)
    setXPLevel(getXPLevel() + 10);
    // Also creates a new building soo insert constructor here
    // Has to decrement sources
}

void engineer::repair() {
    // Starts a repairing process which should take some time
    // e.g. startEvent(Repair)
    setXPLevel(getXPLevel() + 5);
    // Has to use less material than build
}

// Farmer survivor
farmer::farmer(string name = "New Farmer", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Farmer created" << endl;
}

farmer::farmer(const farmer &c): survivor(c) {
    cout << "Farmer created" << endl;
}

farmer::~farmer() {
    survivor::~survivor();
    cout << "Farmer destroyed" << endl;
}

// Other methods

void farmer::breed() {
    // Starts a breeding process which should take some time
    setXPLevel(getXPLevel() + 10);
}

void farmer::growCrops() {
    // Starts a growing crops process which should take some time
    // e.g. startEvent(Farm)
    // this paricularly sets some crops to grow in the farm land, wait a bit, then harvest them
    // and add them to inventory
    setXPLevel(getXPLevel() + 10);
}

// Hunter survivor

hunter::hunter(string name = "New Hunter", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Hunter created" << endl;
}

hunter::hunter(const hunter &c): survivor(c) {
    cout << "Hunter created" << endl;
}

hunter::~hunter() {
    survivor::~survivor();
    cout << "Hunter destroyed" << endl;
}

// Other methods

void hunter::hunt() {
    // Starts a hunting process which should take some time
}

void hunter::fendOff() {
    // Starts a fending off process which should take some time
    // Ends the 'attack event' after 'some time', loses health in the process
    setHealthLevel(getHealthLevel() - 5); 
    setXPLevel(getXPLevel() + 15);
}