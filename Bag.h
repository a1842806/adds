#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

template<class T>
class Bag {
private:
    vector<T> items;
public:
    void addItem(T item);
    void removeItem();
    void print();
};

template<class T>
void Bag<T>::addItem(T item) {
    items.push_back(item);
}

template<class T>
void Bag<T>::removeItem() {
    int idx = rand() % items.size();
    cout << idx << '\n';
    items.erase(items.begin() + idx);
}

template<class T>
void Bag<T>::print() {
    for (int i = 0; i < items.size(); ++i) {
        std::cout << items[i] << ' ';
    }
    std::cout << '\n';
}
