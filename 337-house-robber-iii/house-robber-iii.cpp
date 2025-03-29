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
    int rob(TreeNode* root) {
        vector<int> res;
        res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode* root) {
        if (!root) {
            return {0,0};
        }
        auto left = helper(root->left);
        auto right = helper(root->right);

        int rob = root->val + left[1] + right[1];
        int notRob = max(left[0], left[1]) + max(right[0], right[1]);

        return {rob, notRob};
    }
};