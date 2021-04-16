class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // edge case
        if(digits.size() == 0) return {};
        // hashmap
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        vector<string> res;
        for(int i = 0; i < map[digits[0]].size(); i++) {
            string str;
            str.append(1, map[digits[0]][i]);
            res.push_back(str);
        }  
        vector<string> temp;
        for(int i = 1; i < digits.size(); i++) {
            temp = res;
            res.clear();
            for(int j = 0; j < temp.size(); j++) {
                string str = map[digits[i]];
                for(int k = 0; k < str.size(); k++) {
                    res.push_back(temp[j] + str[k]);
                }
            }
        }
        return res;
    }
};