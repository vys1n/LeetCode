#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> counter;
        for (int num : nums){
            if(counter.count(num)){
                return true;
            }
            counter.insert(num);
        }
        return false;
    }
};

// Optimzed Solution
// TC = O(n)
// SC = O(n)
/* bool containsDuplicate(vector<int>& nums){
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
} */
