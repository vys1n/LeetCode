#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int mn = prices[0];

        for (int i : prices) {
            mx = max(mx, i - mn);
            mn = min(mn, i);
        }

        return mx;
    }
};
