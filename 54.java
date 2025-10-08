import java.util.List;
import java.util.ArrayList;

class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int SR = 0;
        int SC = 0;
        int ER = matrix.length - 1;
        int EC = matrix[0].length - 1;

        while(SR <= ER && SC <= EC) {
            for (int j = SC; j <= EC; j++) {
                result.add(matrix[SR][j]);
            }
            
            for (int i = SR + 1; i <= ER; i++) {
                result.add(matrix[i][EC]);
            }
            
            for (int j = EC - 1; j >= SC; j--) {
                if (SR == ER)
                    break;
                result.add(matrix[ER][j]);
            }
            
            for (int i = ER - 1; i >= SR + 1; i--) {
                if (SC == EC)
                    break;
                result.add(matrix[i][SC]);
            }

            SR++;
            SC++;
            ER--;
            EC--;
        }

        return result;
    }
}
