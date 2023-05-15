#pragma once

#include <string>
#include <vector>
#include <map>

struct Node {
    char letter;
    bool isWord;
    std::string word;
    std::vector<Node*> children;
    Node() : isWord(false), children(26, nullptr) {}
    Node(char letter) : letter(letter), isWord(false), children(26, nullptr) {}
};

class Autocomplete {
private:
    Node *root = new Node;
public:
    std::vector<std::string> getSuggestions(std::string partialWord);
    void insert(std::string word);
};