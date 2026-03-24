#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextSell = 0, nextBuy = 0;  // day i+1
        int currSell = 0, currBuy = 0;  // day i

        for (int i=prices.size()-1; i>=0; i--) {
            currBuy = max(nextBuy, -prices[i]+nextSell);
            currSell = max(nextSell, prices[i]+nextBuy);

            nextSell = currSell;
            nextBuy = currBuy;
        }

        return currBuy;
    }

    // almost my very own solution
    int greedy(vector<int>& prices) {
        int profit = 0;
        
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};
