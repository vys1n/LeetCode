class diagonalSum {
    public static void main(String[] args) {
        int[][] matrix1D = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
        int[][] matrix2D = {{1,2,3}, {5,6,7}, {9,10,11}};
        System.out.println(sumDiagonal(matrix1D));
        System.out.println(sumDiagonal(matrix2D));
    }

    public static int sumDiagonal(int[][] mat) {
        // brute force - O(n^2)
        // int sum = 0;
        // int r = mat.length;
        // int c = mat[0].length;
        //
        // for (int i=0; i<r; i++) {
        //     for (int j=0; j<c; j++) {
        //         // primary diagonal
        //         if (i == j)
        //             sum += mat[i][j];
        //         // secondary diagonal
        //         else if (i+j == r-1)
        //             sum += mat[i][j];
        //     }
        // }
        // return sum;

        // Optimal Solution - O(n)
        int sum = 0;
        int n = mat.length;
        for (int i=0; i<n; i++) {
            sum += mat[i][i];
            int j = mat.length - 1 - i;
            if (i != j)
                sum += mat[i][j];
        }
        return sum;
    }
}
