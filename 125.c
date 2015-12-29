#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool alphanumeric(char c)
{
	if ('A' <= c && c <= 'Z')
		return 1;

	if ('a' <= c && c <= 'z')
		return 1;
	if ('0' <= c && c <= '9')
		return 1;
	return 0;
}

bool isPalindrome(char *s)
{
	int len = strlen(s);
	if (!len)
		return 1;
	int head = 0, tail = len - 1;
	while (1) {
		while (!alphanumeric(s[head])) {
			head++;
			if (head >= tail)
				break;
		}
		while (!alphanumeric(s[tail])) {
			tail--;
			if (head >= tail)
				break;
		}
		if (head >= tail)
			break;
		char head_c = s[head], tail_c = s[tail];
		if ('A' <= head_c && head_c <= 'Z')
			head_c = head_c - 'A' + 'a';
		if ('A' <= tail_c && tail_c <= 'Z')
			tail_c = tail_c - 'A' + 'a';

		if (tail_c == head_c) {
			head++;
			tail--;
			continue;
		} else
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
//      char s[] = "A man, a plan, a canal: Panama";
	char s[] = "0P0";
	int result = isPalindrome(s);
	printf("Result:%d\n", result);
	return 0;
}
