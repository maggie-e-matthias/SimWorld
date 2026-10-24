#include "include/ui.h"

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

// Handles non-zero and non-negative numeric values
int UI::getFromUserNum(){
    int input; 
    cout << "Enter a number please: ";
    do{
        cin>> input;
    }while(input > 0);
    return input;
}


void UI::printTurnStats(vector<simEntity*> world){
    // Supposed to print out all intites in the world with 
    // the option of inspecting one of them
    if(world.empty()){
        cout << "World is currently empty, might wanna start spawining things" << endl;
    }
    else{
        cout << left << setw(4) << "ID" << setw(15) << "Name" << setw(10) << "Status" << endl;
        for(int i = 0, n = world.size(); i < n; i++ ){
            cout << left << setw(4) << world[i]->getID() 
            << setw(15) << world[i]->getName() << setw(20);
            cout << (world[i]->getisActive()? "Active" : "Inactive") << endl;
        }
    }
}

void UI::printCreationOptions(){
    cout << "\nYou could spawn:" << endl;
    cout << "Survivors:" << endl; 
    cout << setw(5) << "Regular Survivor[R]\t" << setw(5) << "Doctor[D]\t" << setw(5) 
    << "Scout[S]\t" << setw(5) << "\nEngineer[E]\t" << setw(5) << "Farmer[F]\t" << setw(5) << "Hunter[H]\t" << endl;
    
}

