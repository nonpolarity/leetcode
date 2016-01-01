#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int singleNumber(int *nums, int numsSize)
{
	int result = 0;
	for (int i = 0; i < numsSize; i++)
		result ^= nums[i];
	return result;

}

int main(int argc, char *argv[])
{
	int nums[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7 };
	int numsSize = 13;
	int result = singleNumber(nums, numsSize);
	printf("Result: %d\n", result);
	return 0;
}
