// T.C.: O(m*n) m - #rows, #n - #cols
// S.C.: O(1)
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int ans[][] = new int[rows][cols];

        for (int i = 0; i < cols; i++) {
            int maxVal = Integer.MIN_VALUE;
            for (int j = 0; j < rows; j++) {
                maxVal = Math.max(maxVal, matrix[j][i]);
            }

            for (int j = 0; j < rows; j++) {
                if (matrix[j][i] == -1) {
                    ans[j][i] = maxVal;
                } else {
                    ans[j][i] = matrix[j][i];
                }
            }
        }
        return ans;
    }
}