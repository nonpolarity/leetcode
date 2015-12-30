#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void rotate(int *nums, int numsSize, int k)
{
	k = k - k / numsSize * numsSize;
	int tmp[k];
	for (int i = 0; i < k; i++)
		tmp[i] = nums[numsSize - k + i];
	for (int i = numsSize - 1; i >= k; i--)
		nums[i] = nums[i - k];
	for (int i = 0; i < k; i++)
		nums[i] = tmp[i];
}

int main(int argc, char *argv[])
{
	int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int numsSize = 10;
	int k = 13;

	rotate(nums, numsSize, k);
	for (int i = 0; i < 10; i++)
		printf("%d,", nums[i]);
	return 0;
}
