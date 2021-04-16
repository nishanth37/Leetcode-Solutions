class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // edge case
        if(digits.size() == 0) return {};
        // hashmap
        unordered_map<char, vector<string>> map;
        map['2'] = {"a", "b", "c"};
        map['3'] = {"d", "e", "f"};
        map['4'] = {"g", "h", "i"};
        map['5'] = {"j", "k", "l"};
        map['6'] = {"m", "n", "o"};
        map['7'] = {"p", "q", "r", "s"};
        map['8'] = {"t", "u", "v"};
        map['9'] = {"w", "x", "y", "z"};
        vector<string> res = map[digits[0]];
        vector<string> temp;
        for(int i = 1; i < digits.size(); i++) {
            temp = res;
            res.clear();
            for(int j = 0; j < temp.size(); j++) {
                vector<string> arr = map[digits[i]];
                for(int k = 0; k < arr.size(); k++) {
                    res.push_back(temp[j] + arr[k]);
                }
            }
        }
        return res;
    }
};