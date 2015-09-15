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
lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	struct TreeNode *tmp = root;
	if (p->val > q->val) {
		struct TreeNode *o = p;
		p = q;
		q = o;
	}
	while (tmp != 0) {
		if (tmp->val < p->val)
			tmp = tmp->right;
		if (p->val <= tmp->val & tmp->val <= q->val)
			return tmp;
		if (q->val < tmp->val)
			tmp = tmp->left;
	}
}

int
main(int argc, char *argv[])
{
	return 0;
}
