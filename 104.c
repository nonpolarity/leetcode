#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode {
	int		val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int
maxDepth(struct TreeNode *root)
{
	if (root == 0)
		return 0;
	int		left = 0,	right = 0;
	if (root->left != 0)
		left = maxDepth(root->left);
	if (root->right != 0)
		right = maxDepth(root->right);
	return (left > right ? left + 1 : right + 1);
}

int
main(int argc, char *argv[])
{
	return 0;
}
