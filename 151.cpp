#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;

        for (int i=n-1; i>=0; i--) {
            if (s[i] == ' ') continue;

            int j=i;
            while (j>=0 && s[j] != ' ') j--;

            if (!ans.empty()) ans += ' ';
            ans += s.substr(j+1, i-j);

            i = j+1;

        }

        return ans;
    }
};

