#include "include/builds.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hut Class, where players sleep overnight to avoid getting health damage over time

// Constructors and destructor

template <int N>
hut<N>::hut(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::STONE}; // list of materials required to finish making the building
    this->upgradeRequirements = item::STONE;
    cout << "Hut created" << endl;
}

template <int N>
hut<N>::hut(const hut<N> &c): builds(c) {
    cout << "Hut created" << endl;
}

template <int N>
hut<N>::~hut() {
    cout << "Hut destroyed" << endl;
}

// Getters and setters 

template <int N>
int hut<N>::getNoOfBeds()const{
    return noOfBeds;
}

template <int N>
void hut<N>::setNoOFBeds(int beds){
    noOFBeds = beds;
}

template <int N>
int hut<N>::getMaxBeds() const{
    return maxBeds;
}


// Fence class, the main build that protects survivors from outside dangers

// Constructors and Destructors

template <int N>
fence<N>::fence(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::WOOD};
    this->upgradeRequirements = item::METAL;
    cout << "Fence created" << endl;
}

template <int N>
fence<N>::fence(const fence<N> &c): builds(c) {
    cout << "Fence created" << endl;
}


template <int N>
fence<N>::~fence() {
    cout << "Fence destroyed" << endl;
}

template <int N>
farm<N>::farm(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequriements[] = {item::WOOD, item::WATER, item::STONE};
    this->upgradeRequirements = item::WATER;
    cout << "Farm created" << endl;
}

template <int N>
farm<N>::farm(const farm<N> &c): builds(c) {
    cout << "Farm created" << endl;
}

template <int N>
farm<N>::~farm() {
    cout << "Farm destroyed" << endl;
}

template <int N>
storage<N>::storage(string name, bool isActive, int durability, int maxDurability, int maxStorageSpace): builds(name, isActive, durability, maxDurability), maxStorageSpace {
    this->buildRequirements[] = {item::LEATHER, item::WOOD, item::METAL};
    this->upgradeRequirements = item::METAL;
    cout << "Storage created" << endl;
}

template <int N>
storage<N>::storage(const storage<N> &c): builds(c) {
    cout << "Storage created" << endl;
}

template <int N>
storage<N>::~storage() {
    cout << "Storage destroyed" << endl;
}

template <int N>
void storage<N>::addToStorage(item I){
    if(storageSpaces.size() == maxStorageSpace){ // Has to check if it's full
        cout << "Sorry, " << this->getName() << "'s storage is full" << endl;
    }
    else{
        this->storageSpaces.push_back(I);
    }   
}

template <int N>
bool storage<N>::isStorageEmpty() const{
    return storageSpaces.empty();
}

// This returns the entire survivor's inventory, not sure how this is useful yet

template <int N>
vector<item> storage<N>::getStorage() const{
    return this->storageSpaces;
}

// Finds an item in survivor inventory and returns its index
// If item doesn't exist, it returns -1

template <int N>
int storage<N>::findInStorage(item I){
   for(int i = 0, n = storageSpaces.size(); i < n; i++){
        if(I == storageSpaces[i]){
            return i;
        }
   }
   return -1;
}

// Double check for if item not found

template <int N>
item storage<N>::getFromStorage(item I){
    if(storageSpaces.empty()){
        cout << "Storage is empty!" << endl;
    }
    else{
        int tempIndex = findInInventory(I);
        if(tempIndex == -1){
            return item::NONE;
        }
        else{
            inventory.erase(inventory.begin() + tempIndex);
            return I 
        }
    }
}

template <int N>
animalPen<N>::animalPen(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::STONE, item::LEATHER};
    this->upgradeRequirements = item::STONE;
    cout << "Animal Pen created" << endl;
}

template <int N>
animalPen<N>::animalPen(const animalPen<N> &c): builds(c) {
    cout << "Animal Pen created" << endl;
}

template <int N>
animalPen<N>::~animalPen() {
    cout << "Animal Pen destroyed" << endl;
}