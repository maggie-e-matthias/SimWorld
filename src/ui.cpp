#include "include/ui.h"

using namespace std;

char UI::getFromUserChar(string bounds, int size) {
    char choice;
    while (true) {
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        choice = static_cast<char>(toupper(static_cast<unsigned char>(choice)));
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < size; i++) {
            if (choice == bounds[i]) return choice;
        }
        cout << "Please enter one of the listed choices." << endl;
    }
}

int UI::getFromUserNum() {
    int input;
    while (true) {
        cout << "Enter a positive whole number: ";
        if (cin >> input && input > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
        cout << "Invalid number. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int UI::findID(int targetID, const vector<simEntity*>& world) {
    for (int i = 0; i < (int)world.size(); i++)
        if (world[i] && world[i]->getID() == targetID) return i;
    cout << "No entity with that ID exists." << endl;
    return -1;
}

void UI::printTurnStats(const vector<simEntity*>& world) {
    cout << "\n---------------- World ----------------\n";
    if (world.empty()) {
        cout << "The world is empty.\n";
        return;
    }
    cout << left << setw(7) << "Index" << setw(7) << "ID"
         << setw(24) << "Name" << "Status\n";
    for (int i = 0; i < (int)world.size(); i++) {
        cout << left << setw(7) << i << setw(7) << world[i]->getID()
             << setw(24) << *world[i]->getName()
             << (world[i]->getisActive() ? "Active" : "Inactive") << '\n';
    }
    cout << "Inspect an entity? [Y/N]\n";
    if (getFromUserChar("YN", 2) == 'Y') {
        cout << "Enter entity ID: ";
        int id = getFromUserNum();
        int index = findID(id, world);
        if (index >= 0) {
            world[index]->getAction();
            living* person = dynamic_cast<living*>(world[index]);
            if (person)
                cout << "Health: " << person->getHealthLevel()
                     << "/" << person->getMaxHealthLevel()
                     << " | Hunger: " << person->getHungerLevel()
                     << "/" << person->getMaxHungerLevel() << '\n';
            survivor* s = dynamic_cast<survivor*>(world[index]);
            if (s) cout << "XP: " << s->getXPLevel() << '\n';
            builds* b = dynamic_cast<builds*>(world[index]);
            if (b) cout << "Durability: " << b->getDurability()
                         << "/" << b->getMaxDurability()
                         << " | Upgrade level: " << b->getUpgradeLevel() << '\n';
        }
    }
}

void UI::printCreationOptions(vector<simEntity*>& world, UndoManager& undo) {
    createEntity(world, undo);
}

void UI::createEntity(vector<simEntity*>& world, UndoManager& undo) {
    cout << "\nCreate: Survivor[S], Animal[A], Build[B], Cancel[C]\n";
    char group = getFromUserChar("SABC", 4);
    if (group == 'C') return;
    cout << "Enter a name (one line): ";
    string name;
    getline(cin, name);
    if (name.empty()) name = "New Entity";

    simEntity* created = nullptr;
    if (group == 'S') {
        cout << "Regular[R], Doctor[D], Scout[S], Farmer[F], Engineer[E], Hunter[H]\n";
        char type = getFromUserChar("RDSFEH", 6);
        if (type == 'R') created = new survivor(name);
        else if (type == 'D') created = new doctor(name);
        else if (type == 'S') created = new scout(name);
        else if (type == 'F') created = new farmer(name);
        else if (type == 'E') created = new engineer(name);
        else if (type == 'H') created = new hunter(name);
    } else if (group == 'A') {
        cout << "Rabbit[R], Goat[G], Pig[P]\n";
        char type = getFromUserChar("RGP", 3);
        if (type == 'R') created = new rabbit(name);
        else if (type == 'G') created = new goat(name);
        else if (type == 'P') created = new pig(name);
    } else {
        cout << "Hut[H], Fence[F], Storage[S], Farm[R], Animal pen[P]\n";
        char type = getFromUserChar("HFSRP", 5);
        if (type == 'H') created = new hut(name);
        else if (type == 'F') created = new fence(name);
        else if (type == 'S') created = new storage(name);
        else if (type == 'R') created = new farm(name);
        else if (type == 'P') created = new animalPen(name);
    }

    if (created) {
        world.push_back(created);
        undo.recordCreated((int)world.size() - 1);
        cout << "Created " << *created->getName() << " with ID " << created->getID() << ".\n";
    }
}

void UI::duplicateEntity(vector<simEntity*>& world, UndoManager& undo) {
    if (world.empty()) { cout << "There are no entities to duplicate.\n"; return; }
    cout << "Enter the ID to duplicate: ";
    int index = findID(getFromUserNum(), world);
    if (index < 0) return;
    simEntity* copy = world[index]->clone();
    world.push_back(copy);
    undo.recordCreated((int)world.size() - 1);
    cout << "Duplicated entity. New ID: " << copy->getID() << '\n';
}

void UI::deleteEntity(vector<simEntity*>& world, UndoManager& undo) {
    if (world.empty()) { cout << "There are no entities to delete.\n"; return; }
    cout << "Enter the ID to delete: ";
    int index = findID(getFromUserNum(), world);
    if (index < 0) return;
    undo.recordDeleted(index, world[index]);
    delete world[index];
    world.erase(world.begin() + index);
    cout << "Entity deleted.\n";
}

void UI::printInteractionOptions(vector<simEntity*>& world, UndoManager& undo, EventManager& events) {
    interactWithEntity(world, undo, events);
}

void UI::interactWithEntity(vector<simEntity*>& world, UndoManager& undo, EventManager& events) {
    if (world.empty()) { cout << "There are no entities to interact with.\n"; return; }
    cout << "Enter the ID of the entity to interact with: ";
    int index = findID(getFromUserNum(), world);
    if (index < 0) return;
    simEntity* entity = world[index];
    cout << "Rename[N], Toggle active[A], Special ability[S], Queue event[E], Cancel[C]\n";
    char choice = getFromUserChar("NASEC", 5);
    if (choice == 'C') return;
    if (choice == 'N') {
        undo.recordModified(index, entity);
        cout << "Enter the new name: ";
        string name; getline(cin, name);
        if (!name.empty()) entity->setName(name);
    } else if (choice == 'A') {
        undo.recordModified(index, entity);
        entity->setActive(!entity->getisActive());
        cout << "Entity is now " << (entity->getisActive() ? "active" : "inactive") << ".\n";
    } else if (choice == 'E') {
        cout << "Damage[D], Heal[H], Deactivate[X]\n";
        char eventType = getFromUserChar("DHX", 3);
        string type, description;
        int amount = 0;
        if (eventType == 'D') { type = "damage"; description = "Damage target"; amount = getFromUserNum(); }
        else if (eventType == 'H') { type = "heal"; description = "Heal target"; amount = getFromUserNum(); }
        else { type = "deactivate"; description = "Deactivate target"; }
        if (events.addEvent(Event(type, entity, amount, description)))
            cout << "Event added to the queue.\n";
        else cout << "Event queue is full.\n";
    } else if (choice == 'S') {
        survivor* s = dynamic_cast<survivor*>(entity);
        doctor* d = dynamic_cast<doctor*>(entity);
        scout* sc = dynamic_cast<scout*>(entity);
        engineer* en = dynamic_cast<engineer*>(entity);
        farmer* f = dynamic_cast<farmer*>(entity);
        hunter* h = dynamic_cast<hunter*>(entity);
        animal* a = dynamic_cast<animal*>(entity);

        if (d) {
            cout << "Make medicine[M] or heal another survivor[H]?\n";
            char action = getFromUserChar("MH", 2);
            undo.recordModified(index, entity);
            if (action == 'M') d->makeMeds();
            else {
                cout << "Enter survivor ID to heal: ";
                int targetIndex = findID(getFromUserNum(), world);
                if (targetIndex >= 0) {
                    survivor* target = dynamic_cast<survivor*>(world[targetIndex]);
                    if (target) { undo.recordModified(targetIndex, target); d->heal(*target); }
                    else cout << "That entity is not a survivor.\n";
                }
            }
        } else if (sc) { undo.recordModified(index, entity); sc->gatherResources(); cout << "Resources gathered; XP increased.\n"; }
        else if (en) {
            cout << "Build action[B] or repair action[R]?\n";
            char action = getFromUserChar("BR", 2);
            undo.recordModified(index, entity);
            if (action == 'B') en->build(); else en->repair();
        } else if (f) {
            cout << "Breed[B] or grow crops[G]?\n";
            char action = getFromUserChar("BG", 2);
            undo.recordModified(index, entity);
            if (action == 'B') f->breed(); else f->growCrops();
        } else if (h) {
            undo.recordModified(index, entity);
            h->fendOff();
            cout << "Hunter fended off danger.\n";
        } else if (a) a->dropResources();
        else if (s) cout << "This survivor has no special ability. Its action is shown below:\n";
        else cout << "This entity has no special ability.\n";
        if (s) s->getAction();
    }
}

void UI::printDailyStats(const vector<simEntity*>& world) {
    int survivorCount = 0, totalXP = 0, buildCount = 0, campLevel = 0, animalCount = 0;
    for (simEntity* entity : world) {
        if (survivor* s = dynamic_cast<survivor*>(entity)) { survivorCount++; totalXP += s->getXPLevel(); }
        if (builds* b = dynamic_cast<builds*>(entity)) { buildCount++; campLevel += b->getUpgradeLevel(); }
        if (dynamic_cast<animal*>(entity)) animalCount++;
    }
    cout << "\n========== Daily Statistics ==========\n"
         << "Total survivors: " << survivorCount << '\n'
         << "Total builds: " << buildCount << '\n'
         << "Total animals: " << animalCount << '\n'
         << "Total survivor XP: " << totalXP << '\n'
         << "Camp upgrade level total: " << campLevel << '\n'
         << "======================================\n";
}
