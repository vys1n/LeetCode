#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, curr = 1;

        for (int i=1; i<s.length(); i++) {
            if (s[i] == s[i-1]) curr++;
            else {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        res += min(prev, curr);

        return res;
    }
};
