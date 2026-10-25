#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "base.h"
#include "Queue.h"
#include "undo.h"
using namespace std;

// An event stores the target's ID rather than a raw pointer, so deleting an
// entity while an event is pending cannot leave a dangling pointer.
class Event {
private:
    int eventID;
    string type;
    int targetID;
    int amount;
    string description;
    static int nextID;
public:
    Event();
    Event(string type, simEntity* target, int amount, string description);
    int getEventID() const;
    string getType() const;
    int getTargetID() const;
    int getAmount() const;
    string getDescription() const;
    void display() const;
    void doDeactivate(simEntity* target, int& targetIndex, UndoManager& undo);
    void doDamage(simEntity* target, Event& current, int& targetIndex, UndoManager& undo);
    void doHeal(simEntity* target, Event& current, int& targetIndex, UndoManager& undo);
    void RandomEvent(simEntity* target, Event& current, int& targetIndex, UndoManager& undo);

};

class EventManager {
private:
    Queue<Event> events;
public:
    bool addEvent(const Event& event);
    void viewEvents() const;
    void processEvents(vector<simEntity*>& world, UndoManager& undo);
    bool hasEvents() const;
    
};
