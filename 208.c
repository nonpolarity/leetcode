#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
	*returnSize = 0;
	char **result = (char **)malloc(sizeof(char *) * numsSize);
	int start = 0;
	int i;
	for (i = 0; i < numsSize; i++) {
		if (i == (numsSize - 1) || nums[i] != (nums[i + 1] - 1)) {
			result[*returnSize] = (char *)malloc(sizeof(char) * 32);
			if (i == start) {
				sprintf(result[(*returnSize)++], "%d", nums[start]);
//                              printf("%d\n", nums[start]);
			} else {
				sprintf(result[(*returnSize)++], "%d->%d", nums[start], nums[i]);
//                              printf("%d->%d\n", nums[start], nums[i]);
			}
			start = i + 1;
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	int nums[] = { 1, 2, 3, 4, 5, 7, 8, 9, 11, 13, 15, 16 };
//      int nums[] = { 1 };
	int *returnSize = (int *)malloc(sizeof(int));
	char **result = summaryRanges(nums, 12, returnSize);
	for (int i = 0; i < *returnSize; i++)
		printf("%s\n", result[i]);
	free(returnSize);
	free(result);
	return 0;
}
