// Time Complexity: O(log(x))
// Space Complexity: O(1)
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int lastDigit = x%10;
            x /= 10;
            if(rev > INT_MAX/10 or (rev == INT_MAX/10 and lastDigit > 7))
                return 0;
            if(rev < INT_MIN/10 or (rev == INT_MIN/10 and lastDigit < -8))
                return 0;
            rev = rev*10 + lastDigit;
        }
        return rev;
    }
};