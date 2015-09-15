#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
hammingWeight(uint32_t n)
{
	int		i = 0;
	while (n > 0) {
		if (n & 0x01)
			i++;
		n = n >> 1;
	}
	return i;
}

int
main(int argc, char *argv[])
{
	return 0;
}
