#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res { 0 };
        int curSum { 0 };
        std::unordered_map<int, int> prefixSums {};
        prefixSums[0] = 1;

        for (int num : nums) {
            curSum += num;
            int diff { curSum - k };
            res += prefixSums[diff];
            prefixSums[curSum]++;
        }

        return res;
    }
};
