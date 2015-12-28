#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int strStr(char *haystack, char *needle)
{
	int len_h = strlen(haystack);
	int len_n = strlen(needle);
	if (len_h - len_n < 0)
		return -1;

	for (int h = 0; h < len_h - len_n + 1; h++) {
		int i;
		for (i = 0; i < len_n; i++)
			if (haystack[h + i] != needle[i])
				break;
		if (i == len_n)
			return h;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	char haystack[] = "abcdefg";
	char needle[] = "effg";
	int result = strStr(haystack, needle);
	printf("Result:%d\n", result);
	return 0;
}
