#include <vector>
#include <string>
#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAccess) {
    Node *current = root;

    for (char c : networkAccess) {
        int index = c - '0';
        if (!current->children[index]) break;
        current = current->children[index];
    }

    while (!current->isWord) {
        for (Node *child : current->children) {
            if (child) {
                current = child;
                break;
            }
        }
    }
    
    return current->index;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    Node *current = root;

    for (char c : address) {
        int index = c - '0';
        if (!current->children[index]) 
            current->children[index] = new Node(c);
        current = current->children[index];
    }

    current->isWord = true;
    current->index = routerNumber;
}