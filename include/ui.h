#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>
#include <vector>
#include "survivors.h"
#include "builds.h"
#include "animals.h"
#include "undo.h"
#include "event.h"

using namespace std;

// UI handles validated input and user-facing operations on the world.
class UI {
public:
    char getFromUserChar(string bounds, int size);
    int getFromUserNum();
    void printTurnStats(const vector<simEntity*>& world);
    void printCreationOptions(vector<simEntity*>& world, UndoManager& undo);
    void printInteractionOptions(vector<simEntity*>& world, UndoManager& undo, EventManager& events);
    int findID(int targetID, const vector<simEntity*>& world);
    void createEntity(vector<simEntity*>& world, UndoManager& undo);
    void duplicateEntity(vector<simEntity*>& world, UndoManager& undo);
    void deleteEntity(vector<simEntity*>& world, UndoManager& undo);
    void interactWithEntity(vector<simEntity*>& world, UndoManager& undo, EventManager& events);
    void printDailyStats(const vector<simEntity*>& world);
};
