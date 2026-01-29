// T.C.: O(S) S - sum of all characters in all strings
// S.C.: O(1)
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++) {
            System.out.println("prefix: " + prefix);
            System.out.println("index of prefix: " + prefix + " " + strs[i].indexOf(prefix));
            while (strs[i].indexOf(prefix) != 0) {
            System.out.println("index of prefix: " + prefix + " " + strs[i].indexOf(prefix));
                prefix = prefix.substring(0, prefix.length() - 1);
                System.out.println("updated prefix: " + prefix);
                if (prefix.isEmpty()) return "";
            }
            System.out.println("index of prefix: " + prefix + " " + strs[i].indexOf(prefix));
        }
        return prefix;
    }
}