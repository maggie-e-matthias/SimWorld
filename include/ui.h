#include <iostream>
#include <string> 
#include <ctime>
#include <iomanip>
#include <cctype>
using namespace std;

#include "survivors.h"
#include "builds.h"
#include "animals.h"


// UI class is a mediator class here that handles large menues, validates input properly, and interacts directly with 
// the backend of the simulation, most complex functionalities have been implemented here for ease of use in the main loop
// and to handle interaction with the 'world' and its entities

class UI{
    public:
        // Basic in every other method
        char getFromUserChar(string, int); // Validates char input and makes sure its within bounds
        int getFromUserNum();

        // Per Turn Options
        void printTurnStats(vector<simEntity*>);
        void printCreationOptions();
        void printInteractionOptions(); 

        // Utility functions
        int findID(int, vector<simEntity*>);
        //Acess to classes functions

        void createEntity(vector<simEntity*>);
        void duplicateEntity(vector<simEntity*>);
        void deleteEntity(vector<simEntity*>);
        void interactWithEntity(vector<simEntity*>);

        // End of each SimDay stats
        void printDailyStats(vector<simEntity*>);

};