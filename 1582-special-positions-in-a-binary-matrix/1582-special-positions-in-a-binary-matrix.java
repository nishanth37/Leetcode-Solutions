// T.C.: O(m.n.(m + n)) - m - rows in matrix, n - columns in matrix
// O(m.n) for traversing each element in matrix
// For each cell in matrix, we perform over m traversal of the same column and n traversal of the same row. That is additional O(m + n) time

// S.C.: O(1)

class Solution {
    private boolean rowElements(int position, int row, int[][] mat) {
        for (int i = 0; i < mat[row].length; i++) {
            if (i != position && mat[row][i] == 1) {
                return false;
            }
        }
        return true;
    }

    private boolean colElements(int position, int col, int[][] mat) {
        for (int i = 0; i < mat.length; i++) {
            if (i != position && mat[i][col] == 1) {
                return false;
            }
        }
        return true;
    }

    public int numSpecial(int[][] mat) {
        int res = 0;
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1) {
                    if (rowElements(j, i, mat) && colElements(i, j, mat)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
}