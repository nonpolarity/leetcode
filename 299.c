#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *getHint(char *secret, char *guess)
{
	int num_bull = 0;
	int num_cow = 0;
	char hash_secret[10];
	char hash_guess[10];

	memset(hash_secret, 0, 10);
	memset(hash_guess, 0, 10);

	for (int i = 0; i < strlen(secret); i++) {
		if (secret[i] == guess[i])
			num_bull++;
		else {
			hash_secret[secret[i] - '0']++;
			hash_guess[guess[i] - '0']++;
		}
	}

	for (int i = 0; i < 10; i++) {
		while (hash_secret[i]-- && hash_guess[i]--)
			num_cow++;
	}

	int lenth = 128;
	char *result = (char *)malloc(sizeof(char) * lenth);
	memset(result, 0, lenth);
	sprintf(result, "%d%s%d%s", num_bull, "A", num_cow, "B");

	return result;
}

int main(int argc, char *argv[])
{
	char *secret = "11111111112222222222";
	char *guess = "22222222221111111111";
	char *result = getHint(secret, guess);
	printf("%s\n", result);
	return 0;
}
