#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996);

struct node {
	int data;
	struct node* next;
}*head;

void getData(int n) {
	struct node* nextItem, * temp;
	int data;
	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		printf("Couldnt initialize memory.\n");
	}
	else {
		printf("\nEnter data\n");
		scanf("%d", &data);
		head->data = data;
		head->next = NULL;
		temp = head;
		for (int i = 1; i < n; i++) {
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

void reverse() {
	struct node* prev, * curr;

	prev = head;
	curr = head->next;
	head = head->next;
	prev->next = NULL;

	while (head != NULL) {
		head = head->next;
		curr->next = prev;
		prev = curr;
		curr = head;
	}
	head = prev;





}

void display() {
	printf("\nThe reverse of the linked lists is as follows:\n");
	struct node* temp;
	temp = head;
	while (temp != NULL) {
		printf("\nData: %d\n", temp->data);
		temp = temp->next;
	}
}
void main() {

	int n;
	printf("\nEnter how many numbers you want in the list\n");
	scanf("%d", &n);
	getData(n);
	//To reverse the list
	reverse();

	//To print the reverse list
	display();

}