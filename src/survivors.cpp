#include "include/survivors.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Average survivor class, can be instantiated and has no special skills, but can be used as a base class for other survivors

// Constructors & Destructor

// Attributes inherited from living class (e.g. health level, hunger level, etc..) are set to their default values
// that are listed in base.h, since the survivors do work with these particular values (like maxHealthLevel = 100 not less),
// these values will not be overridden
survivor::survivor(string name, bool isActive, int maxInventorySize): living(name, isActive), XPLevel(0), maxInventorySize(maxInventorySize) {
    cout << "Survivor created" << endl;
}

survivor::survivor(const survivor &c): living(c), XPLevel(c.XPLevel), maxInventorySize(c.maxInventorySize) {
    cout << "Survivor created" << endl;
}

survivor::~survivor() {
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
    // Still unsure of what the implementation should be
    // Perhaps (somehow) return the action they have done for
    // this turn
}

// Inventory methods

void survivor::addToInventory(item I){
    if(inventory.size() == maxInventorySize){ // Has to check if it's full
        cout << "Sorry, " << this->getName() << "'s inventory is full" << endl;
    }
    else{
        this->inventory.push_back(I);
    }   
}

bool survivor::isInventoryEmpty() const{
    return inventory.empty();
}

// This returns the entire survivor's inventory, not sure how this is useful yet
vector<item> survivor::getInventory() const{
    return this->inventory;
}

// Finds an item in survivor inventory and returns its index
// If item doesn't exist, it returns -1
int survivor::findInInventory(item I){
   for(int i = 0, n = inventory.size(); i < n; i++){
        if(I == inventory[i]){
            return i;
        }
   }
   return -1;
}

// Double check for if item not found
void survivor::useFromInventory(item I){
    if(inventory.empty()){
        cout << "Inventory is empty!" << endl;
    }
    else{
        int tempIndex = findInInventory(I);
        if(tempIndex == -1){
            cout << "Sorry, the item you're trying to use doesn't exist" << endl;
        }
        else{
            inventory.erase(inventory.begin() + tempIndex); 
        }
    }
}


// Doctor survivor

// Constructors & Destructor

doctor::doctor(string name, bool isActive): survivor(name, isActive) {
    cout << "Doctor created" << endl;
}

doctor::doctor(const doctor &c): survivor(c) {
    cout << "Doctor created" << endl;
}

doctor::~doctor() {
    cout << "Doctor destroyed" << endl;
}

// Other methods
void doctor::heal(survivor &s) {
    // Some heal effect
    if(s.getHealthLevel() < s.getMaxHealthLevel()) {

        if(findInInventory(MEDS) == -1){
            cout << "Not enough Meds" << endl;
        }
        else{
            s.setHealthLevel(s.getMaxHealthLevel());
            cout << "Healed " << *s.getName() << endl;

            setXPLevel(getXPLevel() + 10); // Increase XP level for healing
            // Needs to decrement the meds (consume them)
            useFromInventory(MEDS);
        }  
    }
    else{
        cout << s.getName() << " is already at full health!" << endl;
    }


}

void doctor::makeMeds(){
    // Starts a process of making meds, should take some time
    addToInventory(MEDS);
    setXPLevel(getXPLevel() + 5); // Increase XP level for making meds
}

// Scout survivor

// Constructors & Destructor

// The scout survivor has an extended inventory since their special skill is
// to gather more sources than other survivors
scout::scout(string name, bool isActive): survivor(name, isActive, 20) {
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

engineer::engineer(string name, bool isActive): survivor(name, isActive) {
    cout << "Engineer created" << endl;
}

engineer::engineer(const engineer &c): survivor(c) {
    cout << "Engineer created" << endl;
}

engineer::~engineer() {
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
farmer::farmer(string name, bool isActive): survivor(name, isActive) {
    cout << "Farmer created" << endl;
}

farmer::farmer(const farmer &c): survivor(c) {
    cout << "Farmer created" << endl;
}

farmer::~farmer() {
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

hunter::hunter(string name, bool isActive): survivor(name, isActive) {
    cout << "Hunter created" << endl;
}

hunter::hunter(const hunter &c): survivor(c) {
    cout << "Hunter created" << endl;
}

hunter::~hunter() {
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