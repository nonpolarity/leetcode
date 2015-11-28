#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *countAndSay(int n)
{
	char *string = malloc(sizeof(char) * 10240);
	string[0] = '1';
	string[1] = '\0';
	if (!n)
		return 0;
	if (n == 1)
		return string;

	char *newstring = malloc(sizeof(char) * 10240);
	while (n > 1) {
		int i = 1, j = 1, k = 0;
		do {
			if (string[i] == string[i - 1]) {
				j++;
			} else {
				newstring[k++] = j + '0';
				newstring[k++] = string[i - 1];
				j = 1;
			}
		}
		while (string[i++] != '\0');
		newstring[k] = '\0';
		strcpy(string, newstring);
		n--;
	}
	return newstring;
}

int main(int argc, char *argv[])
{
	int number = atoi(argv[1]);
	char *result = countAndSay(number);
	if (*result != '\0')
		printf("%s", result);

	printf("\n");
	return 0;
}
