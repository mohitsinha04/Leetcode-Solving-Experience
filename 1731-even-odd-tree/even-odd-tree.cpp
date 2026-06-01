class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            int prev;
            if (level % 2 == 0) prev = INT_MIN;
            else prev = INT_MAX;
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Check parity: even levels need odd values, odd levels need even values
                if (level % 2 == 0 && curr->val % 2 == 0) return false;
                if (level % 2 == 1 && curr->val % 2 == 1) return false;

                // Check ordering (skip first node in each level)
                if (level % 2 && curr->val >= prev) return false;
                if (level % 2 == 0 && curr->val <= prev) return false;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right); 
                prev = curr->val;
            }
            level++;
        }
        return true;
    }
};