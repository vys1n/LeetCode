#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= res)
                res = i;
        }

        return res == 0;
    }
};
