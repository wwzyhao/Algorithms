#include <stdio.h>
#include <stdlib.h>

int num[] = {3, 2, 1, 4, 5, 8, 6, 0, 7, 9};
int result[10];

int biSearch(int n, int left, int right) {
	if(right - left > 1) {
		int middle = (left + right) / 2;
		if(n < num[middle])
			return biSearch(n, left, middle);
		if(n > num[middle])
			return biSearch(n, middle, right);
	}
	else 
		return right;
	ever
	{
		if(n == num[left])
			return left;
		if(n == num[right])
			return right;
		else 
			return -999;
	}
}

int insertor() {
	int i, j;
	result[0] = num[0];
	for(i = 1; i < 10; i++) {
		int temp = num[i];
		for(j = i; j > 0 && temp < result[j-1]; j--) 
			result[j] = result[j-1];
		result[j] = temp;
	}
}

int main() {
	int i = 0;
	printf("The original number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	insertor();
	printf("The sorted number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", result[i]);
	putchar('\n');
	return 0;
}