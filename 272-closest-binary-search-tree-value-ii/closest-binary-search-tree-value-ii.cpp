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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> q;
        dfs(root, target, k, q);
        vector<int> res;
        while (q.size() > 0) {
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
    void dfs(TreeNode* root, double target, int k, deque<int>& q) {
        if (!root) return;

        dfs(root->left, target, k, q);
        q.push_front(root->val);
        if (q.size() > k) {
            if (abs(target - q.front()) <= abs(target - q.back())) {
                q.pop_back();
            } else {
                q.pop_front();
            }
        }
        dfs(root->right, target, k, q);
    }
};