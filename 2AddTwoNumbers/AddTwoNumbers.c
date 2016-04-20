/*
*create by xiao
*Add Two Numbers
*	You are given two linked lists representing two non-negative numbers. 
*	The digits are stored in reverse order and each of their nodes contain
*	a single digit.Add the two numbers and return it as a linked list.
*	Input: (2->4->3)+(5->6->4)
*	Output: 7->0->8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
*/

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNodei *l2)
{
	int flag = 0;
	int sum = 0;
	struct ListNode *head1 = NULL;
	struct ListNode *head2 = head1;
	while (l1 || l2 || flag) {
		sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
		struct ListNode *lnow = (struct ListNode *)malloc(sizeof(lnow));
		flag = sum / 10;
		if (flag > 1) {
			flag = 1;
			lnow->val = sum -10;
        	} else {
			lnow->val = sum % 10;
		}
		lnow->next = NULL;
		if (head2 == NULL) {
			head2 = lnow;
		} else {
			head2->next = lnow;
			head2 = head2->next;
		}
		if (head1 == NULL) 
			head1 = head2;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	return head1;
}
