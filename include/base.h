#pragma once // To solve the issue of multiple includes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* --- Resource Items --- */

/* Items have been defined explicitly as an enum class rather than a regular class since they are 
   far simpler than needing a class of their own, it was also practical to use enums as to limit the resources
   to certian predefined options
*/

enum class item {NONE, WATER, MILK, FRUITS, COCONUTS, MEAT, FISH, MEDS, WOOD, LEATHER, METAL, STONE};

/* --- Classes --- */

/* --- Base Class (Abstract) --- */
/* Contains all the basic attributes and methods for all other inheriting class (entities classes), including:
   - A unique ID implemented using a static member variable that counts for every entitiy created, hence every count is unique 
   and cannot be repeated even for duplicate entities
   - A name for the entity, which can either be predefined, or customized by the user
   - A state of (in)Active
*/
class simEntity {
private:
    static int count;
    int ID;
    string* name;
    bool isActive;

public:
    simEntity(string name = "NPC", bool isActive = true);
    simEntity(const simEntity& c);
    virtual ~simEntity();

    int getID() const;
    string* getName() const;
    void setName(string name);

    bool getisActive() const;
    void setActive(bool active);

    virtual void getStats() const = 0;
    virtual simEntity* clone() const = 0;

    // Used when undoing a deletion or modification
    void setIDForUndo(int id);
};

/* --- Living class (Abstract) --- */
/* Contains all the attributes for all living creatures in the sim (survivors and animals), it inherits from simEntity and contains:
   - Health level for the entity (and the maximum which is defined in the derived class based on the type of entity)
   - A Hunger level (Same thing as health level)
*/
class living : public simEntity {
private:
    int healthLevel;
    const int maxHealthLevel;
    int hungerlevel;
    const int maxHungerLevel;
public:
    living(string name = "NPC", bool isActive = true,
           int healthLevel = 100, int maxHealthLevel = 100,
           int hungerLevel = 100, int maxHungerLevel = 100);

    living(const living& c);
    virtual ~living();

    int getHealthLevel() const;
    void setHealthLevel(int healthLevel);

    int getMaxHealthLevel() const;

    int getHungerLevel() const;
    void setHungerLevel(int hungerLevel);

    int getMaxHungerLevel() const;
};

/* --- Builds Class (Abstract) --- */
/* Provides the base for all the builds the user can make in the sim, on the condtion that:
   1. There's at least one engineer survivor
   2. There's enough build materials
   It contains multiple attributes for the builds such as:
   - A durability (like a bar going down when a long time passes on the build), and a max value that can 
   be incremeneted as the build is upgraded
   - An upgrade level
   - A list of build requirements 
   - A list of features it provides for the camp
*/

class builds: public simEntity{
    private:
        int durability;
        int maxDurability;
        int upgradeLevel;
        vector<item> buildRequirements; // Array of required resources to create the build
        item upgradeRequirements;
        vector<string> features;
    public: 
        builds(string name = "New Build", bool isActive = true, int durability = 100, int maxDurability = 100,
             vector<item> buildRequirements = {item::WOOD}, item upgradeRequirements = item::WOOD, vector<string> features = {"Just a build"});
        builds(const builds &c);
        virtual ~builds();

        int getDurability() const;
        void setDurability(int);
        int getMaxDurability() const;
        void setMaxDurability(int); // Max durabitlity is modifiable as it can increase with upgrades
        int getUpgradeLevel() const;
        void setUpgradeLevel(int);
};




