#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void dfs(struct TreeNode *root, int *returnSize, char *upper_result, char **FinalResult)
{
	if (root == NULL)
		return;
	char result[100];
	if (strlen(upper_result))
		sprintf(result, "%s->%d", upper_result, root->val);
	else
		sprintf(result, "%d", root->val);
	if (!root->left && !root->right) {
		sprintf(FinalResult[*returnSize], "%s", result);
//              printf("FinalResult[%d]:%s\n", *returnSize, FinalResult[*returnSize]);
		*returnSize += 1;
		return;
	} else {
		if (root->left != 0)
			dfs(root->left, returnSize, result, FinalResult);

		if (root->right != 0)
			dfs(root->right, returnSize, result, FinalResult);
	}
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{

	char **FinalResult = NULL;
	FinalResult = (char **)malloc(100 * sizeof(char *));
	FinalResult[0] = (char *)malloc(100 * 100 * sizeof(char));
	for (int i = 1; i < 100; i++)
		FinalResult[i] = FinalResult[i - 1] + 100;
	memset(FinalResult[0], 0, 100 * 100 * sizeof(char));
	dfs(root, returnSize, "", FinalResult);
	return FinalResult;
}

int main(int argc, char *argv[])
{
	struct TreeNode n1, n2, n3, n5;
	n1.val = 1;
	n1.left = &n2;
	n1.right = &n3;

	n2.val = 2;
	n2.left = 0;
	n2.right = &n5;

	n3.val = 3;
	n3.left = 0;
	n3.right = 0;

	n5.val = 5;
	n5.left = 0;
	n5.right = 0;

	int size = 0;
	char **FinalResult = binaryTreePaths(&n1, &size);
	printf("size:%d\n", size);
	for (int i = 0; i < size; i++)
		printf("%s\n", FinalResult[i]);
}
