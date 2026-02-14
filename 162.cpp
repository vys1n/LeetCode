#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid > 0 && nums[mid] < nums[mid-1]) {
                r = mid - 1;
            }

            else if (mid < nums.size() - 1 && nums[mid] < nums[mid+1]) {
                l = mid + 1;
            }

            else {
                return mid;
            }

        }

        return -1;
    }
};
