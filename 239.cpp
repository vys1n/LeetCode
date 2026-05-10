#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 || k == 1) return nums;
        vector<int> res;
        deque<int> q;
        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r])
                q.pop_back();
            q.push_back(r);

            if (l > q.front())
                q.pop_front();

            if (r+1 >= k) {
                res.push_back(nums[q.front()]);
                l++;
            }

            r++;
        }

        return res;
    }
};
