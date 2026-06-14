#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        count[0] = 1;
        int res { 0 };
        int sum { 0 };

        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            res += count[rem];
            count[rem]++;
        }

        return res;
    }
};
