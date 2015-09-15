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
isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == 0 & q == 0) {
		return (bool) 1;
	} else {
		if (p == 0 | q == 0)
			return (bool) 0;
		else {
			if (p->val == q->val) {
				return isSameTree(p->left, q->left) &&
					isSameTree(p->right, q->right);
			} else
				return (bool) 0;
		};
	}
}


int
main(int argc, char *argv[])
{
	return 0;
}
