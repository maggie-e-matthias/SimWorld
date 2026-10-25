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
    }while(input <= 0);
    return input;
}


void UI::printTurnStats(vector<simEntity*> world){
    // Supposed to print out all intites in the world with 
    // the option of inspecting one of them
    cout << "\n####################" << endl;
    if(world.empty()){
        cout << "World is currently empty, might wanna start spawining things" << endl;
    }
    else{
        cout << left << setw(4) << "Index" << setw(4) <<"ID" << setw(15) << "Name" << setw(10) << "Status" << endl;
        for(int i = 0, n = world.size(); i < n; i++ ){
            cout << left << setw(4) << i << setw(4) << world[i]->getID() 
            << setw(15) << world[i]->getName() << setw(20);
            cout << (world[i]->getisActive()? "Active" : "Inactive") << endl;
        }
        cout << "\n####################" << endl;

        cout << "Want to inspect a certain entity? [Y/N]" << endl;
        if(getFromUserChar("YN", 2) == 'Y'){
            cout << "Enter Entity's index in the world: "; 
            world.at(getFromUserNum())->getAction(); // Supposed to be replaced with stats
        }
    }  
}

void UI::printCreationOptions(){
    cout << "\n####################" << endl;
    cout << "You could spawn:" << endl;
    cout << "Survivors[S]\t" << "Animals[A]\t"<< "Builds[B]\t"<< endl;
    cout << "(Mind you, you need resources and certain survivors in order to create a build)" << endl; 
    char Choice = getFromUserChar("SAB", 3); 
    cout << "####################" << endl;
    switch (Choice){
    case 'S':
        cout << "Survivors: ";
        cout << "\nRegular Survivor[R]" << "\nDoctor[D]" << "\nScout[S]" << "\nFarmer[F]"
        << "\nEngineer[E]" << "\nHunter[H]" << endl;
        Choice = getFromUserChar("RDSFEH", 6);
        switch(Choice){
            case 'R':
            case 'D':
            case 'S':
            case 'F':
            case 'E':
            case 'H':
        }
        break;
    case 'A':
        cout << "Animals: ";
        cout << "\nRabbit[R]" << "\nGoat[G]" << "\nPig[P]" << endl;
        Choice = getFromUserChar("RPG", 3);

        break;
    case 'B':
        cout << "Builds: ";
        cout << "\nHut[H]" << "\nFence[F]" << "\nStorage[S]" << "\nFarm[R]"
        << "\nAnimal Pen[P]" << endl;
        Choice = getFromUserChar("HFSRP", 5);
        break;
    }
}

void UI::printDailyStats(vector<simEntity*> world){
    // Calculates number of survivors
    int survivorsCount = 0, totalXP = 0; 

    // Calculates number of builds
    int buildsCount = 0, campLevel = 0; 

    // Calculates number of animals
    int animalsCount = 0; 

    for(int i = 0, n = world.size(); i < n; i++){
        survivor* person = dynamic_cast<survivor*>(world[i]);

        if(person){
            survivorsCount++;
            totalXP += person->getXPLevel(); // User's general XP points
        }

        builds* building = dynamic_cast<builds*>(world[i]);

        if(building){
            buildsCount++;
            // Asseses Camp total Upgrade level based on total of upgrade levels of each build
            campLevel += building->getUpgradeLevel();
        }

        animal* pet = dynamic_cast<animal*>(world[i]);
        if(pet)
            animalsCount++;
    }

    cout << "\n####################" << endl;
    cout << "Total Survivors: " << survivorsCount << endl;; 
    cout << "Total Builds: " << buildsCount << endl;;
    cout << "Total Animals: " << animalsCount << endl;

    cout << "Your XP level: " << totalXP << endl;
    cout << "Camp level: " << campLevel << endl;
    cout << "\n####################" << endl;
}


// returns the index of entity with target ID, then the returned index can be
// used to refer to the entity through the vector with ease
// will return -1 if there are no entities with target ID or at all
int UI::findID(int targetID, vector<simEntity*> world){
    if(world.empty()){
        cout << "No entities to search for" << endl;
        return -1;
    }
    else{
        for(int i = 0, n = world.size(); i < n; i++){
            if(targetID == world[i]->getID()){
                return i;
            }
        }
        cout << "No such ID exists" << endl;
        return -1;
    }
}

// Menu and process when creating an entity
void UI::createEntity(vector<simEntity*> world){
    // Create a default entity
}

void UI::duplicateEntity(vector<simEntity*> world){
    cout << "\n####################" << endl;
    if(world.empty()){
        cout << "There are no entities to duplicate" << endl;
    }
    else{
        int index;
        do{
            cout << "Enter Enitity ID: "; 
            int dID = getFromUserNum();
            index = findID(dID, world);
        }while(index == -1);

        
    }
}
void deleteEntity(vector<simEntity*>);
void interactWithEntity(vector<simEntity*>);