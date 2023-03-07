#include "inventory.h"
namespace inv {
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
void Inventory::importInventoryFile(const string file) {

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

        addNewItem(name, qty, cost); 
    }
}
void const Inventory::printInventory() {

    cout << "Name of Equipment | Cost | Quantity" << endl;
    for(int i = 0; i < count; i++) {

        cout << p_pItems[i]->name << " | ";
        cout << p_pItems[i]->cost << " | ";
        cout << p_pItems[i]->qty;
        cout << endl;
    }
    cout << endl;
}
double Inventory::purchaseItem(const string n, const int q, Inventory& receipt) {

    int indexLoc;
    double cost, total;
    indexLoc = searchItem(n);
    cost = p_pItems[indexLoc]->cost;

    subtractItem(n, q);

    receipt.addNewItem(n, q, cost);

    return total = (cost * q);
}
void Inventory::addInventories(Inventory &i) {

    if(count > i.count) {
        int tempCount = i.count;
        for(int j = 0; j < count; j++) {
            int indexLoc = 0;
            indexLoc = i.searchItem(p_pItems[j]->name);
            if(indexLoc == -1) {}
                // item is not present is &i inventory
            else {p_pItems[j]->qty += i.p_pItems[indexLoc]->qty;}
            

        }

    }

}
int Inventory::searchItem(const string searchName) {

    int indexLoc = 0;
    while(p_pItems[indexLoc]->name != searchName && indexLoc <= count) 
        indexLoc++;

    if(indexLoc > count)
        indexLoc = -1;

    return indexLoc;
}
void Inventory::resizeInventory(const int newSize) {

    Item **newItems = new Item*[newSize];
    
    for(int i = 0; i < count; i++) 
        newItems[i] = p_pItems[i];

    for(int i = count; count < newSize; count++)
        newItems[i] = new Item;

    delete[] p_pItems;
    p_pItems = newItems;
    size = newSize;
}
void Inventory::addNewItem(const string n, const int q, const float c) {

    Item *newItem = new Item;
    if(count >= size)
        resizeInventory(size + 1);

    newItem->name = n;
    newItem->qty  = q;
    newItem->cost = c;

    p_pItems[count] = newItem;

    count++;
}
void Inventory::addItem(const string n, const int q) {

    int indexLoc = 0;

    indexLoc = searchItem(n);
    p_pItems[indexLoc]->qty += q;
}
void Inventory::subtractItem(const string n, const int q) {

    int indexLoc = 0;

    indexLoc = searchItem(n);
    p_pItems[indexLoc]->qty -= q;

    // if quantity of item is 0 item is removed from list
    if(p_pItems[indexLoc]->qty <= 0) {
        
        delete p_pItems[indexLoc];
        count--;

        while(indexLoc < count) { // shift indexes to reduce count by 1
            p_pItems[indexLoc] = p_pItems[indexLoc + 1];        
            indexLoc++;
        }
    }
}
Inventory::~Inventory() {

    for(int i = 0; i < count; i++)
        delete p_pItems[i];

    delete[] p_pItems;
}

}



