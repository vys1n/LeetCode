#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() > 1) {
            unordered_set<int> s(nums.begin(), nums.end());
            vector<int> uniq(s.begin(), s.end());
            sort(uniq.begin(), uniq.end());
            int current_streak = 1;
            int longest_streak = 1;
            int sz = uniq.size();
            for (int i=0; i<sz-1; i++) {
                if ((uniq[i+1] - uniq[i]) == 1) {
                    current_streak++;
                    if (current_streak >= longest_streak) {
                        longest_streak = max(longest_streak, current_streak);
                    }
                }
                else {
                    current_streak = 1;
                }
            }
            return longest_streak;
        }
        else if (nums.size() == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

/* Brute Force

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for (int num : nums) {
            int streak = 0, curr = num;
            while (store.find(curr) != store.end()) {
                streak++;
                curr++;
            }
            res = max(res, streak);
        }
        return res;
    }
};

Time & Space Complexity

    Time complexity: O(n^2)
    Space complexity: O(n)
*/

/* Sorting

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int res = 0, curr = nums[0], streak = 0, i = 0;

        while (i < nums.size()) {
            if (curr != nums[i]) {
                curr = nums[i];
                streak = 0;
            }
            while (i < nums.size() && nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            res = max(res, streak);
        }
        return res;
    }
};

Time & Space Complexity

    Time complexity: O(nlogn)
    Space complexity: O(1) or O(n) depending on the sorting algorithm.
*/

/* Hash Set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

Time & Space Complexity

    Time complexity: O(n)
    Space complexity: O(n)
*/

/* Hash Map

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;

        for (int num : nums) {
            if (!mp[num]) {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                res = max(res, mp[num]);
            }
        }
        return res;
    }
};

Time & Space Complexity

    Time complexity: O(n)
    Space complexity: O(n)
*/
