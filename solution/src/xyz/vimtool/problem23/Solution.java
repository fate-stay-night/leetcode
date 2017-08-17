package xyz.vimtool.problem23;

import xyz.vimtool.commons.ListNode;

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * 采用分治法，
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-3
 */
public class Solution {

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return separate(lists, 0, lists.length - 1);
    }

    public ListNode separate(ListNode[] lists, int low, int high) {
        if (low < high) {
            int middle = (low + high) / 2;
            return mergeTwoLists(separate(lists, low, middle), separate(lists, middle + 1, high));
        }
        return lists[low];
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
