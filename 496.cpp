#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                int val = st.top();
                st.pop();
                mp[val] = num;
            }
            st.push(num);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back(mp.contains(num) ? mp[num] : -1);
        }

        return res;
    }
};
