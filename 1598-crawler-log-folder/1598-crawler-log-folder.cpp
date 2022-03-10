class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(auto log : logs) {
            if(res < 0) res = 0;
            if(log == "../") {
                res--;
            }
            else if(log == "./")
            {
                // remain in the same folder. so, do nothing
            }
            else {
                res++;
            }
        }
        return (res > 0 ? res : 0);
    }
};