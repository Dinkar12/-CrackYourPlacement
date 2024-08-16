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
    int leftleafsum=0;
private:
    bool isleafnode(TreeNode* root)
    {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    void helper(TreeNode* root)
    {
        if(root==NULL)return;
        if(isleafnode(root->left)) leftleafsum +=root->left->val;
        helper(root->left);
        helper(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return leftleafsum;
    }
};