#include "include/ui.h"
#include <iostream>
#include <string> 
#include <iomanip>
#include <cctype>
using namespace std;

// Handles char input and validates it as well, all compacted in one line
// A parameter of type string was used for bounds to accept input of either on single possibility
// e.g. S in start menu, or multiple choices 
char UI::getFromUserChar(string bounds, int size){
    char Choice;
    bool withinBounds = false;
    cout << "Enter your choice: ";
    do{
        cin >> Choice;
        // Makes sure it's within bounds
        for(int i = 0; i < size; i++){
            if(toupper(Choice) == bounds[i]){
                withinBounds = true; 
                break;
            }
        }
    }while(!withinBounds);

    return toupper(Choice);
}

int UI::getFromUserNum(){
    int input; 
    cout << "Enter a number please: ";
    do{
        cin>> input;
    }while(input > 0);
    return input;
}

void UI::printTitleScreen(){
    cout << "------ Survivor Island Simulator ------" << endl;
    cout << "-------------- Start[S] ---------------" << endl;
}

void UI::printCreationOptions(){
    cout << "\nYou could spawn:" << endl;
    cout << "Survivors:" << endl; 
    cout << setw(5) << "Regular Survivor[R]\t" << setw(5) << "Doctor[D]\t" << setw(5) 
    << "Scout[S]\t" << setw(5) << "\nEngineer[E]\t" << setw(5) << "Farmer[F]\t" << setw(5) << "Hunter[H]\t" << endl;
    
}

