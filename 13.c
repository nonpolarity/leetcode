#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
convert(char c)
{
	int		result;
	switch (c) {
	case 'I':
		result = 1;
		break;
	case 'V':
		result = 5;
		break;
	case 'X':
		result = 10;
		break;
	case 'L':
		result = 50;
		break;
	case 'C':
		result = 100;
		break;
	case 'D':
		result = 500;
		break;
	case 'M':
		result = 1000;
		break;
	case '\0':
	default:
		result = 0;
		break;
	};
	return result;

};



int
romanToInt(char *s)
{

	int		sum = 0,	tmp = 0, sgn = 1, i = 1;
	while (*s != '\0') {
		tmp += convert(*s);
		if (convert(*(s + 1)) > convert(*s)) {
			sgn = -1;
			sum += tmp * sgn;
			tmp = 0;
		}
		if (convert(*(s + 1)) < convert(*s)) {
			sgn = 1;
			sum += tmp * sgn;
			tmp = 0;
		}
		s++;
	}
	return sum;

}


int
main(int argc, char *argv[])
{
	char           *roman[] = {"LXXXVIII", "XLIX", "DCCCXC"};
	for (int i = 0; i < 3; i++)
		printf("The convert of %s is %d\n", roman[i], romanToInt(roman[i]));
	return 0;
}
