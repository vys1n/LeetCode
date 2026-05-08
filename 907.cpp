#include <vector>
#include <stack>
using namespace std;

// #define ll long long
// typedef long long ll;
using ll = long long;

class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        int n = arr.size();
        ll sum = 0;

        for (int i=0; i<n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;

            sum = (sum + (left * right % mod) * arr[i]) % mod;
        }

        return sum;
    }

private:
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }
        
        return res;
    }

    vector<int> findpse(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n,-1);
        stack<int> st;
        
        for (int i=0; i<n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) { st.pop(); }
            if (!st.empty()) { res[i] = st.top(); }
            st.push(i);
        }
        
        return res;
    }
};
