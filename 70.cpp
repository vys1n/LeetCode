#include <cmath>
using namespace std;

class Solution {
public:
    // Binet's formula
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        n++;
        return round((pow(phi, n) - pow(psi, n)) / sqrt5);
    }

    // DP Space Optimized
    // int climbStairs(int n) {
    //     int one = 1, two = 1;
    //     for (int i = 0; i < n - 1; i++) {
    //         int temp = one;
    //         one = one + two;
    //         two = temp;
    //     }
    //     return one;
    // }

    // DP Bottom Up
    // int climbStairs(int n) {
    //     if (n <= 2) {
    //         return n;
    //     }
    //     vector<int> dp(n + 1);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }
};
