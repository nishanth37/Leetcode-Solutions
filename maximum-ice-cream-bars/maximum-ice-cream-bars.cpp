class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for(auto cost : costs) {
            if(coins >= cost) {
                coins -= cost;
                res++;
            }
            else
                break;
        }
        return res;
    }
};