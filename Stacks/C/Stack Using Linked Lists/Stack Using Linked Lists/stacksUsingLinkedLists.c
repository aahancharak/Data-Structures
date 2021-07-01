#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

#define SIZE 10
struct node {
	int data;
	struct node* next;
}*top;
int size = 0;

void push(int data) {
	if (size >= SIZE) {
		printf("\nStack overflow\n");
		return;
	}
	else {
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = top;
		top = newNode;
		size++;
		return;
	}

}

int pop() {
	if (size <= 0) {
		printf("\nSorry Stack UnderFlow");
		return;
	}
	else {
		struct node* topNode = top;
		top = top->next;
		int data = topNode->data;
		free(topNode);
		size--;
		return data;

	}

}

void main() {
	printf("\nWelcome to the stacks using linked lists implementation:\n");
	int choice;
	int data;
	while (1) {
		printf("\nEnter your choice\n");
		printf("\n1. Push  2. Pop 3. Size 4.Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter the number you want to push in the stack:\n");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			data = pop();
			if(data)
			printf("\n The number popped from the stack is %d", data);
			break;
		case 3:
			printf("\nThe size of the stack is %d", size);
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid choice please enter again\n");
		}
	}
}