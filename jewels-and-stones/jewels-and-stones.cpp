class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // edge case
        if(stones.size() == 0) return 0;
        int res = 0;
        unordered_map<char,int> map;
        for(auto i : stones)
            map[i]++;
        for(auto i : jewels) {
            if(map.find(i) != map.end())
                res += map[i];
        }
        return res;
    }
};