#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int            *
getRow(int rowIndex, int *returnSize)
{
	if (rowIndex == 0) {
		int            *rp = (int *)malloc(sizeof(int) * (rowIndex + 1));
		rp[0] = 1;
		*returnSize = (rowIndex + 1);
		return rp;
	}
	if (rowIndex == 1) {
		int            *rp = (int *)malloc(sizeof(int) * (rowIndex + 1));
		rp[0] = 1;
		rp[1] = 1;
		*returnSize = (rowIndex + 1);
		return rp;
	}
	int            *rp = (int *)malloc(sizeof(int) * (rowIndex + 1));
	rp[0] = 1;
	rp[1] = 1;
		*returnSize = (rowIndex + 1);
	int		i;
	for (i = 2; i <= rowIndex; i++) {
		rp[i] = 1;
		int		tmp        [i + 1];
		for (int temp = 0; temp <= i; temp++)
			tmp[temp] = rp[temp];
		for (int j = 1; j < i; j++)
			rp[j] = tmp[j - 1] + tmp[j];
	}
	return rp;
}

int
main(int argc, char *argv[])
{
	int		rowIndex = 2;
	int		returnSize;
	int            *triangle = getRow(rowIndex, &returnSize);
	for (int i = 0; i <= rowIndex; i++) {
		printf("%d", triangle[i]);
		printf("\n");
	}
	return 0;
}
