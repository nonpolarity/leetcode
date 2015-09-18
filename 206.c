#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};

struct ListNode *
reverseList(struct ListNode *head)
{
	//if (head == 0)
		//return 0;
	if (head == 0 | head->next == 0)
		return head;
	struct ListNode *tmp = reverseList(head->next);
	head->next->next = head;
	head->next = 0;
	return tmp;
}

int
main(int argc, char *argv[])
{
	//struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *node1 = 0;
	struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode *));
	struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode *));
	struct ListNode *newhead = (struct ListNode *)malloc(sizeof(struct ListNode *));
	//node1->val = 1;
	//node1->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = 0;
	newhead = reverseList(node1);
	while (newhead != 0) {
		printf("val:%d\n", newhead->val);
		newhead = newhead->next;
	}
	return 0;
}
