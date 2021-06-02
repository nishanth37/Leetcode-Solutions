// Time Complexity: O(NlogK) // O(N) to iterate the map and O(log) for heapify
// Space Complexity: O(N + K) 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map; // space : O(N) N = nums.size()
        priority_queue<vector<int>, vector<vector<int>>, compare> pq; // space : O(K)
        vector<int> res;
        for(auto num : nums) // time : O(N)
            map[num]++;
        for(auto i : map) { // time : O(NlogK)
            pq.push({i.first, i.second});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top()[0]);
            pq.pop();
        }
        return res;
    }
    
private:
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) {
            return (p[1] > q[1]);
        }  
    };
};