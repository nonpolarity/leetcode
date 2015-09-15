#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
myAtoi(char *str)
{
	//skip the spaces
	while (*str == ' ')
		str++;
	if (('9' < *str | '0' > *str) & (*str != '+') & (*str != '-'))
		return 0;
	int		sgn = 1;
	unsigned long long num = 0;
	if ((*str == '-') | (*str == '+')) {
		if ((*(str + 1) == '-') | (*(str + 1) == '+'))
			return 0;
		if (*str == '-') {
			sgn = -1;
			str++;
		} else
			str++;
	}
	for (; ('0' <= *str & *str <= '9'); str++) {
		num = num * 10 + *str - '0';
		if ((num >= (unsigned long long)INT_MAX) & (sgn == 1))
			return INT_MAX;
		if ((num > (unsigned long long)INT_MAX) & (sgn == -1))
			return INT_MIN;
	}
	return num * sgn;
}
int
main(int argc, char *argv[])
{
	char		string    [] = "-2147483648";
	printf("The atoi of %s is %d\n", string, myAtoi(string));
	return 0;
}
