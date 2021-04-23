class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = INT_MAX;
        int moves = 0;
        for(int num : nums)
            minVal = min(minVal, num);
        for(int i = 0; i < nums.size(); i++) {
            moves += nums[i] - minVal;
        }
        return moves;
    }
};