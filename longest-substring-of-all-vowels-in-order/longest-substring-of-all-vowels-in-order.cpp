// Time Complexity: O(N) N = word.size()
// Space Complexity: O(1)
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        // edge case
        if(word.size() == 0) return 0;
        int cnt = 1;
        int len = 1;
        int res = 0;
        for(int i = 1; i < word.size(); i++) {
            if(word[i-1] == word[i]) {
                len++;
            }
            else if(word[i-1] < word[i]) {
                cnt++;
                len++;
            }
            else {
                cnt = 1;
                len = 1;
            }
            if(cnt == 5)
                res = max(res, len);
        }
        return res;
    }
};