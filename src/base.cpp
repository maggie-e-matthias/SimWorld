#include "include/base.h"
#include <iostream>
#include <string>

simEntity::simEntity(){
    count++;
    ID = count;
    name = new string("Default");
    isActive = true;
    daysItLasted = 0;
}