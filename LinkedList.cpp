#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) {
	if (pos1 < 0 || pos2 < 0) return false;
	Node* node1 = head;
	while (pos1--) {
		node1 = node1->link;
		if (node1 == NULL) return false;
	}
	Node* node2 = head;
	while (pos2--) {
		node2 = node2->link;
		if (node2 == NULL) return false;
	}
	int tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
	return true;
}

bool LinkedList::find_and_delete(int target) {
	Node* currNode = head;
	Node* prevNode = nullptr;
	while (currNode != nullptr) {
		if (currNode->data == target) {
			if (prevNode == nullptr) {
				head = currNode->link;
			} else {
				prevNode->link = currNode->link;
			}
			delete currNode;
			return true;
		}
		prevNode = currNode;
		currNode = currNode->link;
	}
	return false;
}