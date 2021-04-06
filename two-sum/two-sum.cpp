class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator itr;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            itr = map.find(target-nums[i]);
            if(itr != map.end() && itr->second != i){
                res.push_back(i);
                res.push_back(itr->second);
                return res;
            }
        }
        return res;
    }
};