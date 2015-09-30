#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void
swap(int *a, int *b)
{
	int		tmp;
	if (*a < *b) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
int
computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	swap(&C, &A);
	swap(&G, &E);
	swap(&D, &B);
	swap(&H, &F);
	int		sum = 0;
	sum += (C - A) * (D - B) + (G - E) * (H - F);
	if (C < E | A > G | B > H | D < F)
		return sum;
	int		dx        , dy;
	if (A <= E & C <= G)
		dx = C - E;
	if (E <= A & C <= G)
		dx = C - A;
	if (E <= A & G <= C)
		dx = G - A;
	if (A <= E & G <= C)
		dx = G - E;
	if (F <= B & H <= D)
		dy = H - B;
	if (B <= F & H <= D)
		dy = H - F;
	if (B <= F & D <= H)
		dy = D - F;
	if (F <= B & D <= H)
		dy = D - B;
	return sum - dx * dy;

}


int
main(int argc, char *argv[])
{
	int		a = -2,	b = -2, c = 2, d = 2, e = -2, f = -2, g = 2, h = 2;
	int		result = computeArea(a, b, c, d, e, f, g, h);
	printf("The result is %d\n", result);
	return 0;
}
