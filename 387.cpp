#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26,0);
        
        for (char ch : s) map[ch - 'a'] += 1;

        for (int i=0; i<s.size(); i++) {
            if (map[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};
