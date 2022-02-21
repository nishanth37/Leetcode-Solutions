class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0; // sum of digits
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int transform = 0;
        for(char c : s) {
            int val = c - 96;
            transform += sumOfDigits(val);
        }
        // decrementing k by 1 as first transform is performed in the above for loop
        k--; 
        
        while(k) {
            transform = sumOfDigits(transform);
            k--;
        }
        return transform;
    }
};