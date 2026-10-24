
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "include/base.h"

using namespace std;


// Hut: a shelter where survivors can spend the night.
class hut : public builds {
private:
    vector<string> features;

public:
    hut();
    hut(const hut& c);
    ~hut() override;

    void getAction() const override;
    simEntity* clone() const override;
};


// Fence: protects the survivors' camp.
class fence : public builds {
private:
    vector<string> features;

public:
    fence();
    fence(const fence& c);
    ~fence() override;

    void getAction() const override;
    simEntity* clone() const override;
};


// Farm: allows survivors to grow crops.
class farm : public builds {
private:
    vector<string> features;

public:
    farm();
    farm(const farm& c);
    ~farm() override;

    void getAction() const override;
    simEntity* clone() const override;
};


// Storage: keeps the survivors' resources.
class storage : public builds {
private:
    vector<string> features;

public:
    storage();
    storage(const storage& c);
    ~storage() override;

    void getAction() const override;
    simEntity* clone() const override;
};


// Animal pen: provides a place for animals to live.
class animalPen : public builds {
private:
    vector<string> features;

public:
    animalPen();
    animalPen(const animalPen& c);
    ~animalPen() override;

    void getAction() const override;
    simEntity* clone() const override;
};
