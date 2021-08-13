class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> set;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(set.find({i,j}) == set.end() and matrix[i][j] == 0) {
                    for(int m = 0; m < matrix.size(); m++) {
                        if(matrix[m][j] != 0) {
                            matrix[m][j] = 0;
                            set.insert({m,j});
                        }
                    }
                    for(int n = 0; n < matrix[0].size(); n++) {
                        if(matrix[i][n] != 0) {
                            matrix[i][n] = 0;
                            set.insert({i,n});
                        }
                    }
                }
            }
        }
    }
};