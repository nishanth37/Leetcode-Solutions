// T.C.: O(n) - n - length of the string
// S.C.: O(1)
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}