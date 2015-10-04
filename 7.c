#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int
reverse(int x)
{
	int		result = 0, prefix = 1;
	if (x == INT_MIN)
		return 0;
	if (x < 0) {
		prefix = -1;
		x = -x;
	}
	while (x != 0) {
		if (prefix == 1 & result > (INT_MAX - x % 10) / 10)
			return 0;
		if (prefix == -1 & result > (INT_MAX - x % 10) / 10)
			return 0;
		result = result * 10 + x % 10;
		x = x / 10;
	}
	return result * prefix;
}

int
main(int argc, char *argv[])
{
	printf("The reverse of 1534236469 is %d\n", reverse(1534236469));
	printf("The reverse of 0 is %d\n", reverse(0));
	printf("The reverse of -321 is %d\n", reverse(-321));
	printf("The reverse of INT_MAX is %d\n", reverse(INT_MAX));
	printf("The reverse of INT_MIN is %d\n", reverse(INT_MIN));
	return 0;
}
