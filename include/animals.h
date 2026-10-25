#pragma once
#include "base.h"
using namespace std;

// Animals class, user can spawn (create) whatever animal they want the
// survivors to breed 
class animal: public living{
    private:
        vector<item> resources;
    public:
        animal(string name = "New Animal", bool isActive = true, vector<item> resources = {item::MEAT}, 
        int healthLevel = 100, int maxHealthLevel = 100, int hungerLevel = 100, int maxHungerLevel = 100);
        animal(const animal &c);
        virtual ~animal();
        
        virtual void dropResources() = 0;
        simEntity* clone() const override = 0;


};

// Rabbit class, has minimal health and minimal meat drop
class rabbit: public animal{
    private:
    vector<string> resources;
    public:
        rabbit(string name = "New Rabbit", bool isActive = true);
        rabbit(const rabbit &c);
        virtual ~rabbit();

        void dropResources() override;
        void getStats() const override;
        simEntity* clone() const override ;


}; 

// Goat class, has the ability to give milk, meat, and leather
class goat: public animal{
    private:
    vector<string> resources;
    public:
        goat(string name = "New Goat", bool isActive = true);
        goat(const goat &c);
        virtual ~goat();
        
        void dropResources() override;
        void getStats() const override;
        simEntity* clone() const override ;
}; 

// Pigs class, drops most meat but no leather
class pig: public animal{
    private:
    vector<string> resources;
    public:
        pig(string name = "New Pig", bool isActive = true);
        pig(const pig &c);
        virtual ~pig();

        void dropResources() override;
        void getStats() const override;
        simEntity* clone() const override ;
};
