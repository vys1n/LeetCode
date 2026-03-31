#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
                if (count > 1) res.push_back(ch);
            } else {
                count --;
                if (count > 0) res.push_back(ch);
            }
        }

        return res;
    }
};
