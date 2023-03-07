#include "inventory.h"

int main() {

    Inventory inv;
    Inventory receipt;
    double total;

    inv.importInventoryFile("inventory.txt");

    inv.printInventory();

    inv.purchaseItem("Nike Basetball Shoes", 5, receipt, total);

    inv.printInventory();

    receipt.printInventory();
    cout << endl <<  "TOTAL: " << total;

    




    return 0;
}
