#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        getParts(s,part);
        return ans;
    }

    void getParts(string s, vector<string> &part) {
        if (s.size() == 0) {
            ans.push_back(part);
            return;
        }


        for (int i=0; i<s.size(); i++) {
            string p = s.substr(0, i+1);
            if (isPalindrome(p)) {
                part.push_back(p);
                getParts(s.substr(i+1), part);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        return s == s2;
    }
};

/* class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0,0,s,part);
        return ans;
    }

    void dfs(int j, int i, string &s, vector<string> &part) {
        if (i >= s.size()) {
            if (i == j)
                ans.push_back(part);
            return;
        }

        if (isPalindrome(s, j, i)) {
            part.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1, s, part);
            part.pop_back();
        }

        dfs(j, i+1, s, part);
    }

    bool isPalindrome(string &s, int l, int r) {
        if (s.length() == 1) return true;

        while (l<r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }

        return true;
    }
}; */
