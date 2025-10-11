#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && i < j) {
                    if (nums[i] + nums[j] == target) {
                        return {i,j};
                    }
                }
            }
        }
        return {};
    }
};


// Optimized Solution
// TC - O(n)
// SC - O(n)

/* vector<int> twoSum(vector<int>& nums, int target){
    int n = nums.size();
    unordered_map<int, int> prevMap;

    for (int i=0; i<n; i++){
        int diff = target - nums[i];
        if (prevMap.find(diff) != prevMap.end())
            return {prevMap[diff], i};
        prevMap.insert({nums[i], i});
    }
    return {};
} */

