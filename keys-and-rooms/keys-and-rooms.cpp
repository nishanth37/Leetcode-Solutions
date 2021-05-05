// Time Complexity: O(E + V) E = number of keys V = number of rooms
// Space Complexity: O(V)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, -1); // space: O(V)
        queue<int> q; // space: O(V)
        q.push(0);
        while(!q.empty()) {// time: O(E)
            int curr = q.front();
            visited[curr] = 1;
            q.pop();
            for(int i = 0; i < rooms[curr].size(); i++) {
                if(visited[rooms[curr][i]] == -1) {
                    q.push(rooms[curr][i]);
                }
            }
        }
        
        for(auto i : visited) { // time: O(V)
            if(i == -1)
                return false;
        }
        return true;
    }
};