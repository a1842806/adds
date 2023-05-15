#pragma once
#include <vector>
#include <string>

struct Node {
    char binary;
    bool isWord;
    int index;
    Node *children[2];
    Node() : isWord(false) {}
    Node(char bit) : binary(bit), isWord(false) {}
};

class PrefixMatcher {
private:
    Node *root = new Node;
public:
    int selectRouter(std::string networkAccess);
    void insert(std::string address, int routerNumber);
};