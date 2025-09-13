#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unsorted.h"

int main() {
    UnsortedType list;
    ItemType item;
    bool found;
    int count = 0;

    std::srand(std::time(0));

    while (list.GetLength() < 50) {
        int randNum = std::rand() % 100;
        item.Initialize(randNum);
        item = list.GetItem(item, found);
        if (!found) {
            list.PutItem(item);
        }
    }

    list.ResetList();
    for (int i = 0; i < 50; i++) {
        item = list.GetNextItem();
        item.Print(std::cout);
        std::cout << "\t";
        if ((i+1) % 10 == 0) std::cout << std::endl;
    }

    return 0;
}
