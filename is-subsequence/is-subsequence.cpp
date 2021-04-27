// Time Complexity: O(t.length)
// Space Complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if(s.size() == 0 and t.size() == 0) return true;
        int i = 0;
        for(int j = 0; j < t.size(); j++) {
            if(s[i] == t[j])
                i++;
        }
        return (i == s.size());
    }
};