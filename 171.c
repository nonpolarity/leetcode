#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int
titleToNumber(char *s)
{
	int		num = 0;
	for (; *s != '\0'; s++) {
		num = num * 26 + *s - 'A' + 1;

	}
	return num;
}


int
main(int argc, char *argv[])
{
	return 0;
}
