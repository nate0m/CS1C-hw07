#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_SIZE = 50;

struct Item {

    string name;
    int qty;
    float cost;
};

class Inventory {

    public:
        Inventory() : count{0}, p_pItems{new Item*[size]} {}
        Inventory(int s) : size{s}, count{0}, p_pItems{new Item*[size]} {}
        Inventory(const Inventory& other);

        void importInventoryFile(string file, Inventory& i);

        void addItem(string n, int q, float c);
        void subtractItem(string n, int q);

        ~Inventory();

    private:
        int size{MAX_SIZE};
        int count;
        Item **p_pItems;
        // p->items[];
        void resizeInventory(int s);

};



#endif