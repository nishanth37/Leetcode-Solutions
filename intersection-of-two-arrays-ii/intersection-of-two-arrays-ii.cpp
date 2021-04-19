class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // edge case
        if(nums1.size() == 0 || nums2.size() == 0) return {};
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        vector<int> res;
        for(int num : nums1)
            map1[num]++;
        for(int num : nums2)
            map2[num]++;
        for(int num : nums2) {
            if((map1.find(num) != map1.end())
            and (map2.find(num) != map2.end())
            and map1[num] != 0) {
                int minFreq = min(map1[num], map2[num]);
                for(int i = 0; i < minFreq; i++)
                    res.push_back(num);
                map1[num] = 0;
                map2[num] = 0;
            }
        }
        return res;
    }
};