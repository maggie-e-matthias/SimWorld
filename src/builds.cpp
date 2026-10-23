#include "include/builds.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <int N>
hut<N>::hut(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::STONE};
    cout << "Hut created" << endl;
}

template <int N>
hut<N>::hut(hut<N> &c): builds(c) {
    cout << "Hut created" << endl;
}

template <int N>
hut<N>::~hut() {
    cout << "Hut destroyed" << endl;
}

template <int N>
fence<N>::fence(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::WOOD};
    cout << "Fence created" << endl;
}

template <int N>
fence<N>::fence(fence<N> &c): builds(c) {
    cout << "Fence created" << endl;
}

template <int N>
fence<N>::~fence() {
    cout << "Fence destroyed" << endl;
}

template <int N>
farm<N>::farm(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequriements[] = {item::WOOD, item::WATER, item::STONE};
    cout << "Farm created" << endl;
}

template <int N>
farm<N>::farm(farm<N> &c): builds(c) {
    cout << "Farm created" << endl;
}

template <int N>
farm<N>::~farm() {
    cout << "Farm destroyed" << endl;
}

template <int N>
storage<N>::storage(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::LEATHER, item::WOOD, item::METAL};
    cout << "Storage created" << endl;
}

template <int N>
storage<N>::storage(storage<N> &c): builds(c) {
    cout << "Storage created" << endl;
}

template <int N>
storage<N>::~storage() {
    cout << "Storage destroyed" << endl;
}

template <int N>
animalPen<N>::animalPen(string name, bool isActive, int durability, int maxDurability): builds(name, isActive, durability, maxDurability) {
    this->buildRequirements[] = {item::WOOD, item::STONE, item::LEATHER};
    cout << "Animal Pen created" << endl;
}

template <int N>
animalPen<N>::animalPen(animalPen<N> &c): builds(c) {
    cout << "Animal Pen created" << endl;
}

template <int N>
animalPen<N>::~animalPen() {
    cout << "Animal Pen destroyed" << endl;
}