#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool
isValid(char *s)
{
	char		stack     [100];
	int		top = 0;
	while (*s != '\0') {
		if (*s == '(' | *s == '[' | *s == '{')
			stack[top++] = *s;
		if (*s == ')' | *s == ']' | *s == '}') {
			char		tmp = stack[top - 1];
			int		diff = *s - tmp;
			if (diff == 2 | diff == 1)
				top--;
			else
				return 0;
		}
		s++;
	}
	if (top == 0)
		return 1;
	else
		return 0;

}

int
main(int argc, char *argv[])
{
	char           *new = "()";
	bool		result = isValid(new);
	printf("the result:%d\n", result);
	return 0;
}
