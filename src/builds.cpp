#include "include/builds.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

hut::hut(string name, bool isActive, int durability, int maxDurability): builds(durability, maxDurability) {
    this->setName(name);
    this->setActive(isActive);
    cout << "Hut created" << endl;
}

hut::hut(hut &c): builds(c) {
    cout << "Hut created" << endl;
}

hut::~hut() {
    cout << "Hut destroyed" << endl;
}

fence::fence(string name, bool isActive, int durability, int maxDurability): builds(durability, maxDurability) {
    this->setName(name);
    this->setActive(isActive);
    cout << "Fence created" << endl;
}

fence::fence(fence &c): builds(c) {
    cout << "Fence created" << endl;
}

fence::~fence() {
    cout << "Fence destroyed" << endl;
}

farm::farm(string name, bool isActive, int durability, int maxDurability): builds(durability, maxDurability) {
    this->setName(name);
    this->setActive(isActive);
    cout << "Farm created" << endl;
}

farm::farm(farm &c): builds(c) {
    cout << "Farm created" << endl;
}

farm::~farm() {
    cout << "Farm destroyed" << endl;
}

storage::storage(string name, bool isActive, int durability, int maxDurability): builds(durability, maxDurability) {
    this->setName(name);
    this->setActive(isActive);
    cout << "Storage created" << endl;
}

storage::storage(storage &c): builds(c) {
    cout << "Storage created" << endl;
}

storage::~storage() {
    cout << "Storage destroyed" << endl;
}

animalPen::animalPen(string name, bool isActive, int durability, int maxDurability): builds(durability, maxDurability) {
    this->setName(name);
    this->setActive(isActive);
    cout << "Animal Pen created" << endl;
}

animalPen::animalPen(animalPen &c): builds(c) {
    cout << "Animal Pen created" << endl;
}

animalPen::~animalPen() {
    cout << "Animal Pen destroyed" << endl;
}