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

class Solution {
public:
    vector<int> res;
    void helper(Node* curr) {
        // base case
        if(curr == nullptr) return ;
        
        // logic
        res.push_back(curr->val);
        for(int i = 0; i < curr->children.size(); i++) {
            helper(curr->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        // edge case
        if(root == nullptr) return {};
        helper(root);
        return res;
    }
};