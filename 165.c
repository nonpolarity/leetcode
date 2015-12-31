#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareVersion(char *version1, char *version2)
{
	char *saverptr1 = NULL;
	char *saverptr2 = NULL;
	char *token1 = strtok_r(version1, ".", &saverptr1);
	char *token2 = strtok_r(version2, ".", &saverptr2);

	int num1, num2;

	while (token1 || token2) {
		printf("\t%s\t%s\n", token1, token2);
		num1 = (token1) ? atoi(token1) : 0;
		num2 = (token2) ? atoi(token2) : 0;

		if (num1 > num2)
			return 1;
		else if (num1 < num2)
			return -1;

		token1 = strtok_r(NULL, ".", &saverptr1);
		token2 = strtok_r(NULL, ".", &saverptr2);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char version1[] = "1.0.3";
	char version2[] = "1";
	int result = compareVersion(version1, version2);
	printf("Result: %d\n", result);
	return 0;
}
