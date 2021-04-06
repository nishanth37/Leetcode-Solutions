/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "null";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr)
                str += "null,";
            else {
                str += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null") return nullptr;
        stringstream ss(data);
        vector<string> tokens;
        string temp;
        while(getline(ss, temp, ','))
            tokens.push_back(temp);
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int idx = 1;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(idx < tokens.size()) {
                if(tokens[idx] != "null") {
                    TreeNode* left = new TreeNode(stoi(tokens[idx]));
                    q.push(left);
                    curr->left = left;
                }
                idx++;
                if(tokens[idx] != "null") {
                    TreeNode* right = new TreeNode(stoi(tokens[idx]));
                    q.push(right);
                    curr->right = right;
                }
                idx++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));