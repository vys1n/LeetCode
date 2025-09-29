#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) {
            return true;
        }

        else {
            for (int i=0; i<s.length(); i++) {
                if ((s[i] >= '0' && s[i] <= '9') ||
                    (s[i] >= 'A' && s[i] <= 'Z') ||
                    (s[i] >= 'a' && s[i] <= 'z')) {
                    if (s[i] >= 65 && s[i] <= 90) {
                        s[i] += 32;
                    }
                    // cout << s[i];
                }

                else {
                    s.erase(i,1);
                    i--;
                }
            }
        }
        // cout << endl;
        return false;
    }
};
