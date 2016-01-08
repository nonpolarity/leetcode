#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int binarysearch(int *nums, int low, int high, int target)
{
	while (1) {
		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] > target)
			high = mid;
		else
			low = mid;
		if (high - low == 1)
			return high;
	}
}

int searchInsert(int *nums, int numsSize, int target)
{
	if (nums[numsSize - 1] <= target)
		return (nums[numsSize - 1] == target) ? numsSize - 1 : numsSize;
	if (nums[0] >= target)
		return 0;
	return binarysearch(nums, 0, numsSize - 1, target);
}

int main(int argc, char *argv[])
{
	int nums[1] = { 0 };
	int numsSize = 1;
	int target = 1;
	int result = searchInsert(nums, numsSize, target);
	printf("The result is %d\n", result);
	return 0;
}
