#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
	int hash[256] = { 0 };
	int i, j;
	int index;
	for (i = 0; s[i] != '\0'; i++) {
		index = s[i];
		if (hash[index] == 0) {
			for (j = 0; j < 256; j++) {
				if (hash[j] == t[i])
					return false;
			}
			hash[index] = t[i];
		} else {
			if (hash[index] != t[i])
				return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	FILE *FILES;
	FILE *FILET;

	char s[65536];
	char t[65536];

	FILES = fopen(argv[1], "r");
	FILET = fopen(argv[2], "r");
	fgets(s, 65536, FILES);
	fgets(t, 65536, FILET);

	printf("%s:%s\n", argv[1], s);
	printf("%s:%s\n", argv[2], t);

	bool result;
	result = isIsomorphic(s, t);
	printf("The result is %d.\n", result);

	return 0;
}
