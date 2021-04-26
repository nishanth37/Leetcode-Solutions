// Time Complexity: O(N) N = size of S
// Space Complexity: O(1)
class Solution {
public:
    bool isLetter(char c) {
        if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'))
            return true;
        return false;
    }
    string reverseOnlyLetters(string S) {
        // edge case
        if(S.size() == 0) return "";
        int l = 0;
        int r = S.size()-1;
        while(l < r) {
            if(isLetter(S[l]) and isLetter(S[r])) {
                swap(S[l], S[r]);
                l++;
                r--;
            }
            else if(isLetter(S[l]) and !isLetter(S[r]))
                r--;
            else if(!isLetter(S[l]) and isLetter(S[r]))
                l++;
            else {
                l++;
                r--;
            }
        }
        return S;
    }
};