#include<stdio.h>
#include<stdbool.h>
#pragma warning(disable:4996);

void elephantSatisified(int N, int C, int AK[100],int T) {
	int ctr = 0;
	if(N<1 || N>100 || C<0)
	{
		printf("Invalid input\n\n");
	}
	
	else {
		for (int i = 0; i < N; i++)
		{
			if (C - (2 + AK[i]) >= 0) {
				C -= (2 + AK[i]);
				ctr++;
			}
			else {
				break;
			}

		}
		if (ctr==N)
		{
			printf("Elephant's were satisfied. Test case %d passed.\n\n", T + 1);
		}
		else {
			printf("Elephants were not satisfied.Test case %d failed.\n\n", T + 1);
			
		}
	}

}

void main()
{
	printf("Enter the number of test cases :\n");
	int T;
	scanf("%d", &T);
	printf("******************************************\n\n");
	int N;
	int C;
	int AK[100];
	int eachToffee[100];
	if (T >= 1 && T <= 1000) {

		for (int i = 0; i < T; i++) {
			printf("Enter the number of elephants and test candies:\n");
			scanf("%d %d", &N, &C);
			printf("Enter the min toffees of each elephant(+2 will make it happy) :\n\n");
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &AK[j]);
				printf("\n");
			}
			elephantSatisified(N, C, AK, i);
		}
	}
	else if(T<=0){
		printf("No test cases.\n\n");
	}
	else {
		printf("Test cases limit bypassed.\n\n");
	}
	
	
}