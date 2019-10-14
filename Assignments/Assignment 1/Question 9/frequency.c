#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

struct node {
	int data;
	struct node* next;
}*head;

void getData(int n) {
	struct node* temp, * nextItem;
	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		printf("\nMemory not allocated.\n");
	}
	else {
		int data;
		printf("\nEnter the data:\n");
		scanf("%d", &data);
		head->data = data;
		head->next = NULL;
		temp = head;
		for (int i = 0; i < n; i++) {
			nextItem = (struct node*)malloc(sizeof(struct node));
			printf("\nEnter the data\n");
			scanf("%d", &data);
			nextItem->data = data;
			nextItem->next = NULL;
			temp->next = nextItem;
			temp = temp->next;

		}
	}


}


int getFrequency(int num) {
	struct node* temp;
	temp = head;
	int ctr = 0;
	while (temp != NULL) {
		if (temp->data == num) {
			ctr++;
		}
		temp = temp->next;
	}
	return(ctr);
}
void main() {
	printf("Enter how many numbers you want in the linked list:\n");
	int n;
	scanf("%d", &n);
	getData(n);
	//To calculate frequency
	printf("\nEnter the number whose frequency you wanna calculate:\n");
	int num;
	scanf("%d", &num);
	int frequency = getFrequency(num);
	printf("\nThe frequency is %d \n", frequency);
}