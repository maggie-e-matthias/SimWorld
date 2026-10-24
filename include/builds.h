#pragma once

#include <iostream>
#include <string>
#include "base.h"
using namespace std;


// Specific builds classes

// Hut class, most basic build where survivors spend the night


template <int N>
class hut: public builds<N>{
    private:
        int noOfBeds; // Number of spaces for survivors to sleep in the hut
        int maxBeds;
    public:
        hut(string name = "New Hut", bool isActive = true, int durability = 50, int maxDurability = 50);
        hut(const hut &c);
        virtual ~hut();

        int getNoOfBeds() const;
        void setNoOfBeds(int);
        int getMaxBeds() const;
        
        // Though maxBeds seems like it should be a constant, it is not
        // as the player can upgrade the build to hold more players
        void setMaxBeds(int); 
        

        void getAction() const override;
};

// Fence class, the main protector of survivors camp
template <int N>
class fence: public builds<N>{
    public:
        fence(string name = "New Fence", bool isActive = true, int durability = 50, int maxDurability = 50);
        fence(const fence &c);
        virtual ~fence();

        void getAction() const override;
};

// Farm class, where farmer survivors can grow crops 

template <int N>
class farm: public builds<N>{
    public:
        farm(string name = "New Farm", bool isActive = true, int durability = 30, int maxDurability = 30);
        farm(const farm &c);
        virtual ~farm();

        void getAction() const override;
};

// Storage class, where survivors can keep their resources

template <int N>
class storage: public builds<N>{
    private:
        vector<item> storageSpaces;
        int maxStorageSpace; 
    public:
        storage(string name = "New Storage", bool isActive = true, int durability = 50, int maxDurability = 50, int maxStorageSpace = 50);
        storage(const storage &c);
        virtual ~storage();

        // Same as inventory methods for player
        void addToStorage(item);
        bool isStorageEmpty() const; 
        vector<item> getStorage() const;
        int findInStorage(item);
        item getFromStorage(item); //Same as useFromInventory except that the item needs to be returned for transfer

        // Though maxStorageSpace seems like it should be a constant, it is not
        // as the player can upgrade the build to hold more storage space
        void setMaxStorageSpace(int);
        int getMaxStorageSpace() const;

        void getAction() const override;
};

// Animal Pen class, where breeded animals can live
template <int N>
class animalPen: public builds<N>{
    private:
        vector<living*> animalsInPen;
        int maxAnimalsInPen;
    public:
        animalPen(string name = "New Animal Pen", bool isActive = true, int durability = 40, int maxDurability = 40);
        animalPen(const animalPen &c);
        virtual ~animalPen();

        // Almost same methods as inventory and storage methods to get animals in and out of the pen

        void addAnimalToPen(living*);
        bool isPenEmpty() const;
        vector<living*> getAnimalsInPen() const;
        int findAnimalInPen(living*);
        living* getAnimalFromPen(int);

        // Though maxAnimals seems like it should be a constant, it is not
        // as the player can upgrade the build to hold more animals
        void setMaxAnimalsInPen(int);
        int getMaxAnimalsInPen() const;

        void getAction() const override;
};