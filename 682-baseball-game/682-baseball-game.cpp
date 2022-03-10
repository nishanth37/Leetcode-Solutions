class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> val;
        for(auto op : ops) {
            if(op == "C")
                val.pop_back();
            else if(op == "D")
                val.push_back(val.back()*2);
            else if(op == "+")
                val.push_back(val.back() + val[val.size()-2]);
            else
                val.push_back(stoi(op));
        }
        int res = 0;
        for(auto v : val)
            res += v;
        return res;
    }
};