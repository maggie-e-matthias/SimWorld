#include "include/animals.h"

using namespace std;

// ANIMAL 

animal::animal(string name, bool isActive, vector<item> resources, int healthLevel, int maxHealthLevel, int hungerLevel, int maxHungerLevel) : 
living(name, isActive, healthLevel, maxHealthLevel, hungerLevel, maxHungerLevel), resources(resources) {
}

animal::animal(const animal& c) : living(c), resources(c.resources) {
}

animal::~animal() {
}

//  RABBIT

rabbit::rabbit(string name, bool isActive): animal(name, isActive, {item::MEAT, item::LEATHER}), resources({"meat", "fur"}){
    cout << "Rabbit Spawned" << endl;
}

rabbit::rabbit(const rabbit& c):animal(c), resources(c.resources) {
}

rabbit::~rabbit() {
    cout << "Rabbit Died" << endl;
}

void rabbit::getStats() const {
    cout << "Name: " << *(this->getName()) << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Health Level: " << this->getHealthLevel() << endl;
    cout << "Hunger Level: " << this ->getHungerLevel() << endl;
}

void rabbit::dropResources() {
    cout << "The rabbit drops: ";

    for (int i = 0; i < resources.size(); i++) {
        cout << resources[i];

        if (i < resources.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

simEntity* rabbit::clone() const {
    return new rabbit(*this);
}


// GOAT 
goat::goat(string name, bool isActive):animal(name, isActive, {item::MEAT, item::MILK, item::LEATHER}), resources({"meat", "milk", "leather"}){
    cout << "Goat Spawned" << endl;
}

goat::goat(const goat& c): animal(c), resources(c.resources) {
}

goat::~goat() {
    cout << "Goat Died" << endl;
}

void goat::getStats() const{
    cout << "Name: " << *(this->getName()) << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Health Level: " << this->getHealthLevel() << endl;
    cout << "Hunger Level: " << this ->getHungerLevel() << endl;
}

void goat::dropResources() {
    cout << "The goat drops: ";

    for (int i = 0; i < resources.size(); i++) {
        cout << resources[i];

        if (i < resources.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

simEntity* goat::clone() const {
    return new goat(*this);
}

// PIG 

pig::pig(string name, bool isActive):animal(name, isActive, {item::MEAT, item::MEAT, item::LEATHER}), resources({"meat", "meat", "leather"}){
    cout << "Pig Spawned" << endl;
}

pig::pig(const pig& c): animal(c), resources(c.resources) {
}

pig::~pig() {
    cout << "Pig Died" << endl;
}

void pig::getStats() const {
    cout << "Name: " << *(this->getName()) << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Health Level: " << this->getHealthLevel() << endl;
    cout << "Hunger Level: " << this ->getHungerLevel() << endl;
}

void pig::dropResources() {
    cout << "The pig drops: ";

    for (int i = 0; i < resources.size(); i++) {
        cout << resources[i];

        if (i < resources.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

simEntity* pig::clone() const {
    return new pig(*this);
}
