// Backtracking Solution
class Solution {
public:
    vector<string> res;
    unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void backtrack(string path, int index, string digits) {
        // base
        if(path.size() == digits.size()) {
            res.push_back(path);
            return ;
        }
        // logic
        string temp = map[digits[index]];
        for(int i = 0; i < temp.size(); i++) {
            // action
            path += temp[i];
            // recurse
            backtrack(path, index+1, digits);
            //backtrack
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string path = "";
        backtrack(path, 0, digits);
        return res;
    }
};