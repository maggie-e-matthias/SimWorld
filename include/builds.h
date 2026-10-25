#pragma once // To solve the issue of multiple includes
#include "include/base.h"

using namespace std;


// Hut: a shelter where survivors can spend the night.
class hut : public builds {
private:
        vector<string> features;
        int noOfBeds; // Number of spaces for survivors to sleep in the hut
        int maxBeds;
    public:
        hut(string name = "New Hut", bool isActive = true, int durability = 50, int maxDurability = 50,
        int noOfBeds = 2, int maxBeds = 4);
        hut(const hut &c);
        ~hut() override;

        int getNoOfBeds() const;
        void setNoOfBeds(int);
        int getMaxBeds() const;
        
        // Though maxBeds seems like it should be a constant, it is not
        // as the player can upgrade the build to hold more players
        void setMaxBeds(int); 
        

        void getStats() const override;
        simEntity* clone() const override;
};


// Fence class, the main protector of survivors camp

class fence: public builds{
    public:
        fence(string name = "New Fence", bool isActive = true, int durability = 50, int maxDurability = 50);
        fence(const fence &c);
        ~fence() override;

        void getStats() const override;
        simEntity* clone() const override;
};


// Farm class, where farmer survivors can grow crops 

class farm: public builds{
    public:
        farm(string name = "New Farm", bool isActive = true, int durability = 30, int maxDurability = 30);
        farm(const farm &c);
        ~farm() override;

        void getStats() const override;
        simEntity* clone() const override;
};


// Storage class, where survivors can keep their resources

class storage: public builds{
    private:
        vector<item> storageSpaces;
        int maxStorageSpace; 
    public:
        storage(string name = "New Storage", bool isActive = true, int durability = 50, int maxDurability = 50);
        storage(const storage &c);
        ~storage() override;

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

        void getStats() const override;
        simEntity* clone() const override;
};


// Animal Pen class, where breeded animals can live
class animalPen: public builds{
    private:
        vector<living*> animalsInPen;
        int maxAnimalsInPen;
    public:
        animalPen(string name = "New Animal Pen", bool isActive = true, int durability = 40, int maxDurability = 40);
        animalPen(const animalPen &c);
        ~animalPen() override;

        // Almost same methods as inventory and storage methods to get animals in and out of the pen

        void addAnimalToPen(living*);
        bool isPenEmpty() const;
        vector<living*> getAnimalsInPen() const;
        int findAnimalInPen(living*);
        // living* getAnimalFromPen();

        // Though maxAnimals seems like it should be a constant, it is not
        // as the player can upgrade the build to hold more animals
        void setMaxAnimalsInPen(int);
        int getMaxAnimalsInPen() const;

        void getStats() const override;
        simEntity* clone() const override;
};
