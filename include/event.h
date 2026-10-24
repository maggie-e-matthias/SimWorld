
#pragma once

#include <iostream>
#include <string>
#include "base.h"
#include "queue.h"

using namespace std;

class Event {
private:
    int eventID;
    string type;
    simEntity* target;
    int amount;
    string description;

    static int nextID;

public:
    Event();
    Event(string type, simEntity* target, int amount,
          string description);

    int getEventID() const;
    string getType() const;
    simEntity* getTarget() const;
    int getAmount() const;
    string getDescription() const;

    void display() const;
};

class EventManager {
private:
    Queue<Event> events;

public:
    bool addEvent(const Event& event);
    void viewEvents() const;
    void processEvents();
    bool hasEvents() const;
};
