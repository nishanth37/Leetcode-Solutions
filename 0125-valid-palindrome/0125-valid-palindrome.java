// T.C.: O(n) n - length of input String
// S.C.: O(1)
class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (Character.isLetterOrDigit(s.charAt(left))) {
                if (Character.isLetterOrDigit(s.charAt(right))) {
                    if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                        return false;
                    } else {
                        left++;
                        right--;
                    }
                } else {
                    right--;
                }
            } else {
                left++;
            }
        }
        return true;
    }
}