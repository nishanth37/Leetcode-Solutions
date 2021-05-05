// Time Complexity: O(N) N = nums.size()
// Space Complexity: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // edge case
        if(nums.size() < 2) return true;
        int nModify = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                nModify++;
                if(i < 1 or nums[i-1] <= nums[i+1])
                    nums[i] = nums[i+1];
                else
                    nums[i+1] = nums[i];
            }
                
            if(nModify == 2)
                return false;
        }
        return true;
    }
};