#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int flag = 0;
int temp = 0;
int num[] = {3, 2, 1, 4, 5, 8, 6, 0, 7, 9};
int result[10];

void merge(left, middle, right) {
	printf("%d %d %d\n", left, middle, right);
	int i = 0, j = 0, k=0;
	int la = middle - left+ 1;
	int lb = right - middle;
	int *a = (int*)malloc(la * sizeof(int));
	int *b = (int*)malloc(lb * sizeof(int));
	
	for(i = 0, k = left; i < la; i++, k++) {
		a[i] = num[k];
		printf("a = %d ", a[i]);
	}
	putchar('\n');

	for(j=0, k = middle + 1; j < lb; j++, k++) {
		b[j] = num[k];
		printf("b = %d ", b[j]);
		printf("k = %d ", k);
	}
	putchar('\n');

	for(i = 0, j = 0, k = left; i < la && j < lb; k++) {
		if(a[i] < b[j]) {
			num[k] = a[i];
			i++;
		}
		else {
			num[k] = b[j];
			j++;
		}
	}
	if(i < la)
		for( ;i < la; i++, k++)
			num[k] = a[i];
	if(j < lb)
		for( ;j < lb; j++, k++)
			num[k] = b[j];

	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	printf("flag = %d\n", flag++);

	return;
}

void mergeSort(int left, int right) {
	int i = 0;
	int middle = (left + right) / 2;
	if(left < right) {
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, middle, right);
	}
}

int main() {
	int i = 0;
	printf("The original number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');

	mergeSort(0, 9);

	printf("The sorted number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	return 0;
}