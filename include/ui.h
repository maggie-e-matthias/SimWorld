#include <iostream>
#include <string> 
#include <ctime>
#include <iomanip>
using namespace std;

// UI has been implemented as a class to encapsulate all functions called during the loop
// and separate them from the logic of the loop

class UI{
    public:
        // Basic in every other method
        char getFromUserChar(string, int); // Validates char input and makes sure its within bounds
        int getFromUserNum();

        // Start Menu
        void printTitleScreen();

        // Per Turn Options
        void printTurnStats();
        void printCreationOptions();
        void printInteractionOptions(); 

        // End of each SimDay stats
        void printDailyStats();

        void setchoiceInput(char);
        void setnumericInput(int);

};