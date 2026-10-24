#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "base.h"
using namespace std;

// Animals class, user can spawn (create) whatever animal they want the
// survivors to breed 
class animal: public living{
    private:
    
    public:
    string* resources[3];
        animal();
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
        rabbit();
        rabbit(const rabbit &c);
        virtual ~rabbit();

        void dropResources();
        void getAction() const override;
       simEntity* clone() const override ;


}; 

// Goat class, has the ability to give milk, meat, and leather
class goat: public animal{
    private:
    vector<string> resources;
    public:
        goat();
        goat(const goat &c);
        virtual ~goat();
        
        void dropResources();
        void getAction() const override;
        simEntity* clone() const override ;
}; 

// Pigs class, drops most meat but no leather
class pig: public animal{
    private:
    vector<string> resources;
    public:
        pig();
        pig(const pig &c);
        virtual ~pig();

        void dropResources();
        void getAction() const override;
        simEntity* clone() const override ;
};
