#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int idx { 0 };
        int len { 0 };

        for (int i { 0 }; i < s.size(); i++) {
            int l { i };
            int r { i };
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    idx = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    idx = l;
                    len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx, len);
    }
};
