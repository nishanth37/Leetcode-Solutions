class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int diff = (arr[n-1] - arr[0])/n;
        if(diff == 0) return arr[0];
        for(int i = 1; i < n; i++) {
            if(arr[i] != (arr[0]+i*diff))
                return (arr[0]+i*diff);
        }
        return 0;
    }
};