#include "include/survivors.h"
#include <iostream>
#include <string>
using namespace std;

survivor::survivor(): living(), XPLevel(0) {
    cout << "Survivor created" << endl;
}

void survivor::getAction() const {
    // Get the action from the user
    cout << "What do you want to do? (move, attack, heal, quit): ";
}

survivor::~survivor() {
    living::~living();
    cout << "Survivor destroyed" << endl;
}