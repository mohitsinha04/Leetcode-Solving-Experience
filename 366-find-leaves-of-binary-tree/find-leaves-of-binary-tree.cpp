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
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> inDegree; // child is prerequisite in this problem
        unordered_map<TreeNode*, vector<TreeNode*>> graph; //child -> parent
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            int child = 0;
            if(curr->left) {
                stk.push(curr->left);
                graph[curr->left].push_back(curr); // the prerequisite of parent is its children
                ++child;
            }
            if(curr->right) {
                stk.push(curr->right);
                graph[curr->right].push_back(curr);
                ++child;
            }
            inDegree[curr] = child;
        }

        // normal topological sort code
        queue<TreeNode*> bfs;
        for(auto& [node, child] : inDegree) {
            if(child == 0)
                bfs.push(node);
        }
        vector<vector<int>> ans;
        while(!bfs.empty()) {
            ans.push_back({});
            int sz = bfs.size();
            for(int i=0; i<sz; i++) {
                auto node = bfs.front();
                ans.back().push_back(node->val);
                bfs.pop();
                for(auto neigh : graph[node]) {
                    inDegree[neigh] -= 1;
                    if(inDegree[neigh] == 0)
                        bfs.push(neigh);
                }
            }
        }
        return ans;
    }
};