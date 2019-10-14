#include<stdio.h>
#pragma warning(disable:4996);

minimizeSteps(int N, int W[100])
{
	int minSteps = 0;
	int min = W[0];
	for (int i = 1; i < N; i++)
	{
		if (min > W[i])
		{
			min = W[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		minSteps += (W[i] - min);
	}
	printf("The minimum steps are %d\n\n\n", minSteps);
}

void main()
{
	int T;
	int N;
	int W[100];
	printf("Enter the number of test cases:\n\n");
	scanf("%d", &T);

	if (T>=1 && T <= 100)
	{
		while (T >= 1) {
			printf("Enter the number of workers\n\n");
			scanf("%d", &N);
			printf("\n\n");
			printf("Enter the worker's salary:\n\n");

			if (N >= 1 && N <= 100)
			{


				for (int i = 0; i < N; i++)
				{
					scanf("%d", &W[i]);
				}
				minimizeSteps(N, W);

			}
			else {
				printf("Invalid number of inputs\n\n");

			}
			T--;
		}
	}

}