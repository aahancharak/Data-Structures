#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996);

#define  SIZE 100
int top = -1;
int stack[SIZE];

void push(int ele);
int pop();

void main() {
	int choice, data;
	while (1) {
		printf("\n------------------------------------\n");
		printf("\nEnter the stack operation choice:\n");
		printf("\n1 Push 2 Pop 3 Size 4 Exit\n");
		printf("\n-------------------------------------\n");
		scanf("%d", &choice);
		printf("\n\n");
		switch (choice) {
		case 1:
			printf("Enter the element you want to push in the stack :\n");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			printf("Popping the last element out of the stack\n");
			data = pop();
			printf("\nThe poped element is %d\n", data);
			break;
		case 3:
			printf("The current size of the stack is %d\n", top + 1);
			break;
		case 4:
			printf("Exiting out of the programme :\n");
			exit(0);
		default:
			printf("Invalid choice enter the choice again.\n");
		}
	}
}

void push(int ele) {
	if (top >= SIZE - 1) {
		printf("\nStack overflow\n");
	}
	else {
		stack[++top] = ele;
		return;
	}
}
int pop() {
	if (top < 0) {
		printf("\nStack underflow\n");
		return;

	}
	else {
		return stack[top--];
	}
}


