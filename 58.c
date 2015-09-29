#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
lengthOfLastWord(char *s)
{
	int		len = 0,	tmp = 0;
	while (*s != '\0') {
		if (*s == ' ') {
			tmp = len ? len : tmp;
			len = 0;
		} else {
			len++;
		}
		s++;
	}
	if (*(--s) == ' ')
		return tmp;
	else
		return len;
}


int
main(int argc, char *argv[])
{
	char           *str = "b   a    ";
	int		len = lengthOfLastWord(str);
	printf("the word lenth is %d\n", len);
	return 0;
}
