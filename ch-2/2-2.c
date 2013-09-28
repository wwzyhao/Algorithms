#include <stdio.h>
#include <stdlib.h>

int num[] = {3, 2, 1, 4, 5, 8, 6, 0, 7, 9};
int result[10];

void sorter() {
	int i, j, temp, flag, min = 9999;
	for(i = 0; i < 10; i++) {
		for(j = i; j < 10; j++) {
			if(min > num[j]) {
				flag = j;
				min = num[j];
			}
		}
		temp = num[i];
		num[i] = min;
		num[flag] = temp;
		min = 9999;
	}
}

int main() {
	int i = 0;
	printf("The original number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	sorter();
	printf("The sorted number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	return 0;
}