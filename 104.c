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
	struct RTreeNode {
		struct TreeNode *itself;
		struct TreeNode *parent;
	};

	struct RTreeNode queue[512];
	int		head = 0,	tail = 0;

	struct RTreeNode Rroot = {root,
		NULL
	};

	queue[tail++] = Rroot;

	while (tail != head) {
		if (queue[head].itself->left) {
			struct RTreeNode new =
			{queue[head].itself->left,
				queue[head].itself
			};
			queue[tail++] = new;
		}
		if (queue[head].itself->right) {
			struct RTreeNode new =
			{queue[head].itself->right,
				queue[head].itself
			};
			queue[tail++] = new;
		}
		head++;
	}
	int		level = 1;
	struct RTreeNode *final = &queue[tail - 1];
	while (final->parent) {
		final = final->parent;
		level++;
	}
	return level;
}


int
main(int argc, char *argv[])
{
	return 0;
}
