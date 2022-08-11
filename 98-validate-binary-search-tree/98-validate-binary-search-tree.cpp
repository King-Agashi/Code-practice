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
    bool isValidBST(TreeNode* root, long high = LONG_MAX, long low = LONG_MIN) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= low || root->val >= high) {
            return false;
        }
        
        return isValidBST(root->left, root->val, low) && isValidBST(root->right, high, root->val);
    }
};