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
    int goodNode = 0;
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        dfs(root, INT_MIN);
        return goodNode;
    }

    void dfs(TreeNode* root, int maxSoFar) {
        if (maxSoFar <= root->val) goodNode++;

        if (root->right) dfs(root->right, max(root->val, maxSoFar));
        if (root->left) dfs(root->left, max(root->val, maxSoFar));

    }
};