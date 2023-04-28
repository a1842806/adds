#include "Node.h"

Node::Node() {

}

Node::Node(int val) {
    this->data = val;
}

int Node::getVal() { 
    return data; 
}

Node* Node::getNext() {
    return link;
}

void Node::next(Node* nextNode) {
    this->link = nextNode;
}

Node::~Node() {
    
}