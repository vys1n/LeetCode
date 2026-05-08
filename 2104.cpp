#include <bits/stdc++.h>
using namespace std;

// #define ll long long
// typedef long long ll;
using ll = long long;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumMax(nums) - sumMin(nums));
    }

private:
    vector<int> NSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n);
        stack<int> st;

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }

        return res;
    }

    vector<int> NGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n);
        stack<int> st;

        for (int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }

        return res;
    }
    
    vector<int> PSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i=0; i<n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }

        return res;
    }
    
    vector<int> PGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i=0; i<n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }

        return res;
    }
    
    ll sumMin(vector<int>& nums) {
        vector<int> pse = PSE(nums);
        vector<int> nse = NSE(nums);
        int n = nums.size();
        ll sum = 0;

        for (int i=0; i<n; i++) {
            ll right = nse[i] - i;
            ll left = i - pse[i];
            
            ll freq = left * right;
            ll val = freq * nums[i];
            
            sum += val;
        }

        return sum;
    }
    
    ll sumMax(vector<int>& nums) {
        vector<int> pge = PGE(nums);
        vector<int> nge = NGE(nums);
        int n = nums.size();
        ll sum = 0;

        for (int i=0; i<n; i++) {
            ll left = i - pge[i];
            ll right = nge[i] - i;

            ll freq = left * right;
            ll val = freq * nums[i];

            sum += val;
        }

        return sum;
    }
};
