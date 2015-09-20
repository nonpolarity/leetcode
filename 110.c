#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


struct TreeNode {
	int		val;
	struct TreeNode *left;
	struct TreeNode *right;
};



bool

isBalanced(struct TreeNode *root)
{
	if (root == 0)
		return 1;
	if (root->left == 0 & root->right == 0)
		return 1;
	int		head = 0,	tail = 0, depthmin = INT_MAX, depth = 1;
	struct TreeNode *queue[512];
	memset(queue, 0, sizeof(struct TreeNode *));
	struct TreeNode *empty = 0;
	struct TreeNode *current = 0;
	queue[head++] = root;
	queue[head++] = empty;
	while (head != tail) {
		current = queue[tail++];
		if (current == empty) {
			queue[head++] = empty;
			depth++;
			break;
		}
		if (current->left == 0 & current->right == 0)
			depthmin = depth;
		else {
			if (current->left != 0)
				queue[head++] = current->left;
			if (current->right != 0)
				queue[head++] = current->right;
		}
		if ((depth - depthmin) > 1)
			return 0;


	}
	return 1;

}
int
main(int argc, char *argv[])
{
	struct TreeNode	c = {3, 0, 0};
	struct TreeNode	b = {2, 0, &c};
	struct TreeNode	a = {1, 0, &b};
	struct TreeNode *p = &a;
	printf("the tree a:%d\n", isBalanced(p));
	return 0;
}
