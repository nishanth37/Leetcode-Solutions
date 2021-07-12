class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;
        for(char c : allowed)
            set.insert(c);
        int res = 0;
        bool consistent;
        for(string word : words) {
            consistent = true;
            for(char c : word) {
                if(set.find(c) == set.end()) {
                    consistent = false;
                    break;
                }
            }
            if(consistent) res++;
        }
        return res;
    }
};