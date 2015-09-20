#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct TreeNode {
	int		val;
	struct TreeNode *left;
	struct TreeNode *right;
};
bool
sym(struct TreeNode *left, struct TreeNode *right);
bool
isSymmetric(struct TreeNode *root)
{
	if (root == 0)
		return 1;
	if (root->left == 0 & root->right == 0)
		return 1;
	if (root->left == 0 | root->right == 0)
		return 0;
	return sym(root->left, root->right);
}

bool
sym(struct TreeNode *left, struct TreeNode *right)
{
	if (left == 0 & right == 0)
		return 1;
	if (left == 0 & right != 0)
		return 0;
	if (left != 0 & right == 0)
		return 0;
	if (left->val != right->val)
		return 0;
	if (left->left == 0 & right->right != 0)
		return 0;
	if (left->right == 0 & right->left != 0)
		return 0;
	if (left->left == 0 & left->right == 0 & right->left == 0 & right->right == 0)
		return 1;
	return (sym(left->left, right->right) & sym(left->right, right->left));
}

int
main(int argc, char *argv[])
{
	struct TreeNode	e = {3, 0, 0};
	struct TreeNode	d = {3, 0, 0};
	struct TreeNode	c = {2, &d, 0};
	struct TreeNode	b = {2, 0, &d};
	struct TreeNode	a = {1, &b, &c};
	struct TreeNode *p = &a;
	printf("a:%d\n", isSymmetric(p));
	return 0;
}
