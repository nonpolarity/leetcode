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
bfs(struct TreeNode *root, bool leftfirst, struct TreeNode *a[100])
{
	memset(a, 0, sizeof(int) * 100);
	int		head = 0,	tail = 0;
	a[head++] = root;
	struct TreeNode *tmp;
	while (head != tail) {
		tmp = a[tail++];
		if (leftfirst == 1) {
			if (tmp->left != 0)
				a[head++] = tmp->left;
			if (tmp->right != 0)
				a[head++] = tmp->right;

		} else {
			if (tmp->right != 0)
				a[head++] = tmp->right;
			if (tmp->left != 0)
				a[head++] = tmp->left;
		};
	}
	return tail - 1;
}

bool
isSymmetric(struct TreeNode *root)
{
	if (root == 0)
		return 1;
	if (root->left == 0 & root->right == 0)
		return 1;
	if (root->left == 0 | root->right == 0)
		return 0;
	struct TreeNode *left[100];
	struct TreeNode *right[100];
	int		i         , depth_left, depth_right;
	depth_left = bfs(root->left, 1, left);
	depth_right = bfs(root->right, 0, right);
	if (depth_left != depth_right)
		return 0;
	for (i = 0; i <= depth_left; i++) {
		if (left[i]->val != right[i]->val)
			return 0;
	};
	return 1;
}
int
main(int argc, char *argv[])
{
	//struct TreeNode c = {2, 0, 0};
	struct TreeNode	b = {2, 0, 0};
	struct TreeNode	a = {1, &b, 0};
	struct TreeNode *p = &a;
	printf("a:%d\n", isSymmetric(p));
	return 0;
}
