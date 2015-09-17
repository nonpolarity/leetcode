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
	struct ListNode *end = head;
	if (end == 0)
		return 0;
	if (end->next == 0)
		return head;
	struct ListNode *tmp1=head, *tmp2=head->next;
	while (tmp2 != 0) {
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		tmp1->next = end;
		end = tmp1;
		tmp1=tmp2;
	}
	head->next = 0;
	return end;

}

int
main(int argc, char *argv[])
{
	return 0;
}
