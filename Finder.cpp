#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;
        int found = -1; 

        // tmp represents the prefixes of s2
        string tmp = "";
    
        for(int i = 1; i <= s2.size(); i++) {
            tmp += s2[i - 1];
            if (found != -1 && s1[found + 1] == tmp.back()) { 
                result.push_back(found);
                continue;
            } 
            found = s1.find(tmp, found + 1);
            if (found != string::npos) {
                result.push_back(found);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }

   