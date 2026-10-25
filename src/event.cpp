#include "include/event.h"

int Event::nextID = 1;

Event::Event() : eventID(nextID++), type(""), targetID(-1), amount(0), description("") {}

Event::Event(string type, simEntity* target, int amount, string description)
    : eventID(nextID++), type(type), targetID(target ? target->getID() : -1),
      amount(amount), description(description) {}

int Event::getEventID() const { return eventID; }
string Event::getType() const { return type; }
int Event::getTargetID() const { return targetID; }
int Event::getAmount() const { return amount; }
string Event::getDescription() const { return description; }

void Event::display() const {
    cout << "Event ID: " << eventID << " | Type: " << type
         << " | Target ID: " << (targetID < 0 ? string("None") : to_string(targetID))
         << " | Amount: " << amount << "\nDescription: " << description << "\n";
}

bool EventManager::addEvent(const Event& event) { return events.enqueue(event); }
bool EventManager::hasEvents() const { return !events.isEmpty(); }

void EventManager::viewEvents() const {
    Queue<Event> copy = events;
    if (copy.isEmpty()) { cout << "There are no pending events.\n"; return; }
    Event current;
    cout << "\nPending events (generation order):\n";
    while (copy.peek(current)) {
        current.display();
        copy.dequeue();
    }
}

void EventManager::processEvents(vector<simEntity*>& world, UndoManager& undo) {
    Event current;
    while (events.peek(current)) {
        simEntity* target = nullptr;
        int targetIndex = -1;
        for (int i = 0; i < (int)world.size(); i++) {
            if (world[i] && world[i]->getID() == current.getTargetID()) {
                target = world[i];
                targetIndex = i;
                break;
            }
        }

        if (!target) {
            cout << "Event " << current.getEventID()
                 << " skipped: target no longer exists.\n";
        } else if (current.getType() == "damage") {
            living* person = dynamic_cast<living*>(target);
            if (person) {
                undo.recordModified(targetIndex, target);
                int health = person->getHealthLevel() - current.getAmount();
                if (health < 0) health = 0;
                person->setHealthLevel(health);
                cout << "Damage event processed for ID " << target->getID() << ".\n";
            } else cout << "Damage event needs a living target.\n";
        } else if (current.getType() == "heal") {
            living* person = dynamic_cast<living*>(target);
            if (person) {
                undo.recordModified(targetIndex, target);
                int health = person->getHealthLevel() + current.getAmount();
                if (health > person->getMaxHealthLevel()) health = person->getMaxHealthLevel();
                person->setHealthLevel(health);
                cout << "Heal event processed for ID " << target->getID() << ".\n";
            } else cout << "Heal event needs a living target.\n";
        } else if (current.getType() == "deactivate") {
            undo.recordModified(targetIndex, target);
            target->setActive(false);
            cout << "Entity deactivated.\n";
        } else cout << "Unknown event type: " << current.getType() << '\n';

        events.dequeue();
    }
}
