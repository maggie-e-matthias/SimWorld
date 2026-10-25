/*
    Survivor Island Simulator
    Authors:
      - Magdoleen Matthias, AUC ID 900251595
      - Hanan Elnakeeb, AUC ID 900253826
    Repository: https://github.com/maggie-e-matthias/SimWorld.git

    WORLD DESCRIPTION
    The player manages a small survivor camp on an island. The player can
    create, inspect, duplicate, modify, and delete survivors, animals, and
    buildings, run turns, schedule events, and undo recent world changes.

    INHERITANCE OVERVIEW
    simEntity (abstract)
    |-- living (abstract)
    |   |-- survivor
    |   |   |-- doctor, scout, engineer, farmer, hunter
    |   |-- animal (abstract)
    |       |-- rabbit, goat, pig
    |-- builds (abstract)
        |-- hut, fence, farm, storage, animalPen

    Why: simEntity stores attributes shared by all entities. living adds
    health and hunger to creatures. survivor and animal specialize living.
    builds is separate because buildings have durability and upgrade levels.
    Concrete classes override getAction() and clone() for polymorphism.

    REQUIREMENT MAP (implemented features in this version)
    F1: The inheritance hierarchy and concrete entity types are declared in
        include/base.h, survivors.h, animals.h, and builds.h.
    F2: UI::createEntity in src/ui.cpp creates each concrete type using a
        default constructor with a user-provided name.
    F3: UI::duplicateEntity calls virtual clone(); concrete clone methods
        use copy constructors.
    F4: The main turn loop calls getAction() polymorphically for active
        entities; the UI also displays entity-specific information.
    F5: UI::interactWithEntity uses checked dynamic_cast operations for
        survivor special abilities, animal resource drops, and living events.
    F6: Event and EventManager in include/event.h and src/event.cpp implement
        a fixed-capacity FIFO queue, pending-event viewing, and damage, heal,
        and deactivate event effects.
    F7: UndoManager in include/undo.h and src/undo.cpp records create, delete,
        and modify operations using polymorphic snapshots and a LIFO stack.
    F8: include/Stack.h and include/Queue.h implement array-based templates.
    F9: UI in include/ui.h and src/ui.cpp implements menus and input checks.
    F10: The world owns its entity pointers; main deletes them at exit.
         Undo snapshots are deleted when their records are discarded.
    F11: Daily statistics in UI::printDailyStats report the current counts of
         survivors, animals, buildings, current survivor XP, and total build
         upgrade levels.

    BUILD
    From the project root:
      mkdir build
      cd build
      cmake ..
      cmake --build .
    Run on Windows: .\\sim.exe
    Run on Linux/macOS: ./sim

    ASSUMPTIONS / LIMITATIONS
    - Entity creation uses each type's default attribute values and lets the
      user customize the name; other attributes can be modified through the
      interaction menu where supported.
    - Event effects are applied when the player selects Process events.
    - Daily XP and camp-level totals describe entities currently in the world,
      not entities that were previously deleted.
    - Building resource costs are represented in class data but are not
      enforced by this console version.

    AI USE DISCLOSURE
    The project authors should update this section to accurately disclose
    all AI tools used, what they were used for, and any relevant links.
    Previous project notes mentioned Claude and GitHub Copilot. ChatGPT was
    used to help review and correct code in this revision; the authors should
    confirm this wording matches their course policy and actual use.
*/

#include "include/ui.h"
#include "include/event.h"
#include "include/undo.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    UI ui;
    vector<simEntity*> world; // Owns the entity pointers in the simulation.
    EventManager events;
    UndoManager undo;

    bool gameOn = true;
    int day = 0;

    cout << "------ Survivor Island Simulator ------\n";
    cout << "Start[S] or Quit[Q]\n";
    if (ui.getFromUserChar("SQ") == 'Q') gameOn = false;

    while (gameOn) {
        day++;
        cout << "\n========== Day " << day << " ==========\n";
        cout << "How many turns do you want today?\n";
        int turns = ui.getFromUserNum();

        for (int turn = 1; turn <= turns; turn++) {
            cout << "\n----- Turn " << turn << " -----\n";
            ui.printTurnStats(world);

        // Every active entity performs its type-specific action through
        // the same virtual function, without checking its concrete type.
        cout << "\nActive entities take their actions:\n";

        for (simEntity* entity : world)
        {
            if (entity != nullptr && entity->getisActive())
            {
                entity->getStats();
            }
        }

            cout << "\nCreate[N] Duplicate[D] Delete[R] Interact[I] Undo[U]\n";
            cout << "View pending events[V] Process events[P] End turn[T]\n";
            char choice = ui.getFromUserChar("NDRIUVPT");

            switch (choice) {
                case 'N': ui.printCreationOptions(world, undo); break;
                case 'D': ui.duplicateEntity(world, undo); break;
                case 'R': ui.deleteEntity(world, undo); break;
                case 'I': ui.printInteractionOptions(world, undo, events); break;
                case 'U': undo.undo(world); break;
                case 'V': events.viewEvents(); break;
                case 'P': events.processEvents(world, undo); break;
                case 'T': break;
            }
        }
        
        ui.printDailyStats(world);
        cout << "\nContinue to the next day? [Y/N]\n";
        if (ui.getFromUserChar("YN") == 'N') gameOn = false;
    }

    // Delete each world-owned entity exactly once before exiting.
    for (simEntity* entity : world) delete entity;
    world.clear();

    cout << "\nThank you for playing!\n";
    return 0;
}
