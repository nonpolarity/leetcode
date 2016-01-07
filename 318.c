#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int maxProduct(char **words, int wordsSize)
{
	unsigned long long *mark = (unsigned long long *)malloc(sizeof(unsigned long long) * wordsSize);

	memset(mark, 0, sizeof(unsigned long long) * wordsSize);
	for (int i = 0; i < wordsSize; i++) {
		for (int j = 0; words[i][j] != '\0'; j++)
			mark[i] = mark[i] | 1 << (words[i][j] - 'a');
	}

	int result = 0;
	for (int i = 0; i < wordsSize - 1; i++) {
		for (int j = i + 1; j < wordsSize; j++)
			if (!(mark[i] & mark[j]))
				if (result < strlen(words[i]) * strlen(words[j])) {
					result = strlen(words[i]) * strlen(words[j]);
				}
	}

	return result;
}

int main(int argc, char *argv[])
{
	char *word[] = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	int wordsSize = 6;

	for (int i = 0; i < wordsSize; i++) {
		printf("%s\n", word[i]);
	}
	int result = maxProduct(word, wordsSize);
	printf("%d\n", result);

	return 0;

}
