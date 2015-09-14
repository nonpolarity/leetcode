#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
myAtoi(char *str)
{
	if (str == 0)
		return 0;
	int		i = 0,	num = 0, sgn = 1;
	if (str[0] == '-') {
		i = 1;
		sgn = -1;
	}
	if (str[0] == '+') {
		i = 1;
	}
	if ((i == 1) & ((str[1] - '9') > 9 | (str[1] - '0') < 0))
		return 0;
	for (; str[i] != '\0'; i++) {
		if (0 <= str[i] - '0' & str[i] - '0' <= 9)
			num = num * 10 + str[i] - '0';
		if (str[i]=='-')
			sgn*=-1;
	}
	return num * sgn;
}


int
main(int argc, char *argv[])
{
	char		string    [] = "     010";
	printf("The atoi of 123 is %d\n", myAtoi(string));
	return 0;
}
