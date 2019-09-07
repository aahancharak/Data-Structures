#include<stdio.h>
#pragma warning(disable :4996);

void safeHouses(int M, int houses[150], int x, int y) {
	//Number of houses searched in time limit
	//x is the house per minute and y is the maximum time searched
	int nhs = x * y;
	int sum = 0;
	int arr[156];
	int min, max;
	for (int i = 0; i < M; i++)
	{
		min = houses[i] - x * y;
		max = houses[i] + x * y;
		min < 1 ? min = 1 : min;
		max > 150 ? max = 150 : max;
		for (int i = min - 1; i < max; i++)
		{
			arr[i] = 1;
		}


	}
	for (int i = 0; i < 150; i++)
	{
		if (arr[i] != 1) {
			sum++;
		}
	}
	printf("Number of empty houses are : %d\n\n", sum);
	
	

}

void main()
{
	int M, x, y;
	int houses[150];
	printf("Enter the number of test cases .\n\n");
	int T;
	scanf("%d", &T);
	printf("\n\n");
	
	if (T >= 1 && T <= 10000)
	{
		while (T >= 1)
		{
			printf("Enter no of police houses,x and y:\n\n");
			scanf("%d %d %d", &M, &x, &y);
			printf("Enter house number of police: \n\n");
			if (M < 150 && M>=1) {
				for (int i = 0; i < M; i++)
				{
					scanf("%d", &houses[i]);
				}
				 safeHouses(M, houses, x, y);
			}
			else {
				printf("Houses cant be that much :\n\n");
			}
			T--;
		}
	}
}