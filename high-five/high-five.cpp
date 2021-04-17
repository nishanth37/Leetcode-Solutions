class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // corner case
        if(items.size() == 0) return {};
        vector<vector<int>> res;
        map<int, vector<int>> map;
        for(int i = 0; i < items.size(); i++) {
            if(map.find(items[i][0]) == map.end())
                map[items[i][0]] = {items[i][1]};
            else
                map[items[i][0]].push_back(items[i][1]);
        }
        
        for(auto it : map) {
            vector<int> temp = it.second;
            priority_queue<int, vector<int>, greater<int>> pq; // minHeap
            int size = 0;
            for(auto i : temp) {
                if(size < 5) {
                    pq.push(i);
                    size++;
                }
                else {
                    int value = pq.top();
                    pq.pop();
                    value = max(value, i);
                    pq.push(value);
                }
            }
            int sum = 0;
            while(!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            res.push_back({it.first, sum/5});
        }
        return res;
    }
};