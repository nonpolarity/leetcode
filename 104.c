#include <stdlib.h>
#include <stdio.h>

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
	struct linkednode {
		int		level;
		struct TreeNode *self;
		struct TreeNode *parent;
	};

	struct linkednode *lroot = (struct linkednode *)malloc(sizeof(struct linkednode));
	lroot->level = 1;
	lroot->self = root;
	lroot->parent = 0;

	struct linkednode *current = lroot;

	do {
		int		parentlevel = current->level + 1;
		struct TreeNode *currentself = current->self;
		struct TreeNode *sameparent = current->parent;
		if (currentself->left) {
			struct linkednode *new = (struct linkednode *)malloc(sizeof(struct linkednode));
			new->level = parentlevel;
			new->self = currentself;
			new->parent = sameparent;
			current = new;
		}
		if (currentself->right) {
			struct linkednode *new = (struct linkednode *)malloc(sizeof(struct linkednode));
			new->level = parentlevel;
			new->self = currentself;
			new->parent = sameparent;
			current = new;
		}
	} while
		((current->self->left != 0) | (current->self->right != 0));
	return (current->level);
}

int
main(int argc, char *argv[])
{
	return 0;
}
