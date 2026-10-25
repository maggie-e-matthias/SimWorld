#include "include/undo.h"

// Undo records own their snapshots. Every snapshot is a polymorphic clone.
UndoManager::UndoManager() {}

UndoManager::~UndoManager() {
    UndoRecord* record;
    while (undoStack.peek(record)) {
        undoStack.pop();
        delete record;
    }
}

void UndoManager::recordCreated(int index) {
    UndoRecord* record = new UndoRecord("create", index);
    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

void UndoManager::recordDeleted(int index, simEntity* entity) {
    if (!entity) return;
    simEntity* snapshot = entity->clone();
    snapshot->setIDForUndo(entity->getID());
    UndoRecord* record = new UndoRecord("delete", index, snapshot, entity->getID());
    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

void UndoManager::recordModified(int index, simEntity* entity) {
    if (!entity) return;
    simEntity* snapshot = entity->clone();
    snapshot->setIDForUndo(entity->getID());
    UndoRecord* record = new UndoRecord("modify", index, snapshot, entity->getID());
    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

bool UndoManager::undo(vector<simEntity*>& entities) {
    UndoRecord* record = nullptr;
    if (!undoStack.peek(record)) {
        cout << "There is nothing to undo." << endl;
        return false;
    }

    int index = record->index;
    if (record->action == "create") {
        if (index < 0 || index >= (int)entities.size()) {
            cout << "Cannot undo: entity position is invalid." << endl;
            return false;
        }
        delete entities[index];
        entities.erase(entities.begin() + index);
        cout << "Creation/duplication undone." << endl;
    } else if (record->action == "delete") {
        if (index < 0 || index > (int)entities.size()) {
            cout << "Cannot undo: entity position is invalid." << endl;
            return false;
        }
        simEntity* restored = record->snapshot->clone();
        restored->setIDForUndo(record->originalID);
        entities.insert(entities.begin() + index, restored);
        cout << "Deletion undone." << endl;
    } else if (record->action == "modify") {
        if (index < 0 || index >= (int)entities.size()) {
            cout << "Cannot undo: entity position is invalid." << endl;
            return false;
        }
        delete entities[index];
        entities[index] = record->snapshot->clone();
        entities[index]->setIDForUndo(record->originalID);
        cout << "Modification undone." << endl;
    } else {
        cout << "Unknown undo action." << endl;
        return false;
    }

    undoStack.pop();
    delete record;
    return true;
}
