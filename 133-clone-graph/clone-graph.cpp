/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> vis;
        Node* copy = new Node(node->val, {});
        vis[node] = copy;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (!vis.count(neighbor)) {
                    vis[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                vis[curr]->neighbors.push_back(vis[neighbor]);
            }
        }
        return copy;
    }
};