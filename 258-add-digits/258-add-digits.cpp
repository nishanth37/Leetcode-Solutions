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
    int addDigits(int num) {
        while(true) {
            num = sumOfDigits(num);
            if(num/10 == 0)
                return num;
        }
        return 0;
    }
};