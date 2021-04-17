// Using DP
// Time Complexity: O(n*(sum/2)) n = stones.size() and sum = sum of weights of all stones in stones array
// Space Complexity: O((n+1) * (sum/2 + 1))
/*
This question eaquals to partition an array into 2 subsets whose difference is minimal
(1) S1 + S2  = S
(2) S1 - S2 = diff  

==> -> diff = S - 2 * S2  ==> minimize diff equals to  maximize S2 
Calculate S2 using DP.
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // edge case
        if(stones.size() == 0) return 0;
        int n = stones.size();
        int sum = 0;
        for(auto i : stones) sum += i;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, 0));
        for(int i = 1; i < n+1; i++) {
            for(int j = 0; j < sum/2 + 1; j++) {
                if(j >= stones[i-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (sum - 2*dp[n][sum/2]);
    }
};