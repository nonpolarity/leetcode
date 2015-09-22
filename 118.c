#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int           **
generate(int numRows, int **columnSizes, int *returnSize)
{
	if (numRows == 0)
		return 0;
	*returnSize = numRows;
	*columnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	int           **rp = (int **)malloc(sizeof(int *) * numRows);
	int		i         , j;
	for (i = 0; i < numRows; i++) {
		rp[i] = (int *)malloc(sizeof(int) * (i + 1));
		(*columnSizes)[i] = i + 1;
		//(*columnSizes)[i] and *columnSizes[i] are different ! !!
				rp            [i][0] = 1;
		rp[i][i] = 1;
	}
	for (i = 2; i < numRows; i++)
		for (j = 1; j < i; j++)
			rp[i][j] = rp[i - 1][j - 1] + rp[i - 1][j];
	return rp;
}


int
main(int argc, char *argv[])
{
	int		numRows = 9;
	int		returnSize;
	int            *columSizes;
	int           **triangle = generate(numRows, &columSizes, &returnSize);
	for (int i = 0; i < numRows; i++) {
		for (int k = numRows - i - 1; k >= 0; k--)
			printf("\t");
		for (int j = 0; j <= i; j++)
			printf("%d\t\t", triangle[i][j]);
		printf("\n");
	}
	return 0;
}
