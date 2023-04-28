#pragma once

class Node {
public:
    Node();
    Node(int val);
    int getVal();
    Node* getNext();
    void next(Node* nextNode);
    ~Node();
private:
    int data;
    Node* link;
};