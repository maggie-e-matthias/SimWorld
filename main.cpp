/*
    Authors: 
    - Magdoleen Matthias 900152595
    - Hanan Elnakeeb 900253826

        ------ Survivor Island Simulator ------
    Could you survive for the longest time possible without killing
    all the survivors on island?

    Sim Description:
        - Basically, you start on an empty island and start to create survivors on it, your goal is to try and
        survive for the longest period possible without getting all the survivors killed 

        - Once the simulation starts, the player can take a certain number of turns per a game day, after the turns end, 
        they're asked if they want to take more turns, if so, they get to take some more, if not, the day ends and they get a 
        board of all game stats, then they're asked whether they want to proceed to the following day or quit the game

    Class Design overview:
    Features:
    Insructions for running: 
        Running requirements: CMake v3.16 or higher, MinGW as your compiler

        If you're recieving this program as part of an assignemnt, you should have recieved:
            /include
            /src
            CMakeLists.txt
            simulation.cpp (which is supposedly our main file)
        
        So, 

        For Windows: 
            1. Create a directory for build:
                ```bash
                mkdir build
                cd build
                ```
            2. Run these CMake commands:
                ```bash
                cmake -G "MinGW Makefiles" ..
                cmake --build .
                ```
            3. Run the simulation:
                ```bash
                ./sim.exe
                ```
        For Linux: (Assuming that you're using something similar to the docker image ubuntu_plus_buildtools)
            1. Create a directory for build:
                ```bash
                mkdir build
                cd build
                ```
            2. Run these CMake commands:
                ```bash
                cmake ..
                make .
                ```
            3. Run the simulation:
                ```bash
                .\sim
                ```
    AI usage:

*/


#include "include/survivors.h"
#include "include/builds.h"
#include "include/animals.h"
#include "include/ui.h"
#include "include/event.h"
#include "include/Stack.h"
#include "include/Queue.h"
#include "include/undo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

// Main simulation loop will live here

int main(){
    // Initialize all in game objects
    UI ui; 
    vector<simEntity*> World; // The container for all entities
    //Stack<vector<simEntity*>> History; // For undo purposes
    
    EventManager manager;

    // Initialize all variables
    int inGameDays = 0, currentTurns = 0, numChoice; // Last one is for numeric choices
    bool GameOn; // Flag for starting the game
    bool moreTurns = false; // Flag for taking more turns if user wants to
    char Choice; // For choosing from menu options

    
    // Starting Menu
    cout << "------ Survivor Island Simulator ------" << endl;
    cout << "-------------- Start[S] ---------------" << endl;
    Choice = ui.getFromUserChar("S", 1);
    if(Choice == 'S')
        GameOn = true;

    // The sim follows two main cycles, turns per day, and events per turn, 
    // The per day cycle may contain one or more turns, and prints daily stats at the end of each day,
    // and is represented in the while(GameOn) loop
    // The per turn cylce prints out current stats for all entities, and gives user the chance to pick one action

    while(GameOn){
        inGameDays++; 
        cout << "\n####################\n";
        cout << "Day #" << inGameDays;
        cout << "\n####################\n";

        cout << "How many turns do you wanna take? >> "; 
        currentTurns = ui.getFromUserNum();

        do{
        //Starts the per turn cycle
        for(int j = 1; j <= currentTurns; j++){
            // Every turn, the world status is printed out
            ui.printTurnStats(World);

            // Let the user choose an operation
            cout << "\nYou could: \n" << "Spawn a new Entity[N]\t"
            << "Duplicate an already existing one[D]\t" << "Remove an entity[R]" << endl;
            cout << "Or you can interact with any existing entity[I] " << endl;
            cout << "\nWhat's your pick? >> "; 
            Choice = ui.getFromUserChar("NDRI", 4);
            switch(Choice){
                case 'N':
                    ui.printCreationOptions();
                    // Then proceeds to creation process no problems
                    break;
                case 'D':
                    // Prints out duplication messages
                    // But only if there are any entities to begin with
                    break;
                case 'R': 
                    // Prints out deletion messages
                    // But only if there are any entities to begin with
                    break;
                case 'I': 
                    // Prints out available interactions
                    // But only if there are entities to begin with
                    break;
            }
            // Must ask if user needs more turns before the day is over
            
            // History.push(World);
        }
        cout << "\nWant more turns before the day ends? [Y/N]" << endl;
        Choice = ui.getFromUserChar("YN", 2);
        if(Choice == 'Y'){
            moreTurns = true;
        }
        else{
            moreTurns = false;
        }
        }while(moreTurns);

        ui.printDailyStats(World);
        cout << "Want to proceed to next day? [Y/N]"; 
        Choice = ui.getFromUserChar("YN", 2);
        if(Choice == 'N'){
            GameOn = false;
        }
    }

    cout << "\n**Thank you for playing**\n" << endl;


    return 0;
}