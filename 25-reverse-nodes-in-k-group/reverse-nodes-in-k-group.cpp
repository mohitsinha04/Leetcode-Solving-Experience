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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k > 0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        while (count < k && curr != nullptr) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            ListNode* reversedHead = reverseLinkedList(head, k);
            head->next = reverseKGroup(curr, k);
            return reversedHead;
        }
        return head;
    }
};