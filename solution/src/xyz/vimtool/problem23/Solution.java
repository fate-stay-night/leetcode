package xyz.vimtool.problem23;

import xyz.vimtool.commons.ListNode;

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-3
 */
public class Solution {

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        ListNode head = lists[0];
        for (int i = 1, len = lists.length; i < len; i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode temp = head;
        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                temp.next = l2;
                l2 = l2.next;
            } else {
                temp.next = l1;
                l1 = l1.next;
            }
            temp = temp.next;
        }
        if (l1 != null) {
            temp.next = l1;
        }
        if (l2 != null) {
            temp.next = l2;
        }
        return head.next;
    }
}
