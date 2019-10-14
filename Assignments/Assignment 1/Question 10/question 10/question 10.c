#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996);

bool pairExist(int sum,int arr[20],int n) {
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (arr[i] + arr[j] == sum && i != j)
			{
				flag = 1;
				break;
			}
		}
	 }
	if (flag == 1) {
		return true;
	}
	else {
		return false;
	}
}

void main() {
	printf("Enter the number of elements you want in the array:\n");
	int n;
	scanf("%d", &n);
	int arr[20];
	printf("Enter the contents:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

	}
	printf("\nEnter the sum you want to see:\n");
	int sum;
	scanf("%d", &sum);
bool exist=	pairExist(sum,arr,n);
if (exist == true) {
	printf("\nPair whose sum is equal to the given sum exist in the array.\n");
 }
else {
	printf("\nThe required pairs do not exist.\n");
}
}