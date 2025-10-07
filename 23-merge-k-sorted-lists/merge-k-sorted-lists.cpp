/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        // push all current heads.
        for(auto l : lists) {
            if(l != nullptr)  {
                q.push(l);
            }
        }

        if(q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();


        if(result->next) q.push(result->next);

        ListNode* curr = result;

        while(!q.empty()) {
            curr->next = q.top();
            q.pop();
            curr = curr->next;
            if(curr->next) q.push(curr->next);
        }
        return result;
    }
};