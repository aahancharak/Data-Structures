#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996);

bool isSubset(int arr1[20], int arr2[20], int n1, int n2) {
	int ctr = 0;
	for (int i =0 ; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (arr2[i] == arr1[j]) {
				ctr++;
				continue;
			}
		}
	}
	
	if (ctr >= n2) {
		return true;
	}
	else{
		return false;
	}
}
void main() {
	printf("\nEnter the number of element in array 1:\n");
	int n1;
	scanf("%d", &n1);
	int arr1[20];
	printf("\n");
	printf("Enter the numbers.\n");
	for (int i = 0; i < n1; i++) {
		scanf("%d", &arr1[i]);
	}
	printf("\n\n");
	printf("\nEnter the number of elements in array 2:\n");
	int n2;
	scanf("%d", &n2);
	int arr2[20];
	printf("\n");
	printf("Enter the numbers.\n");
	for (int i = 0; i < n2; i++) {
		scanf("%d", &arr2[i]);
	}
	if (n1 > n2) {
		bool subset=isSubset(arr1, arr2, n1, n2);
		if (subset == true) {
			printf("Array 2 is subset of array 1.\n");

		}
		else
			printf("Array 2 is not subset.\n");
	}
	else if (n2 > n1){
		bool subset=isSubset(arr2,arr1,n2,n1);
		if (subset == true)
			printf("Array 1 is subset of array 2.\n");
		else
			printf("Array 1 is not a subset.\n");
		}
	else {
		bool subset = isSubset(arr2, arr1, n2, n1);
		if (subset == true)
			printf("Both are subsets of each other");
		else
			printf("Both are not subsets.\n");
		
	}
	


}