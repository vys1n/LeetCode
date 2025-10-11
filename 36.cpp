#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, int> row;
    vector<vector<char>> col(9);
    unordered_map<int, vector<char>> grid;

    for (int r=0; r<9; r++) {
        for (int c=0; c<9; c++) {
            char ch = board[r][c];
            if (ch >= '1' && ch <= '9') {
                row[ch-'0']++;
                col[c].push_back(ch);
            }
        }
        for (auto& pair : row) {
            // cout << pair.first << " : " << pair.second << endl;
            if (pair.second > 1) {
                cout << "row false ";
                return false;
            }
        }
        // cout << endl;
        row.clear();
    }
    
    for (auto& vec : col) {
        unordered_map<char, int> freq;
        for (char c : vec) {
            freq[c]++;
            if (freq[c] > 1) {
                cout << "col false ";
                return false;
            }
        }
    }

    for (int r=0; r<9; r++) {
        for (int c=0; c<9 ;c++) {
            if (board[r][c] >= '1' && board[r][c] <= '9') {
                int id = (r/3)*3 + (c/3);
                grid[id].push_back(board[r][c]);
            }
        }
    }

    for (auto& pair : grid) {
        unordered_map<char, int> freq;
        for (char c : pair.second) {
            freq[c]++;
            if (freq[c] > 1) {
                cout << "grid false";
                return false;
            }
        }
    }

    // for (auto& pair : grid) {
    //     cout << pair.first << " : ";
    //     for (auto& ch : pair.second) {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }

    return true; 
}

int main () {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // board[1][0] = '5';  // duplicate '5' in column 0
    // board[0][1] = '5';  // duplicate '5' in column 0

    // vector<vector<char>> board(9, vector<char>(9, '.'));

    // for(int i=0; i<9; i++){
    //     for(int j=0;j<9;j++){
    //         // cout << board[i][j] << "   ";
    //         // cout << i << '.' << j << "   ";
    //         // cout << i+j << "   ";
    //         // cout << (i/3)*3 + (j/3) << " ";
    //     }
    //     cout << endl;
    // }

    bool valid = isValidSudoku(board);
    cout << (valid ? "valid" : "invalid") << endl;

    // isValidSudoku(board);

    return 0;
}

/* Hash Set (One Pass)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                pair<int, int> squareKey = {r / 3, c / 3};

                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true;
    }
};

Time & Space Complexity

    Time complexity: O(n^2)
    Space complexity: O(n^2)
*/


/* Bitmask

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1';

                if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
                    (squares[(r / 3) * 3 + (c / 3)] & (1 << val))) {
                    return false;
                }

                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
            }
        }
        return true;
    }
};

Time & Space Complexity

    Time complexity: O(n^2)
    Space complexity: O(n)

*/
