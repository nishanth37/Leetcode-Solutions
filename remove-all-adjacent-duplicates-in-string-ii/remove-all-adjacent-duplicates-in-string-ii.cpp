// Time Complexity; O(N) N = input string length
// Space Complexity: O(N) N = size of vector
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // edge case
        if(s.size() == 0) return {};
        string res = "";
        vector<pair<char,int>> freq; // character and its frequency
       
        for(int i = 0; i < s.size(); i++) {
            if(freq.empty() || s[i] != freq.back().first) 
                freq.push_back({s[i], 1});
            else if(++freq.back().second == k)
                freq.pop_back();                
        }
        for(auto &i : freq)
            res += string(i.second, i.first);
          
        return res;
    }
};