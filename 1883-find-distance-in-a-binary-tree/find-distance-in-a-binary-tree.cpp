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
    int findDistance(TreeNode* root, int p, int q) {
        return distance(root, p, q, 0);
    }

    int distance(TreeNode* root, int p, int q, int depth) {
        if (!root || p == q) return 0;

        if (root->val == p || root->val == q) {
            int left = distance(root->left, p, q, 1);
            int right = distance(root->right, p, q, 1);

            return (left > 0 || right > 0) ? max(left, right) : depth;
        }
        int left = distance(root->left, p, q, depth + 1);
        int right = distance(root->right, p, q, depth + 1);
        int retDistance = left + right;

        if (left != 0 && right != 0) {
            retDistance -= 2 * depth;
        }
        return retDistance;
    }
};