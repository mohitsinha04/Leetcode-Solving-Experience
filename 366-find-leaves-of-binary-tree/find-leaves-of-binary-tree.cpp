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
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper(root);
        return res;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        int left = helper(root->left);
        int right = helper(root->right);

        int currHeight = max(left, right) + 1;

        if (currHeight == res.size()) {
            vector<int> curr;
            res.push_back(curr);
        }
        res[currHeight].push_back(root->val);
        return currHeight;
    }
};