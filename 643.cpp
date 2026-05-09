#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (nums.size() == 1) return nums[0];

        if (nums.size() == k) {
            int sum = 0;
            for (int i = 0; i<n; i++)
                sum += nums[i];
            return (double)sum / k;
        }

        int windSum = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxSum = windSum;

        for (int i=k; i<n; i++) {
            windSum += nums[i] - nums[i-k];
            maxSum = max(maxSum, windSum);
        }

        return (double)maxSum / k; 
    }
};
