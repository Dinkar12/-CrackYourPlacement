
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> paths;
        if (root == NULL) return paths;
        stack<pair<TreeNode*, string>> stk;
        stk.push({root, to_string(root->val)});
        while (!stk.empty()){
            auto [node, path] = stk.top();
            stk.pop();
            if(node->left == NULL && node->right == NULL) {
                paths.push_back(path);
            }
            if(node->right != NULL) {
                stk.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if(node->left != NULL) {
                stk.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }

        return paths;
    }
};