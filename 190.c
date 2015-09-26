#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

uint32_t
reverseBits(uint32_t n)
{
	uint32_t	tmp   , ans = 0;
	for (int i = 0; i < 32; i++) {
		tmp = n;
		n >>= 1;
		ans <<= 1;
		ans += (tmp - (n << 1));
	}
	return ans;
}


int
main(int argc, char *argv[])
{
	uint32_t	number = 43261596;
	printf("The number is %u\n", number);
	printf("The reverse of number is %u\n", reverseBits(number));
	return 0;
}
