#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int singleNumber(int *nums, int numsSize)
{
	int len = sizeof(int) * 8;
	int *list = malloc(sizeof(int) * len);
	memset(list, 0, sizeof(int) * len);
	int result = 0;
	int prefix = 1;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < numsSize; j++) {
			list[i] += (nums[j] - ((nums[j] >> 1) * 2));
			nums[j] = nums[j] >> 1;
		}
		// If there are always triple numbers, then %3;
		list[i] %= 2;
	}
	for (int i = 0; i < len; i++)
		result += (list[i] << i);
	return result;
}

int main(int argc, char *argv[])
{
	int nums[] = { 1, 3, 1, -100000, 3 };
	int numsSize = 5;
	int result = singleNumber(nums, numsSize);
	printf("Result: %d\n", result);
	return 0;
}
