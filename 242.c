#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
isAnagram(char *s, char *t)
{
	if (strlen(s) != strlen(t))
		return 0;
	int		count      [26];
	int		i = 0;
	for (i = 0; i < 26; i++)
		count[i] = 0;
	for (i = 0; i < strlen(s); i++)
		count[s[i] - 'a']++;
	for (i = 0; i < strlen(t); i++)
		count[t[i] - 'a']--;
	for (i = 0; i < 26; i++)
		if (count[i] != 0)
			return 0;
	return 1;
}

int
main(int argc, char *argv[])
{
	printf("The result of a and ab is %d\n", isAnagram("a", "ab"));
	return 0;
}
