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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int remainder) {
        ListNode* curr = nullptr;
        if (l1) {
            curr = l1;
            remainder += l1->val;
            l1 = l1->next;
        }
        
        if (l2) {
            curr = l2;
            remainder += l2->val;
            l2 = l2->next;
        }
        if (!curr) curr = new ListNode(0);

        curr->val = remainder % 10;
        if (l1 || l2 || remainder >= 10) {
            curr->next = helper(l1, l2, remainder/10);
        }
        return curr;
    }
};