#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char
convert(int num)
{
	char		ch = '\0';
	switch (num) {
	case 1:
		ch = 'I';
		break;
	case 5:
		ch = 'V';
		break;
	case 10:
		ch = 'X';
		break;
	case 50:
		ch = 'L';
		break;
	case 100:
		ch = 'C';
		break;
	case 500:
		ch = 'D';
		break;
	case 1000:
		ch = 'M';
		break;
	default:
		ch = '\0';
		break;
	};
	return ch;

};

char           *
intToRoman(int num)
{
	int		i = 0;
	char           *result = (char *)malloc(sizeof(char) * 32);
	while ((num - 1000) >= 0) {
		result[i++] = convert(1000);
		num -= 1000;
	}
	while ((num - 900) >= 0) {
		result[i++] = convert(100);
		result[i++] = convert(1000);
		num -= 900;
	}
	while ((num - 500) >= 0) {
		result[i++] = convert(500);
		num -= 500;
	}
	while ((num - 400) >= 0) {
		result[i++] = convert(100);
		result[i++] = convert(500);
		num -= 400;
	}
	while ((num - 100) >= 0) {
		result[i++] = convert(100);
		num -= 100;
	}
	while ((num - 90) >= 0) {
		result[i++] = convert(10);
		result[i++] = convert(100);
		num -= 90;
	}
	while ((num - 50) >= 0) {
		result[i++] = convert(50);
		num -= 50;
	}
	while ((num - 40) >= 0) {
		result[i++] = convert(10);
		result[i++] = convert(50);
		num -= 40;
	}
	while ((num - 10) >= 0) {
		result[i++] = convert(10);
		num -= 10;
	}
	while ((num - 9) >= 0) {
		result[i++] = convert(1);
		result[i++] = convert(10);
		num -= 9;
	}
	while ((num - 5) >= 0) {
		result[i++] = convert(5);
		num -= 5;
	}
	while ((num - 4) >= 0) {
		result[i++] = convert(1);
		result[i++] = convert(5);
		num -= 4;
	}
	while ((num - 1) >= 0) {
		result[i++] = convert(1);
		num -= 1;
	}
	result[i] = '\0';
	return result;

}

int
main(int argc, char *argv[])
{
	for (int i = 3999; i > 0; i--)
		printf("The convert of %d is %s\n", i, intToRoman(i));
	return 0;
}
