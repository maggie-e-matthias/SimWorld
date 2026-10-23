/*
    Authors: 
    - Magdoleen Matthias 900152595
    - Hanan Elnakeeb 900253826

        ------ Survivor Islan Simulator ------
    Where you either make it back to civilization or die trying!

*/


#include "include/survivors.h"
#include "include/builds.h"
#include "include/animals.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

// Main simulation loop will live here

int main(){
    // Collection of all entities in the simulation
    vector<simEntity*> entities;

    // Add simulation code

    survivor s1 = survivor();
    s1.getAction();
    
    return 0;
}