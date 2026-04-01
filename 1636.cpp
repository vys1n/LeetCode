#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int i : nums) count[i]++;

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if (count[a] != count[b]) return count[a] < count[b];
            return a > b;
        });

        return nums;
    }
};
