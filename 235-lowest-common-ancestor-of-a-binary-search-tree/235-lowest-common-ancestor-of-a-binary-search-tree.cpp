/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        inline TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            if (p->left == q || p->right == q)
                return p;

            const auto pAnc = findAncestor(root, root, p->val, q->val, nullptr);
            const auto qAnc = findAncestor(root, root, q->val, p->val, pAnc);

            if (qAnc == pAnc)
                return pAnc;
            return lowestCommonAncestor(root, pAnc, qAnc);
        }

    private:
        inline TreeNode* findAncestor(TreeNode *root, TreeNode *anc, const int &pVal, const int &otherVal, const TreeNode *otherAnc)
        {
            if (root->val == otherVal)
                return root;

            if (root == otherAnc)
                return root;

            if (root->val == pVal)
                return anc;

            if (pVal < root->val)
                return findAncestor(root->left, root, pVal, otherVal, otherAnc);
            return findAncestor(root->right, root, pVal, otherVal, otherAnc);
        }
};