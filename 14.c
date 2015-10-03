#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

char           *
longestCommonPrefix(char **strs, int strsSize)
{
	char           *common = malloc(sizeof(char) * 128);
	memset(common, 0, sizeof(char) * 128);
	if (strs==0 | strsSize==0) return common;
	int		i         , j, len = INT_MAX;
	for (i = 0; i < strsSize; i++) {
		if (strlen(strs[i]) < len)
			len = strlen(strs[i]);
	}
	for (j = 0; j < len; j++) {
		for (i = 1; i < strsSize; i++) {
			if (strs[0][j] != strs[i][j])
				return common;
		}
		common[j] = strs[0][j];
	}
	return common;
}

int
main(int argc, char *argv[])
{
	return 0;
}
