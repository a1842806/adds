#pragma once
 
#include <string>
#include <vector>
#include <unordered_map>

struct Document {
    std::string name;
    int id;
    int license_limit;
    int copies_borrowed;
    Document() : name(""), id(0), license_limit(0), copies_borrowed(0) {};
    Document(std::string name, int id, int license_limit) : name(name), id(id), license_limit(license_limit), copies_borrowed(0) {};
};

class DocumentManager {
private:
    std::vector<Document> documents;
    std::unordered_map<int, int> patrons;
public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection
    bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
    void returnDocument(int docid, int patronID); 
};