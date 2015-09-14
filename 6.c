#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char           *
convert(char *s, int numRows)
{
	if (numRows == 1)
		return s;
	int		lenth = strlen(s);
	int		zig_l = numRows * 2 - 2;
	int		zig_w = numRows - 1;
	const int	Co = ((lenth + zig_l - 1) / zig_l) * zig_w;
	const int	Ro = numRows;
	char		a         [Ro][Co];
	int		i         , j, k = 0;
	for (j = 0; j < Co; j++) {
		for (i = 0; i < Ro; i++) {
			if (((j % zig_w == 0) | ((i + j) % zig_w == 0)) & (k < lenth))
				a[i][j] = s[k++];
			else
				a[i][j] = ' ';
		}
	}

	char           *ns = (char *)malloc(sizeof(char) * (lenth + 1));
	ns[lenth] = '\0';
	k = 0;
	for (i = 0; i < Ro; i++) {
		for (j = 0; j < Co; j++) {
			if ((a[i][j] != ' ') & (k < lenth))
				ns[k++] = a[i][j];
		}
	}
	return ns;
}
int
main(int argc, char *argv[])
{
	char           *original = "PAYPALISHIRING";
	printf("the converted string of %s is %s\n", original, convert(original, 3));
	return 0;
}
