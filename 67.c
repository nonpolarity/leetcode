#include <stdio.h>
#include <stdlib.h>

char           *
addBinary(char *a, char *b)
{
	long int	x = 0,	y = 0, z = 0;
	int		i = 0,	lenth = 0;
	lenth = sizeof(&a) > sizeof(&b) ? sizeof(&a) : sizeof(&b);
	char           *c = (char *)malloc(lenth * 4);
	for (i = 0; a[i] != '\0'; i++) {
		x = (a[i] - '0') + x * 2;
	}
	for (i = 0; b[i] != '\0'; i++) {
		y = (b[i] - '0') + y * 2;
	}
	z = x + y;
	for (i = 0; z > 0; i++) {
		c[i] = (z - z / 2 * 2) + '0';
		z = z / 2;
		if (z < 1) {
			i++;
			break;
		}
	}
	c[i] = '\0';
	int		j;
	char		temp;
	for (j = 0; j < i / 2; j++) {
		temp = c[j];
		c[j] = c[i - 1 - j];
		c[i - 1 - j] = temp;
	}
	return c;
}

int
main(int argc, char *argv[])
{
	printf("the Binary sum of %s and %s is %s\n", argv[1], argv[2], addBinary(argv[1], argv[2]));
	return 0;
}
