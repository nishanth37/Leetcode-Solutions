class Solution {
public:
    bool isArmstrong(int n) {
        int val = n;
        int val2 = 0;
        vector<int> arr;
        while(n) {
            arr.push_back(n%10);
            n /= 10;
        }
        int size = arr.size();
        for(int num : arr) {
            val2 += pow(num, size);
        }
        return (val == val2);
    }
};