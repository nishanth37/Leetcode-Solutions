// T.C. -> O(n + k) Each of the 'k' update operations is done in constant O(1) time. The final cumulative sum transformation takes O(n) time always.
// S.C. -> O(1)
/* Approach: 
Starting from a zero-fill vector, the approach use a cumulative sum iteration:

1. For each update, increment in the vector the "start " with its value (this could happen several times for the same start)
2. Also for each update, decrement in the vector the one-past the "end" with its value (to cancel out the increment when we be doing the cumulative sum iteration)
3. Finally iterate the vector, adding the previous element value to the current
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(auto updt : updates) {
            res[updt.front()] += updt.back();
            if(updt[1] +1 < length)
                res[updt[1] + 1] -= updt.back();
        }
        
        for(int i = 1; i < length; i++)
            res[i] += res[i-1];
        
        return res;
    }
};