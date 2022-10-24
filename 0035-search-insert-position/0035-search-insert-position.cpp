class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        
        int left = 0;
        int right = nums.size()-1;
        int res = 0;
        int mid = 0;
        while(left < right) {
            mid = left + (right-left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        if(nums[left] >= target) return left;
        else return right+1;
    }
};