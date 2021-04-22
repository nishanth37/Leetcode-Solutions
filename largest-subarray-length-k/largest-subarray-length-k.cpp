// Time Complexity: O(N) N = nums length
// Space Complexity: O(1)
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        // edge case
        if(nums.size() == 0 || k == 0) return {};
        int n = nums.size();
        int maxVal = nums[0];
        int start = 0;
        /* since all elements of nums are unique, we can find the
           find the largest subarray by finding the maximum among all the
           first element in each subarray.
        */
        for(int i = 1; i < n-k+1; i++) {
            if(maxVal < nums[i]) {
                maxVal = nums[i];
                start = i;
            }       
        }
        // returning the sub-vector of length 'k'
        return vector<int>(nums.begin()+start, nums.begin()+start+k);
    }
};