#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int tick = 1;
        int zeroCount = 0;
        for (auto& num : nums) {
            if (num != 0)
                tick *= num;
            else
                zeroCount++;
        }
        if (zeroCount > 1) {
            return vector<int>(n, 0);
        }
        vector<int> answer(n);
        for (size_t i = 0; i<n; i++) {
            if (zeroCount > 0) {
                answer[i] = (nums[i] == 0) ? tick : 0;
            }
            else {
                answer[i] = tick / nums[i];
            }
        }
        return answer;
    }
};

/* Prefix & Suffix

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};

Time & Space Complexity

    Time complexity: O(n)O(n)
    Space complexity: O(n)O(n)
*/

/* Prefix & Suffix (Optimal)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};

Time & Space Complexity

    Time complexity: O(n)O(n)
    Space complexity:
        O(1)O(1) extra space.
        O(n)O(n) space for the output array.
*/
