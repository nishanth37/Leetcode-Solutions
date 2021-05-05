// Time Complexity: O(E + V) E = Number of edges, V = Number of vertices
// Space Complexity: O(E + V)
class Solution {
public:
    vector<int> visited; // space: O(V)
    vector<vector<int>> adjList; // space: O(E)
    void bfs(int vertex) {
        queue<int> q; // space: O(V)
        q.push(vertex);
        visited[vertex] = 1;
        while(!q.empty()) { //  
            int curr = q.front();
            q.pop();
            for(int i : adjList[curr]) {
                if(visited[i] == -1) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // edge case
        if(edges.size() == 0) return n;
        
        int res = 0;
        visited.assign(n, -1);
        
        adjList.assign(n, vector<int>(0));
        for(auto edge : edges) { // time: O(E)
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < n; i++) { // time: O(V)
            if(visited[i] == -1) {
                res++;
                bfs(i);
            }
        }
        return res;
    }
};