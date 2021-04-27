class Solution {
public:
    bool isPowerOfThree(int n) {
        // base case
        if(n <= 0) return false;
        if(abs(n) == 1) return true;
        // logic
        if(n%3 != 0) return false;
        return isPowerOfThree(abs(n/3));
    }
};