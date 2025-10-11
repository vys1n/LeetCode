#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string full;
        for (auto& word : strs) {
            full = full + to_string(word.size()) + '#' + word;
        }
        return full;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j + 1, len);
            res.push_back(word);
            i = j + 1 + len;
        }
        return res;
    }
};
