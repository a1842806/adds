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
};

template<class T>
void Bag<T>::addItem(T item) {
    items.push_back(item);
}

template<class T>
void Bag<T>::removeItem() {
    int idx = rand() % items.size();
    items.erase(items.begin() + idx);
}

