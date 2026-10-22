#include "include/survivors.h"
#include <iostream>
#include <string>
using namespace std;

// Average survivor class, can be instantiated and has no special skills, but can be used as a base class for other survivors

// Constructors & Destructor
survivor::survivor(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): living(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick), XPLevel(0) {
    cout << "Survivor created" << endl;
}

survivor::survivor(survivor &c): living(c), XPLevel(c.XPLevel) {
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

doctor::doctor(string name = "NPC", bool isActive = true, int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100, bool isSick = false): survivor(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel, isSick) {
    cout << "Doctor created" << endl;
}

doctor::doctor(doctor &c): survivor(c) {
    cout << "Doctor created" << endl;
}

doctor::~doctor() {
    survivor::~survivor();
    cout << "Doctor destroyed" << endl;
}

// Other methods
void doctor::heal(survivor &s) {}

void doctor::makeMeds() {}

// Scout survivor
