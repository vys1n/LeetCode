#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0;
        int l = 0, m = 0;

        for (int r = 0; r<nums.size(); r++) {
            if (nums[r] % 2)
                odd++;

            while (odd > k) {
                if (nums[l] % 2)
                    odd--;
                l++;
                m = l;
            }

            if (odd == k) {
                while (!(nums[m] % 2))
                    m++;
                res += m-l+1;
            }
        }

        return res;
    }
};
