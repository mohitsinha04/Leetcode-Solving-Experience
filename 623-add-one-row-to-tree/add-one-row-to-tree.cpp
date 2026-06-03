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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return root;
        if (depth == 1) {
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        TreeNode* head = root;
        helper(head, val, depth, 1);
        return root;

    }

    void helper(TreeNode* root, int val, int depth, int currLevel) {
        if (currLevel == depth-1) {
            // if (root->left) {
                TreeNode* left = root->left;
                root->left = new TreeNode(val);
                root->left->left = left;
            // } if (root->right) {
                TreeNode* right = root->right;
                root->right = new TreeNode(val);
                root->right->right = right;
            // }
            return;
        }
        if (root->left)
            helper(root->left, val, depth, currLevel + 1);
        if (root->right)
            helper(root->right, val, depth, currLevel + 1);

    }
}; 