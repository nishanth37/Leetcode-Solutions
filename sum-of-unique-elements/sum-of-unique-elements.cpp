class Solution {
public:
    int sumOfUnique(vector<int>& arr) {
        // edge case
    if(arr.size() == 0) return 0;
    int sum = 0;
    unordered_map<int, int> map;
    for(int i : arr) {
        map[i]++;
    }
    
    for(auto i : map) {
        if(i.second == 1)
            sum += i.first;
    }
    
    return sum;
    }
};