#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};

static struct ListNode *key;
int
search(struct ListNode *head, int n)
{
	int		serial;
	if (head->next == 0) {
		serial = 1;
	} else
		serial = search(head->next, n) + 1;
	if (serial == n)
		key = head;
	return serial;
}

struct ListNode *
removeNthFromEnd(struct ListNode *head, int n)
{
	if (head == 0)
		return 0;
	search(head, n);
	struct ListNode *ohead = head;
	if (head == key)
		return head->next;
	while (head->next != key)
		head = head->next;
	head->next = key->next;
	return ohead;
}
int
main(int argc, char *argv[])
{
	struct ListNode	node2 = {2, 0};
	struct ListNode	node1 = {1, &node2};
	struct ListNode *head = &node1;
	struct ListNode *result;
	result = removeNthFromEnd(head, 2);
	printf("result");
	while (result != 0) {
		printf("==>node%d", result->val);
		result = result->next;
	}
	printf("\n");
	return 0;
}
