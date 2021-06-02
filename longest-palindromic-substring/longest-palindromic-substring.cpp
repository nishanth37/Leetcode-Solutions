// Extending around the center
// time: O(N^2) space: O(1)
class Solution {
public:
    int max;
    int start;
    string longestPalindrome(string s) {
        // edge case
        if(s.size() < 2) return s;
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            extendAroundIndex(s, i, i);
            if(i < n-1 and s[i] == s[i+1]) {
                extendAroundIndex(s, i, i+1); // even case
            }
            if(max == n)
                break;
        }
        return s.substr(start, max);
    }
private:
    void extendAroundIndex(string s, int left, int right) {
        while(left >= 0 and right < s.size() and s[left] == s[right]) {
            left--;
            right++;
        }
        if(max < right-left-1) {
            max = right-left-1;
            start = left+1;
        }
    }
};