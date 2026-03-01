// T.C. : O(k) k = length of string 'n'
// S.C. : O(1)
class Solution {
    public int minPartitions(String n) {
        int max = 0;
        for(int i = 0; i < n.length(); i++) {
            if(n.charAt(i) - '0' == 9) return 9;
            else {
                max = Math.max(max, n.charAt(i) - '0');
            }
        }
        return max;
    }
}