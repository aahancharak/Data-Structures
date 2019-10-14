#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996);

void sort(int* p, int n) {
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(p + i) > * (p + j)) {
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
	printf("\n\n\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", *(p + i));
	}
}


void main() {

	printf("Enter how many numbers you want in the array :\n\n");
	int n;
	scanf("%d", &n);

	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	printf("Enter the elements of the array :\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

 sort(arr,n);





}