#include "inventory.h"

Inventory::Inventory(const Inventory& other) {

    count = other.count;
    size = other.size;

    p_pItems = new Item*[size];

    for(int i = 0; i < count; i++) {

        Item* newItem = new Item;
        *newItem = *(other.p_pItems[i]);

        p_pItems[i] = newItem;
    }
}
void Inventory::importInventoryFile(string file, Inventory& i) {

    ifstream fin;
    fin.open(file);

    string line;

    while(getline(fin, line)) {

        string name;
        int qty;
        float cost;

        istringstream iss(line);
        string token;

        getline(iss, token, '|');
        name = token;

        getline(iss, token, '|');
        cost = stof(token);

        getline(iss, token, '|');
        qty = stoi(token);

        i.addItem(name, qty, cost); 
    }
}
void Inventory::resizeInventory(int newSize) {

    Item **newItems = new Item*[newSize];
    
    for(int i = 0; i < count; i++) 
        newItems[i] = p_pItems[i];

    for(int i = count; count < newSize; count++)
        newItems[i] = new Item;

    delete[] p_pItems;
    p_pItems = newItems;
    size = newSize;
}
void Inventory::addItem(string n, int q, float c) {

    Item *newItem = new Item;
    if(count >= size)
        resizeInventory(size + 1);

    newItem->name = n;
    newItem->qty  = q;
    newItem->cost = c;

    p_pItems[count] = newItem;

    count++;
}
void Inventory::subtractItem(string n, int q) {

    Item *blankItem = new Item;

}
Inventory::~Inventory() {

    for(int i = 0; i < count; i++)
        delete p_pItems[i];

    delete[] p_pItems;
}




