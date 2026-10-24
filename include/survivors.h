
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "base.h"

using namespace std;

// General survivor
class survivor : public living {
private:
    int XPLevel;
    vector<item> inventory;
    const int maxInventorySize;

public:
    survivor(string name = "New Survivor",
             bool isActive = true,
             int maxInventorySize = 10);

    survivor(const survivor& c);
    virtual ~survivor();

    int getXPLevel() const;
    void setXPLevel(int XPLevel);

    void addToInventory(item I);
    bool isInventoryEmpty() const;
    vector<item> getInventory() const;
    int findInInventory(item I);
    void useFromInventory(item I);

    void transferItem(item I, simEntity* target);

    void getAction() const override;
};

// Doctor
class doctor : public survivor {
public:
    doctor(string name = "New Doctor", bool isActive = true);
    doctor(const doctor& c);
    virtual ~doctor();

    void heal(survivor& s);
    void makeMeds();

    simEntity* clone() const override;
};

// Scout
class scout : public survivor {
public:
    scout(string name = "New Scout", bool isActive = true);
    scout(const scout& c);
    virtual ~scout();

    void gatherResources();

    simEntity* clone() const override;
};

// Engineer
class engineer : public survivor {
public:
    engineer(string name = "New Engineer", bool isActive = true);
    engineer(const engineer& c);
    virtual ~engineer();

    void build();
    void repair();

    simEntity* clone() const override;
};

// Farmer
class farmer : public survivor {
public:
    farmer(string name = "New Farmer", bool isActive = true);
    farmer(const farmer& c);
    virtual ~farmer();

    void breed();
    void growCrops();

    simEntity* clone() const override;
};

// Hunter
class hunter : public survivor {
public:
    hunter(string name = "New Hunter", bool isActive = true);
    hunter(const hunter& c);
    virtual ~hunter();

    void hunt();
    void fendOff();

    simEntity* clone() const override;
};
