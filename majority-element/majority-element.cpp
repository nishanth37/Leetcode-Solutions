class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // edge case
        if(nums.size() == 0) return 0;
        int n = nums.size();
        unordered_map<int,int> map;
        for(int num : nums) {
            map[num]++;
            if(map[num] > (n/2))
                return num;
        }
        return -1;
    }
};