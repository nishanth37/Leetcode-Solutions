// Time Complexity: O(N) N = s.size()
/*
Although there is a loop inside a loop, the time complexity is still O(N). This is because the inner while loop is bounded by the total number of elements added to the stack (each time it fires an element goes). This means that the total amount of time spent in the inner loop is bounded by O(N), giving us a total time complexity of O(N).
*/
// Space Complexity: O(26) = O(1) The set 'seen' and the map will contain only unique elements
                        // So, max size is 26 only.
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // edge case
        if(s.size() == 0) return "";
        string res = "";
        stack<char> stack;
        // to maintain last occurrence of unique characters
        unordered_map<char,int> map;
        
        // to check if the character is already in the stack
        unordered_set<char> seen;
        
        for(int i = 0; i < s.size(); i++)
            map[s[i]] = i;
        
        for(int i = 0; i < s.size(); i++) {
            //try to add s[i] if it's not already in our solution
            if(seen.find(s[i]) == seen.end()) {
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while(!stack.empty() && s[i] < stack.top()
                  && map[stack.top()] > i) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(s[i]);
                stack.push(s[i]);
            }
        }
        while(!stack.empty()) {
            res = stack.top() + res;
            stack.pop();
        }
            
        return res;
    }
};