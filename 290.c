#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26

void freehash(char **hash)
{
	for (int i = 0; i < MAX; i++) {
		if (hash[i])
			return;
		else
			free(hash[i]);
	}
}

bool wordPattern(char *pattern, char *str)
{
	char *hash[MAX];
	char hashp[MAX];

	char *token;
	int i = 0, j = 0;
	for (j = 0; j < MAX; j++) {
		hash[j] = 0;
	}

	for (j = 0; j < MAX; j++) {
		hashp[j] = 0;
	}

	for (token = strsep(&str, " "); token != NULL; token = strsep(&str, " ")) {
		for (j = 0; j < MAX; j++) {
			printf("\tj:%d\n", j);
			if (hash[j] == NULL) {
				hashp[j] = pattern[i];

				hash[j] = (char *)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(hash[j], token);
				hash[j][strlen(token)] = '\0';

				printf("\tWTF50!\thash[%d]:%s, token:%s\n\thashp[%d]:%c\tpattern[%d]:%c\n", j, hash[j], token, j, hashp[j], i,
				       pattern[i]);
				i++;
				break;
			}
//check if all the same tokens are mapped to same pattern 
			if (strcmp(hash[j], token) == 0) {
				if (hashp[j] != pattern[i]) {
					printf("\tWTF50!\thash[%d]:%s, token:%s\n\thashp[%d]:%c\tpattern[%d]:%c\n", j, hash[j], token, j, hashp[j], i,
					       pattern[i]);
					freehash(hash);
					return 0;
				} else {
					i++;
					break;
				}
			}
//check if all the same pattern are mapped from same str 
			if (hashp[j] == pattern[i]) {
				if (strcmp(hash[j], token) != 0) {
					printf("\tWTF61!\thash[%d]:%s, token:%s\n\tpattern[%d]:%c\n", j, hash[j], token, j, hashp[j]);
					return 0;
				}
			}
		}
	}
	if (pattern[i] != '\0') {
		freehash(hash);
		return 0;
	}
	freehash(hash);
	return 1;
}

int main(int argc, char *argv[])
{
	FILE *FILEP;
	FILE *FILES;
	char pattern[65536];
	char str[65536];
	FILEP = fopen(argv[1], "r");
	FILES = fopen(argv[2], "r");
	fgets(pattern, 65536, FILEP);
	fgets(str, 65536, FILES);
	pattern[strlen(pattern) - 1] = '\0';
	str[strlen(str) - 1] = '\0';
	printf("%s:%s\n", argv[1], pattern);
	printf("%s:%s\n", argv[2], str);
	bool result;
	result = wordPattern(pattern, str);
	printf("The result is %d.\n", result);
	return 0;
}
