#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int searchInsert(int *nums, int numsSize, int target)
{
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] >= target)
			return i;
	}
	return numsSize;

}

int main(int argc, char *argv[])
{
	int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numsSize = 10;
	int target = 10;
	int result = searchInsert(nums, numsSize, target);
	printf("The result is %d\n", result);
	return 0;
}
