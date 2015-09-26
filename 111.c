#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct TreeNode {
	int		val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int
minDepth(struct TreeNode *root)
{
	if (root == 0)
		return 0;
	int		level = 0;
	int		head = 0,	tail = 0;
	struct TreeNode *queue[512];
	queue[tail++] = root;
	queue[tail++] = 0;
	while (head != tail) {
		struct TreeNode *tmp = queue[head++];
		if (tmp == 0) {
			if (head == tail)
				break;
			level++;
			queue[tail++] = 0;
			continue;
		} else {
			if (tmp->left == 0 & tmp->right == 0)
				return level;
		}
		if (tmp->left)
			queue[tail++] = tmp->left;
		if (tmp->right)
			queue[tail++] = tmp->right;
	}
	return level;
}

int
main(int argc, char *argv[])
{
	return 0;
}
