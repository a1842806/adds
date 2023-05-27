#include <string>
#include <vector>
#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    Document doc(name, id, license_limit);
    documents.push_back(doc);
}

void DocumentManager::addPatron(int patronID) {
    patrons[patronID] = 0;
}

int DocumentManager::search(std::string name) {
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i].name == name) {
            return documents[i].id;
        }
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i].id == docid) {
            if (documents[i].copies_borrowed < documents[i].license_limit) {
                documents[i].copies_borrowed++;
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i].id == docid) {
            documents[i].copies_borrowed--;
        }
    }
}