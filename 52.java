class Solution {
    int count;
    public int totalNQueens(int n) {
       char[][] board = new char[n][n];
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                board[r][c] = '.';
            }
        }
        nQueens(board, 0);
        return count;
    }
    
    private void nQueens(char[][] board, int row){
        if (row == board.length){
            count++;
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
