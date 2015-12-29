#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int strStr(char *haystack, char *needle)
{
	int len_h = strlen(haystack);
	int len_n = strlen(needle);

	if (!len_n)
		return 0;
	if (!len_h)
		return 0;

	if (len_h - len_n < 0)
		return -1;

	int *next = (int *)malloc(sizeof(int) * len_n);

	int j = 0, k = -1;
	next[j] = k;

	while (j < len_n) {

		if (k == -1 || needle[j] == needle[k])
			next[++j] = ++k;
		else
			k = next[k];
	}

	int h, i;
	for (i = 0, h = 0; i < len_n && h < len_h; i++, h++) {
		if (haystack[h] != needle[i]) {
			if (next[i] == -1) {
				h = h - i + 1;
				break;
			} else
				i = next[i];
		}
	}
	if (i == len_n)
		return h - i;
	return -1;
}

int main(int argc, char *argv[])
{
	char haystack[] = "mississippi";
	char needle[] = "issipi";
	int result = strStr(haystack, needle);
	printf("Result:%d\n", result);
	return 0;
}
