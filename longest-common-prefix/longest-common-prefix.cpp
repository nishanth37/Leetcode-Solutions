// Time Complexity: O(S) S = sum of all characters in all strings
// Space Complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // edge case
        if(strs.size() == 0) return "";
        int j;
        for(j = 0; j < strs[0].size(); j++) {
            for(int i = 0; i < strs.size()-1; i++) {
                if(j < strs[i].size() and j < strs[i+1].size() 
                   and strs[i][j] != strs[i+1][j]) {
                    if(strs[i].size() < strs[i+1].size())
                        return strs[i].substr(0, j);
                    else
                        return strs[i+1].substr(0, j);
                }
                else if(j == strs[i].size()) {
                    return strs[i].substr(0, j);
                }
                else if(j == strs[i+1].size()) {
                    return strs[i+1].substr(0, j);
                }
                    
            }
        }
        if(j == strs[0].size())
            return strs[0].substr(0, j);
        else
            return strs[0].substr(0, j-1);
    }
};