#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        vector<pair<char,int>> vec;
        string res;
        
        for(char ch : s) map[ch]++;
        // for(char ch : s) {
        //     if (map.find(ch) == map.end()) {
        //         map.insert({ch, 1});
        //     } else {
        //         map[ch]++;
        //     }
        // }

        for (auto p : map) vec.push_back(p);

        // sort(vec.begin(), vec.end(), greater<int>());
        sort(vec.begin(), vec.end(), [](auto a, auto b) { return a.second > b.second; });

        for (auto i : vec) res += string(i.second, i.first);

        return res;
    }
};

