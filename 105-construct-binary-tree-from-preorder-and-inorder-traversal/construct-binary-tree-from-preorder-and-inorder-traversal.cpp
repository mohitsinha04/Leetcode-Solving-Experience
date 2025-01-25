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
    int pIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pIndex = 0;
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorderIndexMap);
    }

    TreeNode* helper(vector<int>& preorder, int left, int right, unordered_map<int, int>& inorderIndexMap) {
        if (left > right) return nullptr;

        int rootVal = preorder[pIndex++];
        TreeNode* root = new TreeNode(rootVal);

        root->left = helper(preorder, left, inorderIndexMap[rootVal] - 1, inorderIndexMap);
        root->right = helper(preorder, inorderIndexMap[rootVal] + 1, right, inorderIndexMap);
        return root;
    }
};