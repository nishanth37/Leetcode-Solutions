class Solution {
    public int smallestNumber(int n) {
        int res = 0;
        int i = 0;
        while(res < n) {
            res += Math.pow(2, i);
            i++;
        }
        return res;
    }
}