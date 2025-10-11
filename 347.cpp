#include <functional>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums){
            counter[num]++;
        }
        vector<pair<int,int>> arr;
        for (const auto& p : counter){
            arr.push_back({p.second, p.first});
        }
        sort(arr.begin(), arr.end(), greater<>());
        vector<int> result;
        for (int i=0; i<k; i++){
            result.push_back(arr[i].second);
        }
        return result;
    }
};

// Min-Heap Solution
// TC = O(n logk)
// SC = O(n+k)

/* class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
}; */

// Bucket-Sort
// TC - O(n)
// SC = O(n)
/* class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
}; */
