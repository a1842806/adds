#include <string>
#include <vector>
#include "Autocomplete.h"

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> suggestions;

    Node *current = root;
    for (char c : partialWord) {
        int index = c - 'a';    
        if (!current->children[index]) {
            return suggestions;
        }
        current = current->children[index];
    }

    std::vector<Node*> stack;
    stack.push_back(current);

    while (!stack.empty()) {
        current = stack.back();
        stack.pop_back();

        if (current->isWord) {
            suggestions.push_back(current->word);
        }

        for (Node *child : current->children) {
            if (child) stack.push_back(child);
        }
    }

    return suggestions;
}

void Autocomplete::insert(std::string word) {
    Node *current = root;

    for (char c : word) {
        int index = c - 'a';
        if (!current->children[index]) {
            current->children[index] = new Node(c);
        }
        current = current->children[index];
    }

    current->isWord = true;
    current->word = word;
}