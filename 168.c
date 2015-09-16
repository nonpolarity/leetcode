#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char           *
convertToTitle(int n)
{
	char           *s = (char *)malloc(sizeof(char) * 32);
	s[31] = '\0';
	int		i = 30;
	int		reminder;
	for (; n > 0;) {
		reminder = (n - 1) % 26 + 1;
		s[i--] = reminder - 1 + 'A';
		n = (n - reminder) / 26;
	}
	return &s[++i];
}

int
main(int argc, char *argv[])
{
	printf("The string for 26 is %s\n", convertToTitle(26));
	printf("The string for 52 is %s\n", convertToTitle(52));
	printf("The string for 78 is %s\n", convertToTitle(78));
	return 0;
}
