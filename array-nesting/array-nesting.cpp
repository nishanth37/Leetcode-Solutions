class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // base case
        if(nums.size() == 1) return 1;
        int res = 0;
        set<int> set;
        int val;
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            val = nums[i];
            while(set.find(val) == set.end()) {
                set.insert(nums[i]);
                count++;
                val = nums[val];
            }
            res = max(res, count);
        }
        return res;
    }
};