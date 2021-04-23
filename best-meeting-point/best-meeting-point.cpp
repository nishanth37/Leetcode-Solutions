// Same as LC 462. Minimum Moves to Equal Array Elements II
// Time Complexity: O(MN) M = #rows; N = #cols
// Space Complexity: O(MN)
class Solution {
public:
    void getX(vector<vector<int>> grid, int row, int col, vector<int>& xVals) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    xVals.push_back(i);
                }
            }
        }
    }
    void getY(vector<vector<int>> grid, int row, int col, vector<int>& yVals) {
        for(int j = 0; j < col; j++) {
            for(int i = 0; i < row; i++) {
                if(grid[i][j] == 1) {
                    yVals.push_back(j);
                }
            }
        }
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        // edge case
        if(grid.size() == 0) return 0;
        int moves = 0;
        int row = grid.size();
        int col = grid[0].size();
        int median_x, median_y;
        vector<int> xCoordinates, yCoordinates;
        
        // store all x-coordinates and y-coordinates in sorted order
        getX(grid, row, col, xCoordinates);
        getY(grid, row, col, yCoordinates);
                
        int n = xCoordinates.size();
        if(n%2 == 0) {
            median_x = (xCoordinates[n/2 - 1] + xCoordinates[n/2])/2;
            median_y = (yCoordinates[n/2 - 1] + yCoordinates[n/2])/2;
        }
        else {
            median_x = xCoordinates[n/2];
            median_y = yCoordinates[n/2];
        }
        for(int i = 0; i < n; i++) {
            moves += abs(xCoordinates[i] - median_x) + abs(yCoordinates[i] - median_y);
        }
        return moves;  
    }
};