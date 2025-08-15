class Solution {
    public boolean isPowerOfFour(int n) {
        if(n == 1) return true;
        if (n < 1) return false;
        while(n > 1) {
            if(n%4 != 0) {
                return false;
            } else {
                n /= 4;
            }
        }
        return true;
    }
}