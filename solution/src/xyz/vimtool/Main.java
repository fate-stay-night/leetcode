package xyz.vimtool;

import xyz.vimtool.commons.ListNode;
import xyz.vimtool.problem21.Solution;

public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode node1 = new ListNode(1);
        node1.next = new ListNode(4);

        ListNode node2 = new ListNode(2);
        node2.next = new ListNode(3);

        ListNode listNode = solution.mergeTwoLists(node1, node2);
        System.out.println(1);
        System.out.println(3 & 0x1);
        System.out.println(2 & 0x1);
    }
}
