#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int maxProfit(int *prices, int pricesSize)
{
	int profit = 0;
	for (int i = 1; i < pricesSize; i++) {
		profit += (prices[i] > prices[i - 1] ? (prices[i] - prices[i - 1]) : 0);
	}
	return profit;

}

int main(int argc, char *argv[])
{
	int prices[] = { 1, 9, 2, 2, 3, 3, 4, 5 };
	int pricesSize = 8;
	int result = maxProfit(prices, pricesSize);
	printf("result:%d\n", result);
	return 0;
}
