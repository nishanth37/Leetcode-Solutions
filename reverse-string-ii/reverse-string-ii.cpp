class Solution {
public:
    void reverse(string& s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
    string reverseStr(string s, int k) {
        // edge case
        if(s.size() == 0) return 0;
        for(int i = 0; i < s.size();) {
            if(s.size() >= k+i) {
                reverse(s, i, i+k-1);
                i += 2*k;
            }
            else {
                reverse(s, i, s.size()-1);
                i += 2*k;
            }
        }
        return s;
    }
};