#include <iostream>
#include <string> 
#include <ctime>
#include <iomanip>
#include <cctype>
using namespace std;

#include "survivors.h"
#include "builds.h"
#include "animals.h"
// UI has been implemented as a class to encapsulate all functions called during the loop
// and separate them from the logic of the loop

class UI{
    public:
        // Basic in every other method
        char getFromUserChar(string, int); // Validates char input and makes sure its within bounds
        int getFromUserNum();

        // Per Turn Options
        void printTurnStats(vector<simEntity*>);
        void printCreationOptions();
        void printInteractionOptions(); 

        // End of each SimDay stats
        void printDailyStats(vector<simEntity*>);

};