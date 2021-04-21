// Time Complexity: O(N) N = data.size()
// Space Complexity: O(1)
class Solution {
public:
    int minSwaps(vector<int>& data) {
        // edge case
        if(data.size() == 0) return 0;
        int nOnes = 0;
        int nZeros = 0;
        int minZeros = INT_MAX;
        for(auto i : data) {
            if(i == 1)
                nOnes++;
        }
            
        for(int i = 0; i < data.size(); i++) {
            // incoming
            if(data[i] == 0) {
                nZeros++;
            }
            
            // outgoing
            if(i >= nOnes) {
                if(data[i-nOnes] == 0)
                    nZeros--;
            }
            if(i >= nOnes-1)
                minZeros = min(minZeros, nZeros);
        }
        return minZeros;
    }
};