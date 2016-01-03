#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *singleNumber(int *nums, int numsSize, int *returnSize)
{
	int len = sizeof(int) * 8;
	int *list = malloc(sizeof(int) * len);
	memset(list, 0, sizeof(int) * len);
	int result = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < numsSize; j++) {
			list[i] += ((nums[j] >> i) - ((((nums[j] >> i) >> 1) << 1)));
		}
		// If there are always triple numbers, then %3;
		list[i] %= 2;
	}

	for (int i = 0; i < len; i++)
		result += (list[i] << i);

	int p = 0;
	for (int i = 0; i < len; i++)
		if (list[i]) {
			p = i;
			break;
		}

	int mark[numsSize];
	for (int j = 0; j < numsSize; j++) {
		mark[j] = ((nums[j] >> p) - ((((nums[j] >> p) >> 1) << 1)));
	}

	int *list0 = malloc(sizeof(int) * len);
	int *list1 = malloc(sizeof(int) * len);
	memset(list0, 0, sizeof(int) * len);
	memset(list1, 0, sizeof(int) * len);

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < numsSize; j++) {
			if (mark[j])
				list1[i] += (((nums[j] >> i) - ((((nums[j] >> i) >> 1) << 1))));
			else
				list0[i] += (((nums[j] >> i) - ((((nums[j] >> i) >> 1) << 1))));
		}
		// If there are always triple numbers, then %3;
		list0[i] %= 2;
		list1[i] %= 2;
	}

	*returnSize = 2;
	int *resulta = malloc(sizeof(int) * (*returnSize));
	memset(resulta, 0, sizeof(int) * (*returnSize));
	for (int i = 0; i < len; i++) {
		resulta[0] += (list0[i] << i);
		resulta[1] += (list1[i] << i);
	}
	return resulta;
}

int main(int argc, char *argv[])
{
	int nums[] = { 1, 1, 2, 2, 3, 3, -4, -5 };
	int numsSize = 8;
	int returnSize;
	int *result = singleNumber(nums, numsSize, &returnSize);
	printf("result0:%d\nresult1:%d\n", result[0], result[1]);
	return 0;
}
