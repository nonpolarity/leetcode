#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
	if (!head)
		return 0;
	struct ListNode *h = head;
	struct ListNode *t = head;
	while (h && t) {
		t = t->next;
		h = h->next;
		if (h)
			h = h->next;
		else
			return 0;
		if (h == t)
			return 1;
	}
	return 0;

}

int main(int argc, char *argv[])
{
	struct ListNode node0;
	struct ListNode node1;
	struct ListNode node2;
	struct ListNode node3;
	struct ListNode node4;

	node0.val = 0;
	node0.next = &node1;

	node1.val = 1;
	node1.next = &node2;

	node2.val = 2;
	node2.next = &node3;

	node3.val = 3;
	node3.next = &node4;

	node4.val = 4;
	node4.next = &node1;

	int result = hasCycle(&node0);
	printf("%d\n", result);
	return 0;
}
