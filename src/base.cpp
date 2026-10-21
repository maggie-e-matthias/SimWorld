#include "include/base.h"
#include <iostream>
#include <string>
using namespace std;

int simEntity::count = 0;

simEntity::simEntity(){
    count++;
    ID = count;
    name = new string("Default");
    isActive = true;
    daysItLasted = 0;
}

simEntity::~simEntity() {
    delete name;
    cout << "simEntity destroyed" << endl;
}

living::living(): simEntity(), healthLevel(100), maxHealthLevel(100), isSick(false) {
    cout << "Living entity created" << endl;
    
}

living::~living() {
    simEntity::~simEntity();
    cout << "Living entity destroyed" << endl;
}