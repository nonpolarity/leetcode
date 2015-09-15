#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct TreeNode {
	int		val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *
invertTree(struct TreeNode *root)
{
	if (root != 0) {
		invertTree(root->left);
		invertTree(root->right);
		struct TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
	return root;
}


int
main(int argc, char *argv[])
{
	return 0;
}
