/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* res = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return res;
    }
    bool lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        int left = lca(root->left, p, q);
        int right = lca(root-> right, p, q);

        int mid = (root == p) || (root == q);

        if (left + right + mid >= 2) res = root;

        return (left + right + mid) > 0;
    }
};