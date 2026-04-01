#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> count;

        for (int i : nums) {
            if (i % 2 == 0) count[i]++;
        }

        if (count.empty()) return -1;

        int res = -1;
        int mFreq = 0;
        for (auto [val, freq] : count) {
            if (freq > mFreq) {
                mFreq = freq;
                res = val;
            }
        }

        return res;
    }
    
    int newSol(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = -1, curr = nums[0], count = 0, max = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                if (i>0 && nums[i] != nums[i-1]) {
                    curr = nums[i];
                    count = 0;
                }

                count++;

                if (count > max) {
                    max = count;
                    res = nums[i];
                }
            }
        }

        return res;
    }
};

