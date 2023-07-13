class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> map;
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            
            if(map.find(prerequisites[i][1]) == map.end()) {
                vector<int> temp;
                temp.push_back(prerequisites[i][0]);
                map[prerequisites[i][1]] = temp;
            }
            else {
                map[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
        }
        
        // pushing all independent courses into the queue
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int currCourse = q.front();
            q.pop();
            for(int i = 0; i < map[currCourse].size(); i++) {
                indegree[map[currCourse][i]]--;
                if(indegree[map[currCourse][i]] == 0)
                    q.push(map[currCourse][i]);
            }
        }
        
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i]) return false;
        }
        return true;
    }
};