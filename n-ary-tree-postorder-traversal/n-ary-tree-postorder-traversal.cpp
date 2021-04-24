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
// DFS recursion approach
// Time Complexity: O(N) N = #nodes in the N-ary tree
// Space Complexity: O(N) when tree is skewed, max size of recursive stack = N
class Solution {
public:
    vector<int> res;
    void helper(Node* curr) {
        // base
        if(curr == nullptr) return ;
        // logic
        for(int i = 0; i < curr->children.size(); i++) {
            helper(curr->children[i]);
        }
        res.push_back(curr->val);
    }
    vector<int> postorder(Node* root) {
        // edge case
        if(root == nullptr) return {};
        helper(root);
        return res;
    }
};