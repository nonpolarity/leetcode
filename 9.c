#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool
isPalindrome(int x)
{
	if (x < 0)
		return 0;
	int		old = x,	new = 0;
	while (old >= 1) {
		new = new * 10 + old % 10;
		old/=10;
	}
	return (new == x);
}

int
main(int argc, char *argv[])
{
	return 0;
}
