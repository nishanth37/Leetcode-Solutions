class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size()-1;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(left < right) {
            if(set.find(s[left]) != set.end()) {
                if(set.find(s[right]) != set.end()) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                else {
                    right--;
                }
            }
            else {
                left++;
            }
        }
        return s;
    }
};