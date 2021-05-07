// Time COmplexity: O(N) N = nums.size()
// Space Complexity: O(1)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for(int num : nums) {
            if(num == target)
                count++;
            if(count > nums.size()/2)
                return true;
        }
        return false;
    }
};