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
     int Mini=INT_MAX , prev=-1;

    void Traverse(TreeNode* root)
    {
        if(!root)return;

        Traverse(root->left);

        if(prev>=0) Mini=min(Mini,root->val-prev);
        prev=root->val;

        Traverse(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        Traverse(root);
        return Mini;
    }
};