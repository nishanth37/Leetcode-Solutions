// Time Complexity: O(NlogN + MlogM) N = horizontalCuts.size(), M = verticalCuts.size()
// Space Complexity: O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MODULO = 1000000007;
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(verticalCuts.begin(), verticalCuts.end());
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        long maxHeight = max(horizontalCuts[0], h - horizontalCuts[n-1]);
        for(int i = 1; i < n; i++) 
            maxHeight = max((int)maxHeight, (horizontalCuts[i] - horizontalCuts[i-1]));
        maxHeight %= MODULO;
        long maxWidth = max(verticalCuts[0], w - verticalCuts[m-1]);
        for(int i = 1; i < m; i++) 
            maxWidth = max((int)maxWidth, (verticalCuts[i] - verticalCuts[i-1]));
        maxWidth %= MODULO;
        //return (long long)((maxWidth*maxHeight)%MODULO);
        return (int)(((maxWidth%MODULO) * (maxHeight%MODULO))%MODULO);
    }
};