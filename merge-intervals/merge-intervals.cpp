// Time Complexity: O(NlogN) N = length of intervals vector
// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for(auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if(res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else 
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        return res;
    }
};