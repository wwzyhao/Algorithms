#include <stdio.h>
#include <stdlib.h>

int num[] = {3, 2, 1, 4, 5, 8, 6, 0, 7, 9};
int result[10];

void insertor(int n) {
	int i = 0;

	if(n <= 1)
		return;
	
	insertor(n-1);
	int temp = num[n-1];
	for(i = n-2; i >= 0; i--) {
		if(temp < num[i]) 
			num[i+1] = num[i];
		else
			break;
	}

	num[i + 1] = temp;

	return;
}

int main (){
	int i = 0;
	printf("The original number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	insertor(10);
	printf("The sorted number is: \n");
	for(i = 0; i < 10; i++)
		printf("%d  ", num[i]);
	putchar('\n');
	return 0;
}