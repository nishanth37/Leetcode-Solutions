class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> map;
        string str = paths[0][0];
        for(auto path : paths) {
            map[path.front()] = path.back();
        }
        
        while(true) {
            if(map.find(str) != map.end())
                str = map[str];
            else
                return str;
        }
        return "";
    }
};