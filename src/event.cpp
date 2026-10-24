
#include "include/event.h"
#include "include/Queue.h"
#include <iostream>


int Event::nextID = 1;

Event::Event()
    : eventID(nextID++), type(""), target(nullptr),
      amount(0), description("") {
}

Event::Event(string type, simEntity* target, int amount,
             string description)
    : eventID(nextID++), type(type), target(target),
      amount(amount), description(description) {
}

int Event::getEventID() const {
    return eventID;
}

string Event::getType() const {
    return type;
}

simEntity* Event::getTarget() const {
    return target;
}

int Event::getAmount() const {
    return amount;
}

string Event::getDescription() const {
    return description;
}

void Event::display() const {
    cout << "Event ID: " << eventID << endl;
    cout << "Type: " << type << endl;
    cout << "Description: " << description << endl;

    if (target != nullptr) {
        cout << "Target entity ID: "
             << target->getID() << endl;
    } else {
        cout << "Target: None" << endl;
    }

    cout << "Amount: " << amount << endl;
}

bool EventManager::addEvent(const Event& event) {
    return events.enqueue(event);
}

bool EventManager::hasEvents() const {
    return !events.isEmpty();
}

// Show events without removing them from the original queue
void EventManager::viewEvents() const {
    Queue<Event> copy = events;
    Event current;

    if (copy.isEmpty()) {
        cout << "There are no pending events." << endl;
        return;
    }

    while (copy.peek(current)) {
        current.display();
        copy.dequeue();
    }
}

void EventManager::processEvents() {
    Event current;

    while (events.peek(current)) {
        simEntity* target = current.getTarget();

        if (target == nullptr) {
            cout << "Event has no target." << endl;
        }
        else if (current.getType() == "damage") {
            living* person = dynamic_cast<living*>(target);

            if (person != nullptr) {
                int newHealth =
                    person->getHealthLevel() - current.getAmount();

                if (newHealth < 0) {
                    newHealth = 0;
                }

                person->setHealthLevel(newHealth);
                cout << "Damage event processed." << endl;
            } else {
                cout << "Damage event requires a living entity."
                     << endl;
            }
        }
        else if (current.getType() == "heal") {
            living* person = dynamic_cast<living*>(target);

            if (person != nullptr) {
                int newHealth = person->getHealthLevel() + current.getAmount();

                if (newHealth > person->getMaxHealthLevel()) {
                    newHealth = person->getMaxHealthLevel();
                }

                person->setHealthLevel(newHealth);
                cout << "Heal event processed." << endl;
            } else {
                cout << "Heal event requires a living entity."
                     << endl;
            }
        }
        else if (current.getType() == "deactivate") {
            target->setActive(false);
            cout << "Entity deactivated." << endl;
        }
        else {
            cout << "Unknown event type." << endl;
        }

        // Remove the event after processing it
        events.dequeue();
    }
}
