/*
    Authors: 
    - Magdoleen Matthias 900251595
    - Hanan Elnakeeb 900253826

    GitHub Repo link(for documentation purposes):
    https://github.com/maggie-e-matthias/SimWorld.git

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
        The Class heirarchy in the sim is as follows: 
            simEntity
            |---living
            |   |---survivor
            |   |   |---doctor
            |   |   |---hunter
            |   |   |---scout
            |   |   |---engineer
            |   |   |---farmer
            |   |  
            |   |---animal
            |       |---goat
            |       |---pig
            |       |---rabbit
            |   
            |---builds
                |---hut
                |---storage
                |---fence
                |---farm
                |---animalPen

        
    Features:
        F1 Diverse Entities
            There are about 14 Unique Entities that can be instantiaded in the sim, and 

        F2 Creating Entites
            Functions in the UI class (that handle printing out interface and access the backend as well) provide the option
            to create any of the 14 entities, supposedly with the option of using defualt values and custom values
            (Both parameterized and default constructors have been implemented using the defualt parameters as arguments(in order to avoid repition), 
            if provided, then entity can be created with custom parameters, if not, defualt values are used)

        F3 Duplicating Entities
            This process calls the "clone" function of target entity, which in turn calls the deep copy constructor, 
            the ID practically can never be duplicated as the constructor itself generates a unique ID based on static memeber count

        F4 Running the Sim
            Once the simulation starts, the user can take a certain number of turns per a game day, after the turns end, 
            they're asked if they want to take more turns, if so, they get to take some more, if not, the day ends and they get a 
            board of all game stats, then they're asked whether they want to proceed to the following day or quit the game
            This is done by making a day loop and an inner turn loop, the inner turn loop itself has a while loop to see whether the user
            wants to take more turns FOR THAT DAY. All entities are stored in one World vector of type simEntity*

        F5 Special Capabilities
            Survivors in particular have special abilities for each kind, e.g. doctors can heal other survivors, engineers can make builds and repairs

        F6 Event Queue
            A special template queue class was implemented to handle this situation, and a derived event manager (that has an event
            queue object inside) was implmented to hold pending events

        F7 Undo
            A special template stack class was created and a derived Undo record class was implemented with
            attributes and methods to handle undos 

        F8 Data Structures
            Instead of #include<Stack> and #include<Queue>, we implemented our own template classes for it in the 
            include directory

        F9 Console interface
            Some of the messages printed to user were implemented in main, more complex ones (especially ones that directly deal
            with the world itself) were implemented in thier own UI class, where functions and some utility functions (such as the one for finding the 
            index corresponding to a certian ID) were incapsulated in this class for ease of use

        F10 Memory Safety
            At the end of sim, every enitiy in the world is deleted, and the world vector itself is cleared afterwards

        F11 Special feature: 
            At the end of each game day, the user gets an overview of their world stats, 
            in this case the number of survivors, number of builds, number of animals, and most importantly;
            Their own XP level (which is the total level of XP of all survivors ever created)
            and Their camp level (which is the total level of upgradeLevel of all builds ever created as well), 
            this gives the user a sense of acomplishment and progress while playing 
    
    Insructions for running: 
        Running requirements: CMake v3.16 or higher, MinGW as your compiler

        If you're recieving this program as part of an assignemnt, you should have recieved:
            /include
            /src
            CMakeLists.txt
            main.cpp
        
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
    I acknowledge that I have used claude AI to: 
    - Explain concepts in c++/cmake
    - Help explain error messages and explain what could be causing the errors
    - Help Debug errors in the program
        https://claude.ai/share/aeb69181-202c-464d-b15e-ba6033c9cf6c

    As well as partially using inline suggestions by GitHub Copilot in VS Code

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

    // Delete all remaining entities
    for (int i = 0, n = World.size(); i < n; i++) {
        delete World[i];
        World[i] = nullptr;
    }
    World.clear();

    cout << "\n**Thank you for playing**\n" << endl;


    return 0;
}