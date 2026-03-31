#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return (s.size() == goal.size() && strstr((s+s).data(), goal.data()));
    }
};

/* bool rotateString(string s, string goal) {

    if(s.size() != goal.size()) return false;

    for(int i = 0; i < s.size(); i++){
        char first = s[0];
        s.erase(0,1);
        s.push_back(first);

        if(s == goal) return true;
    }

    return false;
} */
