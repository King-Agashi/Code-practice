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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* makeBST(vector<int>& nums, int start, int end) { // end is inclusive
        if (start > end) { return nullptr; }
        if (start == end) {
            TreeNode* newNode = new TreeNode(nums[start]);
            return newNode;
        }
        
        int mid = (start + end) / 2;
        int val = nums[mid];
        TreeNode* left = makeBST(nums, start, mid - 1);
        TreeNode* right = makeBST(nums, mid + 1, end);
        TreeNode* newNode = new TreeNode(val, left, right);
        
        return newNode;
    }
};