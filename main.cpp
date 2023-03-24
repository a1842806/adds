#include "Bag.h" 
#include <iostream>
#include <vector>

using namespace std;

void stars(int n) {
    if (n == 0) return;
    std::cout << '*';
    stars(n - 1);
}

int main() {
    Bag<string> myBag;
    myBag.addItem("A");
    myBag.addItem("B");
    myBag.addItem("C");
    myBag.addItem("E");
    myBag.print();

    myBag.addItem("C");
    myBag.addItem("E");
    myBag.print();
    myBag.removeItem();

    myBag.print();
    return 0;
}