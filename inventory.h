#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <iostream>
#include <iomanip>
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
namespace inv {
    class Inventory {

    public:
        Inventory() : count{0}, p_pItems{new Item*[size]} {} // PRE  | |
                                                             // POST | Inventory object is intalized to the MAX_SIZE(50) |
        Inventory(int s) : size{s}, count{0}, p_pItems{new Item*[size]} {} // PRE  | s = number of item slots (size) |
                                                                           // POST | Inventory object is italized to have 's' number of item slots |
        Inventory(const Inventory& other); // PRE  | other = initalized Inventory object | 
                                           // POST | invoking Inventory object == other |

        void importInventoryFile(const string file); // PRE  | file = file name ; see "inventory.txt" for format | 
                                                     // POST | invoking Inventory object is == to file items, quantity, cost |
        void const printInventory(); // PRE  | invoking Inventory object has data in it |
                                     // POST | Inventory object is printed to console |

        double purchaseItem(const string n, const int q, Inventory& receipt); // PRE  | n = item name | q = item quantiy | receipt = receipt Inventory odj |
                                                                  // POST | total cost of purchase is returned as double | quantity of item is 
                                                                  // removed from invoking inventory list | quantity of item is added to 
                                                                  // receipt inventory list |

        int  searchItem(const string searchName); // PRE  | searchName = item name |
                                                  // POST | index location of item is returned as int |
        void addInventories(Inventory &i); // NOT USED INCOMPLETE
        void addNewItem(const string n, const int q, const float c); // PRE  | n = item name | q = item quantity | c = item cost |
                                                                     // POST | item is added to Inventory list in new slot |
        void addItem(const string n, const int q); // PRE  | n = item name | q = item quantity |
                                                   // POST | "item name" quantity is increased by 'q' amount | 
        void subtractItem(const string n, const int q); // PRE  | n = item name | q = item quantity |
                                                        // POST | "item name" quantity is decreased but 'q' amount | item slot is removed if quantity < 0 |

        ~Inventory(); // destructor

    private:
        int size{MAX_SIZE}; // MAX_SIZE = 50
        int count; // list count
        Item **p_pItems;
        // p->items[];
        void resizeInventory(const int s); // PRE  | s = new size (slot number) | 
                                           // POST | Inventorys size increases to new size | only increased Inventory size | can not decrease Inventory size |

    };
}


#endif
