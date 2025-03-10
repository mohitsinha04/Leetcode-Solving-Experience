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
    void dfs(TreeNode* root, int hd, int& mn, unordered_map<int, set<int>>& mp) {
        if (root == nullptr) 
        return;
    
        // Store the current node in the map at horizontal distance hd
        mp[hd].insert(root->val);
        
        // Update the minimum horizontal distance
        mn = min(mn, hd);
        
        // Recursively traverse the left and right subtrees
        dfs(root->left, hd - 1, mn, mp);  
        dfs(root->right, hd + 1, mn, mp);
    }
public:
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     // unordered_map<int, set<int>> mp;
    
    //     // // Variable to track the minimum horizontal distance
    //     // int mn = 0; 

    //     // // Perform DFS to fill the hashmap with vertical levels
    //     // dfs(root, 0, mn, mp);
        
    //     // vector<vector<int>> res;
    //     // int hd = mn;

    //     // // Traverse the map from minimum to maximum horizontal distance
    //     // while(mp.find(hd) != mp.end()) {
    //     //     res.push_back(mp[hd].begin(), mp[hd].end());
    //     //     hd++;
    //     // }
    
    //     // return res;

    // }
    unordered_map<int, unordered_map<int, multiset<int>>> m;
void traverse(TreeNode* r, int x, int y) {
  if (r != nullptr) {
    m[x][y].insert(r->val);
    traverse(r->left, x - 1, y + 1);
    traverse(r->right, x + 1, y + 1);
  }
}
vector<vector<int>> verticalTraversal(TreeNode* r) {
  vector<vector<int>> res;
  traverse(r, 0, 0);
  for (int x = -999; x < 1000; ++x) {
    auto it = m.find(x);
    if (it != end(m)) {
      res.push_back(vector<int>());
      for (int y = 0; y < 1000; ++y) {
        auto ity = it->second.find(y);
        if (ity != end(it->second)) {
          res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
        }
      }
    }
  }
  return res;
}
};