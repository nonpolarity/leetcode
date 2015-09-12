#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char           *
addBinary(char *a, char *b)
{
	int		i = 0,	lenth = 0;
	int		cin = 0,	cout = 0;
	lenth = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	char           *c = (char *)malloc(sizeof(char) * (lenth + 2));
	c[lenth + 1] = '\0';
	for (i = lenth; i > 0; i--) {
		//printf("i:%d\n", i);
		int		A         , B, C;
		if ((lenth - i + 1) <= strlen(a))
			A = a[strlen(a) - 1 - lenth + i] - '0';
		else
			A = 0;
		//printf("A:%c\n", A);
		if ((lenth - i) + 1 <= strlen(b))
			B = b[strlen(b) - 1 - lenth + i] - '0';
		else
			B = 0;
		//printf("B:%c\n", B);
		C = A ^ B ^ cin;
		//printf("c[i]:%d\n", A ^ B ^ cin);
		cout = (A & B) | (cin & (A | B));

		cin = cout;
		c[i] = C + '0';
		//printf("cin:%c\n\n", cin);
	}
	if (cout == 1) {
		c[0] = '1';
		return c;
	}
	//
		else
		//c[0] = '0';
	return c + 1;
}

int
main(int argc, char *argv[])
{
	printf("the Binary sum of %s and %s is %s\n", argv[1], argv[2],
	       addBinary(argv[1], argv[2]));
	return 0;
}
