// Time Complexity: O(32*num)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        int i;
        for(i = 0; i <= num; i++) { // O(num)
            int bits = 0;
            int n = i;
            while(n) { // O(32)
                bits++;
                n &= n-1;
            }
            res[i] = bits;
        }
        return res;
    }
};