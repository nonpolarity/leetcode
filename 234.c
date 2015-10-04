#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};

bool
isPalindrome(struct ListNode *head)
{
	if (head == 0)
		return 1;
	int		index = 0;
	struct ListNode *tmp = head;
	while (tmp != 0) {
		index++;
		tmp = tmp->next;
	}
	int		val        [index];
	index = 0;
	tmp = head;
	while (tmp != 0) {
		val[index++] = tmp->val;
		tmp = tmp->next;
	}
	for (int i = 0; i < index / 2; i++) {
		if (val[i] != val[index - i - 1])
			return 0;
	}
	return 1;
}

int
main(int argc, char *argv[])
{
	struct ListNode	node3 = {1, 0};
	struct ListNode	node2 = {2, &node3};
	struct ListNode	node1 = {1, &node2};
	bool		result = isPalindrome(&node1);
	printf("The result is %d\n", result);
	return 0;
}
