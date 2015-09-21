#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
removeDuplicates(int *nums, int numsSize)
{
	if (numsSize < 2)
		return numsSize;
	int		i = 0,	duplicated = 0;
	for (; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1])
			duplicated++;
		else
			nums[i - duplicated] = nums[i];
	}
	nums[i - duplicated] = nums[i];
	return numsSize - duplicated;
}

int
main(int argc, char *argv[])
{
	const int	numsSize = 10;
	int		nums       [numsSize] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	int		result = removeDuplicates(nums, numsSize);
	printf("The new size is %d\n", result);
	for (int i = 0; i < result; i++)
		printf("nums[%d]:%d\n", i, nums[i]);
	return 0;
}
