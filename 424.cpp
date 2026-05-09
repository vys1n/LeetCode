#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> cnt;
        int l = 0, maxf = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            maxf = max(maxf, cnt[s[r]]);

            while ((r - l + 1) - maxf > k) {
                cnt[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
