class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<vector<int>> graph, int index, vector<int> path) {
        // base
        if(path.back() == graph.size()-1) {
            res.push_back(path);
            return;
        }
        // logic
        for(int i = 0; i < graph[index].size(); i++) {
            // action
            path.push_back(graph[index][i]);
            // recurse
            helper(graph, graph[index][i], path);
            // backtrack
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // edge case
        if(graph.size() == 0) return {};
        
        helper(graph, 0, {0});
        return res;
    }
};