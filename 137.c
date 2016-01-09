#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int singleNumber(int *nums, int numsSize)
{
	int len = sizeof(int) * 8;
	int *mark = (int *)malloc(sizeof(int) * len);
	memset(mark, 0, sizeof(int) * len);

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < numsSize; j++) {
			mark[i] += ((nums[j] >> i) - (nums[j] >> i >> 1 << 1)) % 2;
		}
		mark[i] = mark[i] % 3;
	}
	int result = 0;
	for (int i = 0; i < len; i++) {
		result += mark[i] << i;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int nums[10] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, -111 };
	int numsSize = 10;
	int result = singleNumber(nums, numsSize);
	printf("result is %d\n", result);
	return 0;
}
