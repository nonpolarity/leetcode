#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int missingNumber(int *nums, int numsSize)
{
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
		sum += nums[i];
	int result = (numsSize - (sum - numsSize * (numsSize - 1) / 2));
	return result;
}

int main(int argc, char *argv[])
{
	int nums[5] = { 0, 1, 2, 3, 4 };
	int result = missingNumber(nums, 5);
	printf("%d\n", result);
	return 0;
}
