#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        // ["eat","tea","tan","ate","nat","bat"]
        // make a nested loop
        // for "eat", count the no. of chars (in the outer loop)
        // and compare with the no. of chars, with every other element (in the inner loop)
        // group the elements together and then delete the grouped elements

        for (const auto& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            res[key].push_back(s);
        }

        vector<vector<string>> result;
        // insert res.second in result
        for (auto& pair : res){
            result.push_back(pair.second);
        }
        
        return result;
    }
};


// TC - O(m*n)
// SC - O(m) extra space, O(m * n) output list

/* vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> res;
    for (const auto& s : strs){
        vector<int> count(26,0);
        for (char c : s){
            count[c - 'a']++;
        }
        string key = to_string(count[0]);
        for (int i=0; i<26; i++){
            key = key + ',' + to_string(count[i]);
        }
        res[key].push_back(s);
    }
    vector<vector<string>> result;
    for (const auto& pair : res){
        result.push_back(pair.second);
    }
    return result;
} */
