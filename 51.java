import java.util.ArrayList;
import java.util.List;

class Solution {
    List<List<String>> result = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
       char[][] board = new char[n][n];
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                board[r][c] = '.';
            }
        }
        nQueens(board, 0);
        return result;
    }

    private List<String> construct(char[][] board){
        List<String> path = new ArrayList<>();
        for(int i=0; i<board.length; i++){
            path.add(new String(board[i]));
        }
        return path;
    }

    private void nQueens(char[][] board, int row){
        if (row == board.length){
            result.add(construct(board));
            return;
        }

        for (int col=0; col<board.length; col++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                nQueens(board, row+1);
                board[row][col] = '.';
            }
        }
    }

    private boolean isSafe(char[][] board, int row, int col){
        // vertical up (col same, row--, r--)
        for(int r = row-1; r>=0; r--){
            if(board[r][col] == 'Q')
                return false;
        }
        
        // left diagonal(r--, c--, r>=0, c>=0)
        for(int r = row-1, c = col-1; r>=0 && c>=0; r--, c--){
            if(board[r][c] == 'Q')
                return false;
        }
        
        // right diagonal(r--, c++, r>=0, c<board.lenght)
        for(int r = row-1, c = col+1; r>=0 && c<board.length; r--, c++){
            if(board[r][c] == 'Q')
                return false;
        }

        return true;
    }
}
