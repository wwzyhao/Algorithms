#include <stdio.h>
#include <stdlib.h>

int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int biSearch(int n, int left, int right) {
	if(right - left > 1) {
		int middle = (left + right) / 2;
		if(n < num[middle])
			return biSearch(n, left, middle);
		else if(n > num[middle])
			return biSearch(n, middle, right);
		else
			return middle;
	}
	else {
		if(n == num[left])
			return left;
		if(n == num[right])
			return right;
		else return -999;
	}
}

int main() {
	int n, i, result;
	printf("Input a number: ");
	scanf("%d", &n);
	putchar('\n');
	result = biSearch(n, 0, 9);
	if(result == -999)
		printf("No such number~!\n");
	else
		printf("Find this number, in position %d\n", result);
}