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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int minimum = INT_MAX, secMin = INT_MAX;
        bool isSecMin = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->val < minimum) {
                secMin = minimum;
                minimum = curr->val;
            } else if (curr->val <= secMin && curr->val != minimum) {
                secMin = curr->val;
                isSecMin = true;
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return isSecMin == false ? -1 : secMin;

    }
};