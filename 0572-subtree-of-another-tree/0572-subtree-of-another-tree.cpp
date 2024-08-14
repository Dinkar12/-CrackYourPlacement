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
    bool issymmetric(TreeNode* root, TreeNode* subRoot)
    {
        if((root==NULL && subRoot!=NULL)||(root!=NULL && subRoot==NULL)) return false;
        if(root==NULL&&subRoot==NULL)return true;
        if(root->val!=subRoot->val) return false;
        return issymmetric(root->left, subRoot->left) && issymmetric(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val)
        {
            bool ans=issymmetric(root, subRoot);
            if(ans) return true;
        }
        bool left=isSubtree(root->left, subRoot);
        bool right=isSubtree(root->right, subRoot);
        return left || right;
    }
};