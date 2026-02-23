// T.C.: O(NK) - we need to iterate the string, and use O(K) to calculate the hash of each substring.
// S.C.: O(NK) - There are at most N strings with length K in the set.
class Solution {
    public boolean hasAllCodes(String s, int k) {
        int need = 1 << k;
        Set<String> got = new HashSet<>();

        for(int i = k; i <= s.length(); i++) {
            String subStr = s.substring(i - k, i);
            if (!got.contains(subStr)) {
                got.add(subStr);
                need--;
                if (need == 0) {
                    return true;
                }
            }
        }
        return false;
    }
}