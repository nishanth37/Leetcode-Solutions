class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i < n+1; i++) {
            for(int k = 0, j = i-1; k <= j; k++,j--) {
                if(k == j)
                    dp[i] += dp[k]*dp[j];
                else
                    dp[i] += dp[k]*dp[j]*2;
            }
        }
        return dp[n];
    }
};