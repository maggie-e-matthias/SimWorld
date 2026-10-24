
#include "include/undo.h"

UndoManager::UndoManager() {
}

UndoManager::~UndoManager() {
    UndoRecord* record;

    while (undoStack.peek(record)) {
        undoStack.pop();
        delete record;
    }
}

// this is used after creating or duplicating an entity
void UndoManager::recordCreated(int index) {
    UndoRecord* record =
        new UndoRecord("create", index);

    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

// this is used before deleting the entity
void UndoManager::recordDeleted(int index, simEntity* entity) {
    if (entity == nullptr) {
        return;
    }

    simEntity* snapshot = entity->clone();

    // this is to keep the original ID for undo
    snapshot->setIDForUndo(entity->getID());

    UndoRecord* record =
        new UndoRecord("delete", index, snapshot, entity->getID());

    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

// this is used before changing an entity's attributes
void UndoManager::recordModified(int index, simEntity* entity) {
    if (entity == nullptr) {
        return;
    }

    simEntity* snapshot = entity->clone();
    snapshot->setIDForUndo(entity->getID());

    UndoRecord* record =
        new UndoRecord("modify", index, snapshot, entity->getID());

    if (!undoStack.push(record)) {
        delete record;
        cout << "Undo history is full." << endl;
    }
}

bool UndoManager::undo(simEntity* entities[], int& count) {
    UndoRecord* record;

    if (!undoStack.peek(record)) {
        cout << "There is nothing to undo." << endl;
        return false;
    }

    int index = record->index;

    // this is to undo creating or duplicating an entity
    if (record->action == "create") {
        if (index < 0 || index >= count) {
            cout << "Cannot undo: entity position is invalid."
                 << endl;
            return false;
        }

        delete entities[index];

        // to move the remaining entities one position left
        for (int i = index; i < count - 1; i++) {
            entities[i] = entities[i + 1];
        }

        count--;
        entities[count] = nullptr;

        cout << "Creation/duplication undone." << endl;
    }

    // this is to undo deleting an entity
    else if (record->action == "delete") {
        if (count >= WORLD_CAPACITY) {
            cout << "Cannot undo: the world is full." << endl;
            return false;
        }

        if (index < 0 || index > count) {
            cout << "Cannot undo: entity position is invalid."
                 << endl;
            return false;
        }

        // this is to move entities right to make room
        for (int i = count; i > index; i--) {
            entities[i] = entities[i - 1];
        }

        // this is to restore a copy of the saved entity
        entities[index] = record->snapshot->clone();
        entities[index]->setIDForUndo(record->originalID);

        count++;

        cout << "Deletion undone." << endl;
    }

    // this is to undo modifying an entity
    else if (record->action == "modify") {
        if (index < 0 || index >= count) {
            cout << "Cannot undo: entity position is invalid."
                 << endl;
            return false;
        }

        // this is to remove the modified entity
        delete entities[index];

        // this is to restore the saved state
        entities[index] = record->snapshot->clone();
        entities[index]->setIDForUndo(record->originalID);

        cout << "Modification undone." << endl;
    }

    else {
        cout << "Unknown undo action." << endl;
        return false;
    }

    // this is to remove this undo record from the stack
    undoStack.pop();
    delete record;

    return true;
}
