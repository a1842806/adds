#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;
        bool notFound = false;

        // tmp represents the prefixes of s2
        string tmp = s2.substr(0, 1);
        size_t found = s1.find(tmp); 
        result.push_back(found);
    
        for(size_t i = 1; i < s2.size(); i++) {
            if (notFound) {
                result.push_back(-1);
                continue;
            }
            tmp += s2[i];
            found = s1.find(tmp, found);
            if (found != string::npos) {
                result.push_back(found);
            } else {
                result.push_back(-1);
                notFound = true;
            }
        }
        return result;
    }

   