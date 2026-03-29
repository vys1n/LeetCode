#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = {""};
        vector<string> digiCh = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   
        for (char digit : digits) {
            vector<string> tmp;
            for (string curStr : ans) {
                for (char ch : digiCh[digit - '0']) {
                    tmp.push_back(curStr + ch);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};


/* class Solution {
    vector<string> ans;
    vector<string> digiCh = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        backtrack(0, "", digits);
        return ans;
    }

    void backtrack(int i, string currStr, string &digits) {
        if (currStr.size() == digits.size()) {
            ans.push_back(currStr);
            return;
        }
        
        string chars = digiCh[digits[i] - '0'];
        for (char ch : chars)
            backtrack(i+1, currStr+ch, digits);
    }
}; */
