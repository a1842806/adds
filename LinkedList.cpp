#include <iostream>
#include <vector>
#include <climits>
#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList() {

}

LinkedList::LinkedList(int* array, int len) {
    Node* prevNode;
    for (int i = 0; i < len; ++i) {
        Node* nextNode = new Node(array[i]);
        if (i > 0) prevNode->next(nextNode);
        else head = nextNode;
        prevNode = nextNode;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* nextNode = head, *prevNode;
    Node* newNode = new Node(newNum);
    if (pos <= 1) {
        head = newNode;
        newNode->next(nextNode);
        return;
    }
    while (--pos && nextNode) {
        prevNode = nextNode;
        nextNode = nextNode->getNext();
    }
    prevNode->next(newNode);
    newNode->next(nextNode);
}

bool LinkedList::deletePosition(int pos) {
    if (pos < 1) return false;
    Node* nextNode = head;
    Node* prevNode = NULL;
    for (int i = 2; i <= pos; ++i) {
        prevNode = nextNode;
        nextNode = nextNode->getNext();
        if (nextNode == nullptr) return false;
    }
    if (prevNode) 
        prevNode->next(nextNode->getNext());
    else 
        head->next(nextNode->getNext());
    delete nextNode;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return INT_MAX;
    Node* cur = head;
    for (int i = 2; i <= pos; ++i) {
        cur = cur->getNext();
        if (cur == nullptr) return INT_MAX;
    }
    return cur->getVal();
}

int LinkedList::search(int target) {
    Node* cur = head;
    int cnt = 0;
    while (cur) {
        cnt++;
        if (cur->getVal() == target) return cnt;
        cur = cur->getNext();
    }
    return -1;
}

void LinkedList::printList() {
    Node* cur = head;
    if (!cur) return;
    std::cout << '[';
    while (cur) {
        std::cout << cur->getVal();
        cur = cur->getNext();
        if (cur) std::cout << ' ';
    }
    std::cout <<  "]\n";

}

LinkedList::~LinkedList() {
    while (head) {
        Node* cur = head->getNext();
        delete head;
        head = cur;
    }
}