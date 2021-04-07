class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            if(set.find(s[i]) != set.end())
                cnt1++;
            if(set.find(s[j]) != set.end())
                cnt2++;
        }
        return (cnt1 == cnt2);
    }
};