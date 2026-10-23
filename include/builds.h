#pragma once

#include <iostream>
#include <string>
#include "base.h"
using namespace std;


// Specific builds classes

// Hut class, most basic build where survivors spend the night
class hut: public builds{
    public:
        hut(string name = "New Hut", bool isActive = true, int durability = 100, int maxDurability = 100);
        hut(hut &c);
        virtual ~hut();
};

// Fence class, the main protector of survivors camp
class fence: public builds{
    public:
        fence(string name = "New Fence", bool isActive = true, int durability = 100, int maxDurability = 100);
        fence(fence &c);
        virtual ~fence();
};

// Farm class, where farmer survivors can grow crops 
class farm: public builds{
    public:
        farm(string name = "New Farm", bool isActive = true, int durability = 100, int maxDurability = 100);
        farm(farm &c);
        virtual ~farm();
};

// Storage class, where survivors can keep their resources
class storage: public builds{
    public:
        storage(string name = "New Storage", bool isActive = true, int durability = 100, int maxDurability = 100);
        storage(storage &c);
        virtual ~storage();
};

// Animal Pen class, where breeded animals can live
class animalPen: public builds{
    public:
        animalPen(string name = "New Animal Pen", bool isActive = true, int durability = 100, int maxDurability = 100);
        animalPen(animalPen &c);
        virtual ~animalPen();
};