// Time Complexity: O(max(l1, l2)) l1 = length of s, l2 = length of t
// Space Complexity: O(max(l1,l2)) creating substring costs O(l1+l2) bcoz strings are immutable
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if(s == t or abs(l1-l2) > 1) return false;
        int i = 0;
        int j = 0;
        while(i < l1 and j < l2 and s[i] == t[j]) {
            i++;
            j++;
        }
        // If we reach end of both strings, it means both strings are same, so straight return false as same strings cannot be one edit distance apart.
        if(i == l1 and j == l2)
            return false;
        
        // If l1 > l2, which means s is longer than t, so only deletion is possible.
        if(l1 > l2) {
            return (s.substr(i+1) == t.substr(j));
        }
        else if(l1 < l2) { // If l1 < l2, which means s is shorter than t, so only insertion is possible.
            return (s.substr(i) == t.substr(j+1));
        }
        else { // If l1 == l2, which means s and t are of same length, so only replacing is possible. 
            return (s.substr(i+1) == t.substr(j+1));
        }
    }
};