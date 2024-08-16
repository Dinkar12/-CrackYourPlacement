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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return(targetSum==root->val);
        bool pathsumexists=false;
        if(root->left) pathsumexists=hasPathSum(root->left, targetSum-root->val);
        if(root->right) pathsumexists=pathsumexists || hasPathSum(root->right, targetSum-root->val);
        return pathsumexists;
    }
};