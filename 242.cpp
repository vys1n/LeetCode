#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int>countS;
        unordered_map<char, int>countT;
        for(int i=0; i < s.length(); i++){
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};

// TC - O(n+m)
// SC - O(1)

/* bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    vector<int> count(26, 0);
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int val : count) {
        if (val != 0) {
            return false;
        }
    }
    return true;
} */
