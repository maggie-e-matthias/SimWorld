#pragma once

#include <iostream>
#include <string>
#include "base.h"
using namespace std;

// Animals class, user can spawn (create) whatever animal they want the
// survivors to breed 
class animal: public living{
    public:
        animal();
        animal(animal &c);
        virtual ~animal();
        
        virtual void dropResources() = 0;
};

// Rabbit class, has minimal health and minimal meat drop
class rabbit: public animal{
    public:
        rabbit();
        rabbit(rabbit &c);
        virtual ~rabbit();

        void dropResources();
}; 

// Goat class, has the ability to give milk, meat, and leather
class goat: public animal{
    public:
        goat();
        goat(goat &c);
        virtual ~goat();
        
        void dropResources();
}; 

// Pigs class, drops most meat but no leather
class pig: public animal{
    public:
        pig();
        pig(pig &c);
        virtual ~pig();

        void dropResources();
};
