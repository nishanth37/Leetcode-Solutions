class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> map;
        map['q'] = map['w'] = map['e'] = map['r'] = map['t'] = map['y'] = map['u'] = map['i'] = map['o'] = map['p'] = 1;
        map['a'] = map['s'] = map['d'] = map['f'] = map['g'] = map['h'] = map['j'] = map['k'] = map['l'] = 2;
        map['z'] = map['x'] = map['c'] = map['v'] = map['b'] = map['n'] = map['m'] = 3;
        vector<string> res = {};
        for(auto word: words) {
            int rowVal = map[tolower(word[0])];
            bool flag = true;
            for(auto c: word) {
                if(rowVal != map[tolower(c)]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(word);
        }
        return res;
    }
};