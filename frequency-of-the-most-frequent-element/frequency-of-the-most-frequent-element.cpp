// Time Complexity: O(NlogN) N = nums.size()
// Space Complexity: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        /*
        Sort the input array nums
        Sliding window prolem actually,
        the key is to find out the valid condition:
                k + sum >= size * max
        which is 
                k + sum >= (i-j+1)* nums[i]
        */
        int res = 1;
        int j = 0;
        long sum = 0;
        sort(nums.begin(), nums.end());
        /*
        For every new element nums[i] to the sliding window,
        Add it to the sum by sum += num[i].
        Check if it'a valid window by
                sum + k < (long)nums[i] * (i - j + 1)

        If not, removing A[i] from the window by
                sum -= nums[j] and j += 1.

        Then update the res by res = max(res, i - j + 1).
        */
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(k+sum < (long)nums[i]*(i-j+1)) {
                sum -= nums[j];
                j++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};