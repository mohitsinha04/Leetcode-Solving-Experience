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
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode* root, TreeNode* upperLimit, TreeNode* lowerLimit) {
        if (!root) return true;

        if ((upperLimit && root->val >= upperLimit->val) || (lowerLimit && root->val <= lowerLimit->val)) return false;

        return helper(root->left, root, lowerLimit) && helper(root->right, upperLimit, root);
    }


};