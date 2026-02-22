#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int water = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
            }
        }

        return water;
    }
};

// n = height.size()
// H = max_element
// T.C = O(H*n) or worst case - O(n^2)
// S.C = O(H*n) or worst case - O(n^2)
int mySolution(vector<int>& height) {
    int n = height.size();

    if (n == 1)
        return 0;

    int res = 0;
    int max = *max_element(height.begin(), height.end());

    vector<vector<int>> map(max, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<height[i]; j++) {
            map[j][i] = 1;
        }
    }

    for (int i=0; i<map.size(); i++){
        for (int j=0; j<n; j++){
            if (map[i][j] == 0) {
                map[i][j] = 1;
            } else {
                break; 
            }
        }
    }

    for (int i=0; i<map.size(); i++){
        for (int j=n-1; j>=0; j--){
            if (map[i][j] == 0) {
                map[i][j] = 1;
            } else {
                break; 
            }
        }
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        if (height[i] == max) {
            count++;
        }
    }

    if (count < 2) {
        map.pop_back();
    }

    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<n-1; j++) {
            if (map[i][j] == 0) {
                res++;
            }
        }
    }

    return res;
}

