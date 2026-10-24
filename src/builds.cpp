
#include <iostream>
#include <string>
#include "include/builds.h"

using namespace std;
//HUT 

hut::hut()
    : builds(), features({"shelter", "rest"}) {
}

hut::hut(const hut& c)
    : builds(c), features(c.features) {
}

hut::~hut() {
}

void hut::getAction() const {
    cout << "The hut provides shelter for survivors." << endl;
}

simEntity* hut::clone() const {
    return new hut(*this);
}


// FENCE 

fence::fence()
    : builds(), features({"protection", "camp boundary"}) {
}

fence::fence(const fence& c)
    : builds(c), features(c.features) {
}

fence::~fence() {
}

void fence::getAction() const {
    cout << "The fence protects the survivors' camp." << endl;
}

simEntity* fence::clone() const {
    return new fence(*this);
}


// FARM 

farm::farm()
    : builds(), features({"crops", "food production"}) {
}

farm::farm(const farm& c)
    : builds(c), features(c.features) {
}

farm::~farm() {
}

void farm::getAction() const {
    cout << "The farm is used to grow crops." << endl;
}

simEntity* farm::clone() const {
    return new farm(*this);
}


//  STORAGE

storage::storage()
    : builds(), features({"resource storage", "supplies"}) {
}

storage::storage(const storage& c)
    : builds(c), features(c.features) {
}

storage::~storage() {
}

void storage::getAction() const {
    cout << "The storage keeps the island's resources safe." << endl;
}

simEntity* storage::clone() const {
    return new storage(*this);
}


//  ANIMAL PEN 

animalPen::animalPen()
    : builds(), features({"animal shelter", "breeding area"}) {
}

animalPen::animalPen(const animalPen& c)
    : builds(c), features(c.features) {
}

animalPen::~animalPen() {
}

void animalPen::getAction() const {
    cout << "The animal pen provides a place for animals to live." << endl;
}

simEntity* animalPen::clone() const {
    return new animalPen(*this);
}
