#include "inventory.h"

// INVENTORY PROGRAM:
// create inventory objects with defaul alternate and copy constructors
// add and subtract from current list of items or add new items
// import inventories from text file see "inventory.txt" for format
// print inventories
// purchase items, creating a receipt with purchased items
// add total cost of purchased items and print total
//
int main() {

    // initalization of inventory, receipt, and total cost of purchase
    Inventory inv;
    Inventory receipt;
    double total;

    // importing inventory from text file into inv object
    inv.importInventoryFile("inventory.txt");
    Inventory copy(inv);

    // printing inventory and copy
    cout << "ORIGNIAL" << endl;
    inv.printInventory();
    cout << "COPY" << endl;
    copy.printInventory();
    
    // purchasing items, adding to receipt and total
    total = inv.purchaseItem("Nike Basetball Shoes", 10, receipt);
    total += inv.purchaseItem("Nike shorts", 5, receipt);

    // printing inventory and receipt
    inv.printInventory();
    receipt.printInventory();

    // calc total and print
    total = total + (total * .0825);
    cout << "RECEIPT TOTAL: " << total << endl;




    return 0;
}
