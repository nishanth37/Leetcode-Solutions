// Using MaxHeap
// Time Complexity: O(NlogK) N = #points, logK for heapify
// Space Complexity: O(K)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compareDist> pq; // space: O(K)
        vector<vector<int>> res;
        for(auto point : points) { // time: O(N)
            pq.push(point);
            if(pq.size() > K)
                pq.pop();
        }
        while(!pq.empty()) { //time: O(K)
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
private:
    struct compareDist {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0]*p[0] + p[1]*p[1] < q[0]*q[0] + q[1]*q[1];
        }
    };
};