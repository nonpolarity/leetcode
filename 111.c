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

int
minDepth(struct TreeNode *root)
{
	if (root == 0)
		return 0;
	if (root->left == 0 & root->right == 0)
		return 1;
	int		left = INT_MAX, right = INT_MAX;
	if (root->left != 0)
		left = minDepth(root->left);
	if (root->right != 0)
		right = minDepth(root->right);
	return (left < right ? left + 1 : right + 1);
}

int
main(int argc, char *argv[])
{
	return 0;
}
