/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Level order traversal - BFS using queue
// Time Complexity: O(N) N. #nodes in N-ary tree
// Space Coplexity: O(N) max size of queue = N/2, N/2 leaf nodes will be added into the queue when it is a complete tree.
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // edge case
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                lvl.push_back(curr->val);
                for(Node* n : curr->children)
                    q.push(n);
            }
            res.push_back(lvl);
        }
        return res;
    }
};