// time: O(N) N = nums.size(); space: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums)
            set.insert(num);
        int maxStreak = 0;
        for(int num : set) {
            if(set.find(num-1) == set.end()) {
                int currNum = num;
                int currStreak = 1;
                while(set.find(currNum+1) != set.end()) {
                    currNum++;
                    currStreak++;
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};