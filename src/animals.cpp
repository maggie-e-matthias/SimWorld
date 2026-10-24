
#include <iostream>
#include <string>
#include "include/animals.h"

using namespace std;

// ANIMAL 

animal::animal() : living() {
}

animal::animal(const animal& c) : living(c) {
}

animal::~animal() {
}

//  RABBIT

rabbit::rabbit()
    : animal(), resources({"meat", "fur"}) {
}

rabbit::rabbit(const rabbit& c)
    : animal(c), resources(c.resources) {
}

rabbit::~rabbit() {
}

void rabbit::getAction() const {
    cout << "The rabbit is moving around the island." << endl;
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
goat::goat()
    : animal(), resources({"meat", "milk", "hide"}) {
}

goat::goat(const goat& c)
    : animal(c), resources(c.resources) {
}

goat::~goat() {
}

void goat::getAction() const{
    cout << "The goat is grazing on the island." << endl;
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

pig::pig()
    : animal(), resources({"meat", "fat", "hide"}) {
}

pig::pig(const pig& c)
    : animal(c), resources(c.resources) {
}

pig::~pig() {
}

void pig::getAction() const {
    cout << "The pig is searching for food on the island." << endl;
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
