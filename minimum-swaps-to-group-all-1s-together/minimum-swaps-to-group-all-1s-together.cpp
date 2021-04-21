// Time Complexity: O(N) N = data.size()
// Space Complexity: O(1)
class Solution {
public:
    int minSwaps(vector<int>& data) {
        // edge case
        if(data.size() == 0) return 0;
        for(int i = 1; i < data.size(); i++) {
            data[i] += data[i-1];
        }
        
        int nOnes = data.back();
        if(nOnes == 0) return 0;
        int maxOnes = data[nOnes-1];
        
        for(int i = nOnes; i < data.size(); i++) {
            maxOnes = max(maxOnes, data[i]-data[i-nOnes]);
        }
        return nOnes-maxOnes;
    }
};