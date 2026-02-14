#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int start = BS(nums, target, n);

        if (start == n || nums[start] != target) {
            return {-1, -1};
        }

        int end = BS(nums, target + 1, n) - 1;

        return {start,end};
    }

private:
    int BS(vector<int>& nums, int target, int n) {
        int l = 0;
        int r = n;

        while (l < r) {
            int m = l + (r - l)/2;

            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
