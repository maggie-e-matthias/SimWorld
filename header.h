#include <iostream> 

// ------ Survivor Island ------
// (Where you either make it back to civilization or die trying)


// The Base for all other entities

// non-type template parameter used as a counter for total no. of entities created 
// (despite the number of entities destroyed), the counter will serve as a unique ID generator
class simEntity{
    private: 
        int ID;
        string* name;
    public: 
        simEntity(); 
        ~simEntity();
};

// General functions

void printUI();