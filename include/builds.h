#pragma once

#include <iostream>
#include <string>
#include "base.h"
using namespace std;


// Specific builds classes

// Hut class, most basic build where survivors spend the night
class hut: public builds{
    public:
        hut();
        hut(hut &c);
        virtual ~hut();
};

// Fence class, the main protector of survivors camp
class fence: public builds{
    public:
        fence();
        fence(fence &c);
        virtual ~fence();
};

// Farm class, where farmer survivors can grow crops 
class farm: public builds{
    public:
        farm();
        farm(farm &c);
        virtual ~farm();
};

// Storage class, where survivors can keep their resources
class storage: public builds{
    public:
        storage();
        storage(storage &c);
        virtual ~storage();
};

// Animal Pen class, where breeded animals can live
class animalPen: public builds{
    public:
        animalPen();
        animalPen(animalPen &c);
        virtual ~animalPen();
};