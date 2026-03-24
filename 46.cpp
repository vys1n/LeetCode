#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, vector<int>(), nums);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, vector<int> temp, vector<int> &nums) {
        if (temp.size() == nums.size()) {
            res.push_back(vector<int>(temp));
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            backtrack(res, temp, nums);
            temp.pop_back();
        }
    }
};
