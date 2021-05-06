// Time Complexity: O(NlogN) N = #elements in boxTypes
// Space Complexity: O(1)
class Solution {
public:
    struct custSort {
        bool operator()(vector<int>& v1, vector<int>& v2) {
            return v1[1] > v2[1];
        }
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // edge case
        if(boxTypes.size() == 0) return 0;
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), custSort());
        for(auto box : boxTypes) {
            if(truckSize >= box[0]) {
                truckSize -= box[0];
                res += box[0]*box[1];
            }
            else {
                res += truckSize*box[1];
                break;
            }
        }
        return res;
    }
};

