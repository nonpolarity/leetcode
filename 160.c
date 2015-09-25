#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
	int		val;
	struct ListNode *next;
};

struct ListNode *
getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int		a = 0,	b = 0;
	struct ListNode *A = headA, *B = headB;
	if (A == 0 | B == 0)
		return 0;
	while (A) {
		a++;
		A = A->next;
	}
	while (B) {
		b++;
		B = B->next;
	}
	A = headA, B = headB;
	while (a > b) {
		a--;
		A = A->next;
	}
	while (b > a) {
		b--;
		B = B->next;
	}
	while (A) {
		if (A == B)
			return A;
		A = A->next;
		B = B->next;
	}
	return 0;
}

int
main(int argc, char *argv[])
{

	struct ListNode	node11 = {21,};
	struct ListNode	node10 = {19, &node11};
	struct ListNode	node9 = {17, &node10};
	struct ListNode	node8 = {15, &node9};
	struct ListNode	node7 = {13, &node8};
	struct ListNode	node6 = {11, &node7};
	struct ListNode	node5 = {9, &node6};
	struct ListNode	node4 = {7, &node5};
	struct ListNode	node3 = {5, &node4};
	struct ListNode	node2 = {3, &node3};
	struct ListNode	node1 = {1, &node2};
	struct ListNode	nodea = {1, &node1};
	struct ListNode	nodeb = {1, &node1};
	struct ListNode *result = getIntersectionNode(&nodea, &nodeb);
	if (result != 0)
		printf("Good! The intersection is %d\n", result->val);
	else
		printf("Too bad! The intersection is %p\n", result);
	return 0;
}
