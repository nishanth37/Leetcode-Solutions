class Solution {
public:
    bool checkIfPangram(string sentence) {
        // edge case
        if(sentence.size() < 26) return false;
        unordered_set<char> set;
        for(auto c : sentence) {
            if(set.find(c) == set.end())
                set.insert(c);
            if(set.size() == 26)
                return true;
        }
        return false;
    }
};