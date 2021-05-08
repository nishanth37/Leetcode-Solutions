// Time Complexity: O(N) N = nums.size()
// Space Complexity: O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int num : nums)
            map[num]++;
        for(auto it : map) {
            if(it.second > nums.size()/3)
                res.push_back(it.first);
        }
        return res;
    }
};