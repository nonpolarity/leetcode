#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int		val;
	struct ListNode *next;
};

void
deleteNode(struct ListNode *node)
{
	node->val = node->next->val;
	free(node->next);
	node->next = node->next->next;
}

int
main(int argc, char *argv[])
{
	return 0;
}
