#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};


struct ListNode *
removeElements(struct ListNode *head, int val)
{
	if (head == 0)
		return head;
	struct ListNode *newhead = 0;
	struct ListNode *parent;
	while (head) {
		if (head->val != val) {
			if (newhead == 0)
				newhead = head;
			parent = head;
			head = head->next;
		} else {
			parent->next = head->next;
			head = head->next;
		}
	}
	return newhead;

}

int
main(int argc, char *argv[])
{
	return 0;
}
