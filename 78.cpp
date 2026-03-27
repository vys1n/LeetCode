#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());

        for (int num : nums) {
            int sz = ans.size();
            for (int i=0; i<sz; i++) {
                vector<int> subset(ans.at(i));
                subset.push_back(num);
                ans.push_back(subset);
            }
        }

        return ans;
    }
};
