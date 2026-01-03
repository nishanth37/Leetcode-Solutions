// T.C.: O(n)
// S.C.: O(1)
// Primary Technique: Dynamic Programming + Pattern Recognition
// Breakdown:

// Pattern Classification: Group 12 patterns into 2 types (x: Alternating and y: All Different)
// State Transition: Calculate next row possibilities from current row
// Space Optimization: Only track 2 variables instead of all 12 patterns
class Solution {
    public int numOfWays(int n) {
        final int MOD = 1000000007;
        // x - alternating colors like RYR, YRY, GRG, RGR, YGY, GYG - 6 patterns
        // y - all different colrs like RYG, RGY, YRG, YGR, GRY, GYR - 6 patterns
        long x = 6, y = 6;

        for (int i = 2; i <= n; i++) {
            // next_x (Alternating) → next row: Can form 3 Alternating + 2 All Different patterns
            // next_y (All Different) → next row: Can form 2 Alternating + 2 All Different patterns
            long new_x = (3*x + 2*y) % MOD;
            long new_y = (2*x + 2*y) % MOD;
            x = new_x;
            y = new_y;
        }
        return (int) ((x+y) % MOD);
    }
}