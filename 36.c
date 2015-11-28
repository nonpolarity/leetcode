#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool vaildlinev(char *root, int Col)
{
	char a[10];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 9; i++) {
		printf("i:%d\n", i);
		if (*(root + Col * i) >= '0' && *(root + Col * i) <= '9') {
			int value = *(root + Col * i) - '0';
			printf("value:%c\n", *(root + Col * i));
			if (a[value] == 1) {
				printf("Err!\n");
				return 0;
			} else
				a[value] = 1;
		}
	}
	return 1;
}

bool vaildlineh(char *root)
{
	char a[10];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 9; i++) {
		if (*(root + i) >= '0' && *(root + i) <= '9') {
			int value = *(root + i) - '0';
			if (a[value] == 1)
				return 0;
			else
				a[value] = 1;
		}
	}
	return 1;
};

bool vaildsquare(char *root, int Col)
{
	char a[10];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (*(root + Col * i + j) >= '0' && *(root + Col * i + j) <= '9') {
				int value = *(root + Col * i + j) - '0';
				if (a[value] == 1)
					return 0;
				else
					a[value] = 1;
			}
		}
	}
	return 1;
}

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	int i, j;

	for (i = 0; i < boardRowSize - 8; i++)
		for (j = 0; j < boardColSize; j++) {
			if (!vaildlinev(*board + i * boardColSize + j, boardColSize)) {
				return 0;
			}
		}
	/*
	 * for (i = 0; i < boardRowSize; i++) for (j = 0; j < boardColSize -
	 * 8; j++) { if (!vaildlineh(*board + i * boardColSize + j)) return
	 * 0; }
	 * 
	 * 
	 * for (i = 0; i < boardRowSize - 2; i++) for (j = 0; j < boardColSize -
	 * 2; j++) { if (!vaildsquare(*board + i * boardColSize + j,
	 * boardColSize)) return 0; }
	 */
	return 1;
}

int main(int argc, char *argv[])
{
	char tmp[9][9] = { "..4...63.", ".........", "5......9.", "...56....", "4.3.....1", "...7.....", "...5.....", ".........", "........." };
	char *board[9];
	for (int i = 0; i < 9; i++)
		board[i] = tmp[i];
	//char         *board[] = {tmp[0]};

	//char         *tmp1 = tmp[0];
	int boardRowSize = 9;
	int boardColSize = 9;
	printf("the array:\t%d\n", isValidSudoku(board, boardRowSize, boardColSize));
	return 0;
}
