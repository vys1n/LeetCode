#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int res = right;

        while (left <= right) {
            int cap = left + (right - left) / 2;

            if (canShip(weights, cap, days)) {
                res = min(res, cap);
                right = cap - 1;
            }
            else
                left = cap + 1;
        }

        return res;
    }

private:
    bool canShip(vector<int>& weights, int cap, int days) {
        int ships = 1, currCap = cap;

        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                
                if (ships > days)
                    return false;
                
                currCap = cap;
            }
            
            currCap -= w;
        }

        return true;
    }
};
