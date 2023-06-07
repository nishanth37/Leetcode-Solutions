class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int carry = 1;
        for(int i = n-1; i >= 0; i--) {
            if(digits[i] != 9) {
                digits[i] += carry;
                carry = 0;
                return digits;
            }
            else {
                carry = 1;
                digits[i] = 0;
            }
        }
        if(carry == 1) {
            int newarr[] = new int[n + 1];
            newarr[0] = carry;
            carry = 0;
            for(int i = 1; i < n; i++)
                newarr[i] = digits[i];
            return newarr;
        }
        return digits;
    }
}