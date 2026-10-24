#include <iostream>
#include <string> 
#include <ctime>
#include <iomanip>
using namespace std;

// UI has been implemented as a class to encapsulate all functions called during the loop
// and separate them from the logic of the loop

class UI{
    private:
        char choiceInput; // For choosing between options
        int numericInput; // For getting a numeric input
    public:
        // Basic in every other method
        void getFromUserChar();
        void getFromUserNum();

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