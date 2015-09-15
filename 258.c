#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int
addDigits(int num)
{
	if (num == 0)
		return 0;
	return (num % 9 ? num % 9 : 9);
}

int
main(int argc, char *argv[])
{
	int		num = 0;
	printf("the result of %d is %d\n", num, addDigits(num));
	return 0;
}
