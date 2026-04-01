#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = 0;
        for (char ch : s) {
            if (ch == '(') {
                count++;
                ans = max(ans, count);
            }
            
            if (ch == ')') {
                count--;
                ans = max(ans, count);
            }
        }

        return ans;
    }
};
