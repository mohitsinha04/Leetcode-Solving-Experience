/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ancestor;

        while (p != nullptr) {
            ancestor.insert(p);
            p = p->parent;
        }
        while (!ancestor.count(q)) {
            q = q->parent;
        }
        return q;
    }
};