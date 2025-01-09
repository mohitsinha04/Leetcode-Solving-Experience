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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack;
        stack.push(root);

        unordered_map<TreeNode*, TreeNode*> parents;

        parents[root] = nullptr;

        while (!parents.count(p) || !parents.count(q)) {
            TreeNode* curr = stack.top();
            stack.pop();

            if (curr->left) {
                parents[curr->left] = curr;
                stack.push(curr->left);
            }
            if (curr->right) {
                parents[curr->right] = curr;
                stack.push(curr->right);
            }
        }
        unordered_set<TreeNode*> set;

        while(p != nullptr) {
            set.insert(p);
            p = parents[p];
        }
        while (!set.count(q)) {
            q = parents[q];
        }
        return q;
    }
};