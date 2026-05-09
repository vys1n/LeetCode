#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int l = 0, res = 0;

        for (int r=0; r<s.size(); r++) {
            cnt[s[r] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                res += s.size() - r;
                cnt[s[l] - 'a']--;
                l++;
            }
        }

        return res;
    }
};
