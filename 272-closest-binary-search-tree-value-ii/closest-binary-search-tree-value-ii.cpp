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

//  1, 2, 3, 4, 5
//  k = 2, 
// 
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> nums;
        dfs(root, nums);
        int left = 0;
        int right = nums.size() - k;

        while (left < right) {
            int mid = left + (right - left)/2;
            if (abs(nums[mid + k] - target) < abs(nums[mid] - target)) left = mid + 1;
            else right = mid;
        }
        vector<int> res;
        for (int i = left; i < left + k; i++) {
            res.push_back(nums[i]);
        }
        return res;
    }

    void dfs(TreeNode* root, vector<int>& sortedArray) {
        if (!root) return;
        dfs(root->left, sortedArray);
        sortedArray.push_back(root->val);
        dfs(root->right, sortedArray);
    }
};