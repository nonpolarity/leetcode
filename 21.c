#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int
removeElement(int *nums, int numsSize, int val)
{
	int		i = numsSize - 1;
	for (; i >= 0; i--) {
		if (nums[i] == val) {
			if (i != (numsSize - 1))
				nums[i] = nums[numsSize - 1];
			numsSize--;
		}
	}
	return numsSize;
}

int
main(int argc, char *argv[])
{
	return 0;
}
