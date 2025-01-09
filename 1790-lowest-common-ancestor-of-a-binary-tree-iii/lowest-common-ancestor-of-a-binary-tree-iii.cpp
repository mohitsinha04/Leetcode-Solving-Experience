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
        Node* a = p;
        Node* b = q;

        // Traverse until both pointers meet
        while (a != b) {
            // If a reaches the root (nullptr), start from q
            a = (a == nullptr) ? q : a->parent;
            // If b reaches the root (nullptr), start from p
            b = (b == nullptr) ? p : b->parent;
        }
        
        // Return the meeting point, which is the LCA
        return a;
    }
};