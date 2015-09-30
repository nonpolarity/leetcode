#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	int		i         , j;
	for (i = 0; i < numsSize; i++) {
		for (j = 1; (j <= k & j + i < numsSize); j++)
			if (nums[i] == nums[i + j])
				return 1;
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int		a          [2] = {2, 2};
	int		kv = 2;
	bool		result = containsNearbyDuplicate((int *)a, 2, kv);
	printf("The result is %d", result);
	return 0;
}
