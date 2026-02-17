#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curMax = 1;
        int curMin = 1;

        for (int num : nums) {
            int oldCurMax = num * curMax;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(oldCurMax, num * curMin), num);
            ans = max(ans, curMax);
        }

        return ans;
    }
};
