#include "include/builds.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hut Class, where players sleep overnight to avoid getting health damage over time

// Constructors and destructor

hut::hut(string name, bool isActive, int durability, int maxDurability, int noOfBeds, int maxBeds): 
builds(name, isActive, durability, maxDurability, {item::WOOD, item::STONE}, item::STONE, {"shelter", "rest"}),
noOfBeds(noOfBeds), maxBeds(maxBeds) {
    cout << "Hut created" << endl;
}

hut::hut(const hut &c): builds(c), noOfBeds(c.noOfBeds), maxBeds(c.maxBeds) {
    cout << "Hut created" << endl;
}

hut::~hut() {
    cout << "Hut destroyed" << endl;
}

// Getters and setters 

int hut::getNoOfBeds()const{
    return noOfBeds;
}

void hut::setNoOfBeds(int beds){
    noOfBeds = beds;
}

int hut::getMaxBeds() const{
    return maxBeds;
}

void hut::getAction() const {
    cout << "The hut provides shelter and a place to rest." << endl;
}

simEntity* hut::clone() const {
    return new hut(*this);
}

// Fence class, the main build that protects survivors from outside dangers

// Constructors and Destructors

fence::fence(string name, bool isActive, int durability, int maxDurability):
builds(name, isActive, durability, maxDurability, {item::WOOD, item::WOOD}, item::METAL, {"protection", "camp boundary"} ) {
    cout << "Fence created" << endl;
}

fence::fence(const fence &c): builds(c) {
    cout << "Fence created" << endl;
}

fence::~fence() {
    cout << "Fence destroyed" << endl;
}

void fence::getAction() const {
    cout << "The fence protects the survivors' camp." << endl;
}

simEntity* fence::clone() const {
    return new fence(*this);
}

// Farm Class

// Constructors and Destructors

farm::farm(string name, bool isActive, int durability, int maxDurability):
builds(name, isActive, durability, maxDurability, {item::WOOD, item::WATER, item::STONE}, item::WATER, {"crops", "food production"}) {
    cout << "Farm created" << endl;
}

farm::farm(const farm &c): builds(c) {
    cout << "Farm created" << endl;
}


farm::~farm() {
    cout << "Farm destroyed" << endl;
}

void farm::getAction() const {
    cout << "The farm is used to grow crops." << endl;
}

simEntity* farm::clone() const {
    return new farm(*this);
}

// Storage Class 

storage::storage(string name, bool isActive, int durability, int maxDurability): 
builds(name, isActive, durability, maxDurability, {item::LEATHER, item::WOOD, item::METAL}, item::METAL, {"resource storage", "supplies"}), 
maxStorageSpace(50){
    cout << "Storage created" << endl;
}


storage::storage(const storage &c): builds(c), maxStorageSpace(c.maxStorageSpace), storageSpaces(c.storageSpaces) {
    cout << "Storage created" << endl;
}


storage::~storage() {
    cout << "Storage destroyed" << endl;
}


void storage::addToStorage(item I){
    if(storageSpaces.size() == maxStorageSpace){ // Has to check if it's full
        cout << "Sorry, " << this->getName() << "'s storage is full" << endl;
    }
    else{
        this->storageSpaces.push_back(I);
    }   
}


bool storage::isStorageEmpty() const{
    return storageSpaces.empty();
}

// This returns the entire survivor's inventory, not sure how this is useful yet

vector<item> storage::getStorage() const{
    return this->storageSpaces;
}

// Finds an item in survivor inventory and returns its index
// If item doesn't exist, it returns -1


int storage::findInStorage(item I){
   for(int i = 0, n = storageSpaces.size(); i < n; i++){
        if(I == storageSpaces[i]){
            return i;
        }
   }
   return -1;
}

// Double check for if item not found

item storage::getFromStorage(item I){
    if(storageSpaces.empty()){
        cout << "Storage is empty!" << endl;
        return item::NONE;
    }
    else{
        int tempIndex = findInStorage(I);
        if(tempIndex == -1){
            return item::NONE;
        }
        else{
            storageSpaces.erase(storageSpaces.begin() + tempIndex);
            return I;
        }
    }
}

void storage::getAction() const {
    cout << "The storage keeps the island's resources safe." << endl;
}

simEntity* storage::clone() const {
    return new storage(*this);
}


// Animal Pen

animalPen::animalPen(string name, bool isActive, int durability, int maxDurability): 
builds(name, isActive, durability, maxDurability, {item::WOOD, item::STONE, item::LEATHER}, item::STONE, {"animal shelter", "breeding area"}) {
    cout << "Animal Pen created" << endl;
}

animalPen::animalPen(const animalPen &c): builds(c) {
    cout << "Animal Pen created" << endl;
}

animalPen::~animalPen() {
    cout << "Animal Pen destroyed" << endl;
}

void animalPen::addAnimalToPen(living* animal){
    if(animalsInPen.size() == maxAnimalsInPen){ // Has to check if it's full
        cout << "Sorry, " << this->getName() << "'s storage is full" << endl;
    }
    else{
        this->animalsInPen.push_back(animal);
    }   
}


bool animalPen::isPenEmpty() const{
    return animalsInPen.empty();
}

// This returns the entire survivor's inventory, not sure how this is useful yet

vector<living*> animalPen::getAnimalsInPen() const{
    return this->animalsInPen;
}

// Finds an item in survivor inventory and returns its index
// If item doesn't exist, it returns -1


int animalPen::findAnimalInPen(living* animal){
   for(int i = 0, n = animalsInPen.size(); i < n; i++){
        if(animal == animalsInPen[i]){
            return i;
        }
   }
   return -1;
}

// Double check for if item not found

// living* animalPen::getAnimalFromPen(int I){
//     if(storageSpaces.empty()){
//         cout << "Storage is empty!" << endl;
//         return nullptr;
//     }
//     else{
//         int tempIndex = findAnimalInPen(I);
//         if(tempIndex == -1){
//             return nullptr;
//         }
//         else{
//             storageSpaces.erase(storageSpaces.begin() + tempIndex);
//             return I;
//         }
//     }
// }


void animalPen::getAction() const {
    cout << "The animal pen provides a place for animals to live." << endl;
}

simEntity* animalPen::clone() const {
    return new animalPen(*this);
}
