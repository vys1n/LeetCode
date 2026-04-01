#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0, n = s.size();

        for (char ch : s) {
            if (ch == letter) count++;
        }

        return (count * 100) / n;
    }
};
