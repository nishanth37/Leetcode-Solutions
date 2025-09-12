// T.C.: O(n) n - string length
// S.C.: O(1)
// Actual requirement is only to check if Alice can win. Alice can win as long as there is at least one vowel in the string.
class Solution {
    public boolean doesAliceWin(String s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;
        }
        return false;
    }
}