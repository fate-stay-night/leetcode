package xyz.vimtool.problem19;

import xyz.vimtool.commons.ListNode;

/**
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-1
 */
public class Solution {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (n == 0 ) {
            return head;
        }
        int length = 1;
        ListNode head1 = head;
        while (head.next != null) {
            head = head.next;
            length++;
        }
        int pre = length - n;
        head = head1;

        if (pre == 0) {
            head1 = head1.next;
            return head1;
        }

        while (pre > 1) {
            pre--;
            head1 = head1.next;
        }
        head1.next = head1.next.next;
        return head;
    }

    public ListNode removeNthFromEnd2(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first.next;
        }
        // Move first to the end, maintaining the gap
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return dummy.next;
    }
}
