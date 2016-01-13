#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int numTrees(int n)
{
	if (n == 0 || n == 1)
		return 1;
	int result = 0;
	if (n > 1) {
		int left = 0, right = 0;
		for (left = 0; left < n; left++) {
			right = n - left - 1;
			result += numTrees(left) * numTrees(right);
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	int num = 5;
	int result = numTrees(num);
	printf("Result:%d\n", result);
	return 0;
}
