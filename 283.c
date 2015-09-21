#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void
moveZeroes(int *nums, int numsSize)
{
	int		i = 0,	duplicated = 0;
	for (; i < numsSize - 1; i++) {
		if (nums[i] == 0)
			duplicated++;
		else
			nums[i - duplicated] = nums[i];
	}
	nums[i - duplicated] = nums[i];
	for (int j = numsSize - 1; j >= numsSize - duplicated; j--)
		nums[j] = 0;
}

int
main(int argc, char *argv[])
{
	const int	numsSize = 10;
	int		nums       [numsSize] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
	moveZeroes(nums, numsSize);
	for (int i = 0; i < numsSize; i++)
		printf("nums[%d]:%d\n", i, nums[i]);
	return 0;
}
