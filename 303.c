#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int nums[] = { -2, 0, 3, -5, 2, -1 };

struct NumArray {
	int *nums;
	int numsSize;
	int *presum;
};

/** Initialize your data structure here. */
struct NumArray *NumArrayCreate(int *nums, int numsSize)
{
	struct NumArray *newarray = (struct NumArray *)malloc(sizeof(struct NumArray));
	newarray->nums = nums;
	newarray->numsSize = numsSize;

	int *presum = (int *)malloc(sizeof(int) * numsSize);
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum = sum + nums[i];
		presum[i] = sum;
	}
	newarray->presum = presum;
	return newarray;
}

int sumRange(struct NumArray *numArray, int i, int j)
{
	int local_sum = 0;
	local_sum = numArray->presum[j] - numArray->presum[i] + numArray->nums[i];
	return local_sum;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray *numArray)
{
	free(numArray->presum);
	free(numArray);
	return;
}

int main(int argc, char *argv[])
{
	struct NumArray *numArray = NumArrayCreate(nums, 6);
	printf("0-2:%d\n", sumRange(numArray, 0, 2));
	printf("2-5:%d\n", sumRange(numArray, 2, 5));
	printf("0-5:%d\n", sumRange(numArray, 0, 5));
	NumArrayFree(numArray);
	return 0;
}
