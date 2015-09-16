#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int
majorityElement(int *nums, int numsSize)
{
	int		select = nums[0];
	int		count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (select == nums[i])
			count++;
		else {
			if (count > 0)
				count--;
			else
				select = nums[i];
		}
	}
	return select;
}
int
main(int argc, char *argv[])
{
	return 0;
}
