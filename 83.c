#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct ListNode {
	int		val;
	struct ListNode *next;
};

struct ListNode *
deleteDuplicates(struct ListNode *head)
{
	if (head == 0)
		return head;
	struct ListNode *tmp = head;
	while (tmp->next) {
		if (tmp->val == tmp->next->val) {
			tmp->val = tmp->next->val;
			tmp->next = tmp->next->next;
		} else
			tmp = tmp->next;
	}
	return head;
}


int
main(int argc, char *argv[])
{
	return 0;
}
