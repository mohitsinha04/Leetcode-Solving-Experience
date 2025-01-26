/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        if (map.count(head)) return map[head];

        Node* node = new Node(head->val, NULL, NULL);

        map[head] = node;

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};