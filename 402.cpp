#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char c : num) {
            while (k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        int i = 0;
        while (i < st.size() && st[i] == '0')
            i++;

        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }

private:
    string twoPointersRemoveKdigits(string num, int k) {
        int l = 0;
        for (int r=0; r < num.size(); r++) {
            while (l>0 && k>0 && num[l-1] > num[r]) {
                l--;
                k--;
            }
            
            num[l++] = num[r];
        }

        l -= k;
        int i = 0;
        while (i<l && num[i] == '0')
            i++;

        if (i == l) return "0";
        return num.substr(i, l-i);
    }
};
