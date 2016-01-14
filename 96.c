#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int numTrees(int n)
{
	int result[512];
	result[0] = 1;
	result[1] = 1;
	for (int i = 2; i <= n; i++) {
		int left = 0, right = 0;
		int sum = 0;
		for (left = 0; left < i; left++) {
			right = i - left - 1;
			sum += result[left] * result[right];
		}
		result[i] = sum;
	}
	return result[n];
}

int main(int argc, char *argv[])
{
	int num = 5;
	int result = numTrees(num);
	printf("Result:%d\n", result);
	return 0;
}
