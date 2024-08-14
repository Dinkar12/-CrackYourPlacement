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
    int sum, left, right;
public:
    Solution(): sum(0) {}

    void algorithm(TreeNode* root) {
        if (root == nullptr) return;
        sum += (root -> val >= left && root -> val <= right) ? root -> val : 0;
        algorithm(root -> left);
        algorithm(root -> right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        left = low;
        right = high;
        algorithm(root);
        
        root -> left = nullptr;
        root -> right = nullptr;
        return sum;
    }
};