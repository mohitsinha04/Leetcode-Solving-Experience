/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) return head;

        ListNode prev = null;
        ListNode curr = head;
        int pos = 1;

        // Step 1: Move curr to 'left' position
        while (pos < left) {
            prev = curr;
            curr = curr.next;
            pos++;
        }

        // Step 2: Remember the connections
        ListNode lastNodeOfFirstPart = prev;  // node before sublist
        ListNode lastNodeOfSublist = curr;    // will become tail after reversal

        // Step 3: Reverse sublist from left to right
        ListNode next = null;
        while (pos <= right) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        // Step 4: Reconnect
        if (lastNodeOfFirstPart != null) {
            lastNodeOfFirstPart.next = prev;  // connect with reversed part
        } else {
            head = prev;  // if reversed from the start
        }

        lastNodeOfSublist.next = curr;  // connect tail of reversed part to rest

        return head;
    }
}
