class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        // edge case
        if(grid.size() == 0) return 0;
        int moves = 0;
        int row = grid.size();
        int col = grid[0].size();
        int median_x, median_y;
        vector<int> xCoordinates, yCoordinates;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    xCoordinates.push_back(i);
                    yCoordinates.push_back(j);
                }
            }
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        sort(yCoordinates.begin(), yCoordinates.end());
        
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