class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compareDist> pq;
        vector<vector<int>> res;
        for(auto point : points) {
            pq.push(point);
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
private:
    struct compareDist {
        bool operator()(vector<int> &p, vector<int> &q) {
            return (p[0]*p[0] + p[1]*p[1] < q[0]*q[0] + q[1]*q[1]);
        }
    };
};