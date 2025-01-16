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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (auto desc : descriptions) {
            int pvalue = desc[0];
            int childValue = desc[1];
            bool isLeft = desc[2];

            if (!nodeMap.count(pvalue)) {
                nodeMap[pvalue] = new TreeNode(pvalue);
            }
            if (!nodeMap.count(childValue)) {
                nodeMap[childValue] = new TreeNode(childValue);
            }
            if (isLeft) {
                nodeMap[pvalue]->left = nodeMap[childValue];
            } else {
                nodeMap[pvalue]->right = nodeMap[childValue];
            }
            children.insert(childValue);
        }

        for (auto entry : nodeMap) {
            auto value = entry.first;
            auto node = entry.second;

            if (!children.count(value)) return node;
        }
        return nullptr;
    }
};