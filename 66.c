#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int            *
plusOne(int *digits, int digitsSize, int *returnSize)
{
	if (digitsSize == 0 | digits == 0) {
		*returnSize = 0;
		return digits;
	}
	int		allnines = 1;
	for (int i = 0; i < digitsSize; i++) {
		if (digits[i] != 9) {
			allnines = 0;
			break;
		}
	}
	if (allnines == 1) {
		*returnSize = digitsSize + 1;
		int            *rp = (int *)malloc(sizeof(int) * (*returnSize));
		//memset(rp, 0, *returnSize);
		for (int i = 1; i < *returnSize; i++)
			rp[i] = 0;
		rp[0] = 1;
		return rp;
	}
	int		carry = 0;
	*returnSize = digitsSize;
	int		current = digits[digitsSize - 1];
	digits[digitsSize - 1] = (current + 1 + carry) % 10;
	carry = (current + 1 + carry) / 10;
	if (digitsSize == 1) {
		return digits;
	}
	for (int i = digitsSize - 2; i >= 0; i--) {
		current = digits[i];
		digits[i] = (current + carry) % 10;
		carry = (current + carry) / 10;
	}
	return digits;

}

int
main(int argc, char *argv[])
{
	const int	digitSize = 4;
	int		digits     [digitSize] = {8, 9, 9, 9};
	int            *returnSize = (int *)malloc(sizeof(int));
	int            *result = plusOne(digits, digitSize, returnSize);
	printf("The result of 0 plus one is:\n");
	for (int i = 0; i < *returnSize; i++) {
		printf("%d", result[i]);
	}
	printf("\n");
	return 0;
}
