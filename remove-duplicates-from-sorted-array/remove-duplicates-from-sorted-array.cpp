class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // edge case
        if(nums.size() == 0) return 0;
        int idx = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(prev != nums[i]) {
                prev = nums[i];
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};