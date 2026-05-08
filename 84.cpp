#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mA = 0;
        stack<int> st;

        for (int i=0; i<=n; i++) {
            while (!st.empty() && (i == n || heights[i] <= heights[st.top()])) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;
                mA = max(mA, h*w);
            }
            
            st.push(i);
        }
        
        return mA;
    }
};
