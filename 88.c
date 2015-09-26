#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
void
merge(int *nums1, int m, int *nums2, int n)
{
	int		i = m + n - 1, j = m - 1, k = n - 1;
	int		num1      , num2;
	while (i >= 0) {
		if (j >= 0)
			num1 = nums1[j];
		else
			num1 = INT_MIN;
		if (k >= 0)
			num2 = nums2[k];
		else
			num2 = INT_MIN;
		if (num1 >= num2) {
			nums1[i--] = num1;
			j--;
		} else {
			nums1[i--] = num2;
			k--;
		}
	}
	return;
}


int
main(int argc, char *argv[])
{
	int		nums1      [] = {0, 0, 3, 0, 0, 0, 0, 0, 0};
	int		nums2      [] = {-1, 1, 1, 1, 2, 3};
	merge(nums1, 3, nums2, 6);
	for (int i = 0; i < 9; i++)
		printf("a[%d]:%d\n", i, nums1[i]);
	return 0;
}
