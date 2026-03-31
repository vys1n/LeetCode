#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mapS, mapT;
        
        for (int i=0; i<s.size(); i++) {
            char ch_s = s[i], ch_t = t[i];
            
            if (mapS[ch_s] != mapT[ch_t]) return false;
            
            mapS[ch_s] = i+1;
            mapT[ch_t] = i+1;
        }
        
        return true;
    }
};
