#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *stack[128];
static int top = 0;
void push(struct TreeNode *node)
{
	stack[top++] = node;
	return;
}

struct TreeNode *pop(void)
{
	return stack[--top];
}

int empty(void)
{
	if (top)
		return 1;
	else
		return 0;
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	struct TreeNode *list[128];
	memset(list, 0, sizeof(struct TreeNode *) * 128);
	int *vallist = malloc(sizeof(int) * 128);
	memset(vallist, 0, sizeof(int) * 128);

	*returnSize = 0;

	while (root || top) {
		if (root) {
			push(root);
			root = root->left;
		} else {
			root = pop();
			vallist[(*returnSize)++] = root->val;
			root = root->right;
		}
	}

	return vallist;
}

int main(int argc, char *argv[])
{
	struct TreeNode node1;
	struct TreeNode node2;
	struct TreeNode node3;
	struct TreeNode node4;
	struct TreeNode node5;
	struct TreeNode node6;

	node1.val = 1;
	node1.left = &node2;
	node1.right = &node3;

	node2.val = 2;
	node2.left = NULL;
	node2.right = &node4;

	node3.val = 3;
	node3.left = &node5;
	node3.right = NULL;

	node4.val = 4;
	node4.left = NULL;
	node4.right = NULL;

	node5.val = 5;
	node5.left = NULL;
	node5.right = &node6;

	node6.val = 6;
	node6.left = NULL;
	node6.right = NULL;

	int returnSize;
	int *vallist = inorderTraversal(&node1, &returnSize);

	for (int i = 0; i < returnSize; i++)
		printf("%d,", vallist[i]);

	printf("\n");
	return 0;
}
