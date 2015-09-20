#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};


struct ListNode *
mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *l = (struct ListNode *)malloc(sizeof(struct ListNode)),
	               *head = 0;
	if (l1 == 0 & l2 == 0)
		return l1;
	while (l1 != 0 & l2 != 0) {
		if (l1->val < l2->val) {
			l->next = l1;
			l1 = l1->next;
		} else {
			l->next = l2;
			l2 = l2->next;
		}


		if (head == 0)
			head = l->next;
		l = l->next;
	}
	if (l1 == 0)
		l->next = l2;
	else
		l->next = l1;
	if (head == 0)
		head = l->next;
	return head;
}

int
main(int argc, char *argv[])
{
	return 0;
}
