#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isBadVersion(int version)
{
	if (version >= 1702766719)
		return 1;
	else
		return 0;
};

int search(int n1, int n2)
{
	if ((n2 - 1) == n1)
		return n2;
	else {
		int mid = ((unsigned)n1 + (unsigned)n2) / 2;
		if (isBadVersion(mid))
			n2 = mid;
		else
			n1 = mid;
		return search(n1, n2);
	}

}

int firstBadVersion(int n)
{
	if (isBadVersion(1))
		return 1;
	else
		return search(1, n);
}

int main(int argc, char *argv[])
{
	int n = 2126753390;
	printf("%d\n", firstBadVersion(n));
	return 0;
}
