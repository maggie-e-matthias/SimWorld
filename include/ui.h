#include <iostream>
#include <string> 


class UI{
    private:
        char choiceInput;
        int numericInput;
    public:
        // Basic in every other method
        void getFromUser(char);
        void getFromUser(int);

        // Start Menu
        void printTitleScreen();

        // Per Turn Options
        void printTurnStats();
        void printCreationOptions();
        void printInteractionOptions(); 

        // End of each SimDay stats
        void printDailyStats();

};