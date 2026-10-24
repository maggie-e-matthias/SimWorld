
#pragma once

#include <iostream>
#include "base.h"
#include "stack.h"

using namespace std;

const int WORLD_CAPACITY = 1000;

class UndoRecord {
public:
    string action;
    int index;
    int originalID;
    simEntity* snapshot;

    UndoRecord(string action, int index,
               simEntity* snapshot = nullptr,
               int originalID = -1)
        : action(action), index(index),
          originalID(originalID), snapshot(snapshot) {
    }

    ~UndoRecord() {
        delete snapshot;
    }
};

class UndoManager {
private:
    Stack<UndoRecord*> undoStack;

public:
    UndoManager();
    ~UndoManager();

    void recordCreated(int index);
    void recordDeleted(int index, simEntity* entity);
    void recordModified(int index, simEntity* entity);

    bool undo(simEntity* entities[], int& count);
};
