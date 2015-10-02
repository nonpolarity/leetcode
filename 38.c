#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char           *
countAndSay(int n)
{
	char           *string = malloc(sizeof(char) * 512);
	string[0] = '1';
	string[1] = '\0';
	if (!n)
		return 0;
	if (n == 1)
		return string;
	char           *index = string;
	char		newstring [512];
	char           *newindex = newstring;
	while (n >= 2) {
		while (*index != '\0') {
			if (*index == '1') {
				if (*(index + 1) == '1') {
					*(newindex++) = '2';
					index++;
				} else
					*(newindex++) = '1';
				*(newindex++) = '1';
				index++;
			}
			if (*index == '2') {
				*(newindex++) = '1';
				*(newindex++) = '2';
				index++;
			}
		}
		*newindex = '\0';
		index = string;
		newindex = newstring;
		while (*newindex != '\0') {
			*(index++) = *(newindex++);
		}
		index = string;
		newindex = newstring;
		n--;
	}
	return string;
}

int
main(int argc, char *argv[])
{
	int		number = 3;
	char           *result = countAndSay(number);
	while (*result != '\0')
		printf("%c", *(result++));

	printf("\n");
	return 0;
}
