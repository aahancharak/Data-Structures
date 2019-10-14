#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

struct pair {
	int max;
	int min;
};

struct pair getMaxandMin (int arr[50],int n){
	struct pair minmax;
	if (n == 1) {
	   minmax.max = arr[1];
		minmax.min = arr[1];
   }
	else {
		if (arr[0] > arr[1]) {
			minmax.min = arr[1];
			minmax.max = arr[0];
		}
		else if (arr[0] < arr[1]) {
			minmax.min =arr[0];
			minmax.max = arr[1];
		}

		for (int i = 2; i < n; i++)
		{
			if (arr[i] > minmax.max) {
				minmax.max = arr[i];
			}
			else if (arr[i] < minmax.min) {
				minmax.min = arr[i];
			}

			
		}
	}
	return minmax;

};

void main()
{

	int n;
	printf("Enter how many numbers you want in the array :\n");
	scanf("%d", &n);
	printf("\n\n");
	int* arr = (int*)malloc(sizeof(int) * n);
	printf("Enter the contents of the array :\n\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		printf("\n");

	}
	struct pair maxandMin= getMaxandMin(arr, n);
	printf("\n\nThe maximum and minimum are :\n");
	printf("Max : %d Min : %d", maxandMin.max, maxandMin.min);

}