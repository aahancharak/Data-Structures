#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

void main()
{
	int n;
	printf("Enter how many numbers you want in the array :\n\n");
	scanf("%d", &n);
	
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	printf("\n\n\n");
	printf("Enter the elements of the array :\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\n\n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == j)
			{
				arr[j] = i;
			}
		}
	}
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}






}