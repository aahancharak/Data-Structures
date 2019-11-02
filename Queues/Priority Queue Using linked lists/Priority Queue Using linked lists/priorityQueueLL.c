#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996);

typedef struct node {
	int data;
	int priority;
	struct node* next;
}NODE;
NODE *front = NULL;
void Insert(int data, int prior);
int Delete();
void Display();
void main() {
	int data,prior, ch;
	printf("\n ------Welcome to the programme ---\n\n");
	while (1) {
		printf("\n----Enter your choice----\n");
		printf("\n 1> Enqueue\n");
		printf("\n 2>Dequeue\n");
		printf("\n 3>Display\n");
		printf("\n 3>Exit\n");
		printf("\n");
		scanf("%d", &ch);
		printf("\n");
		switch (ch) {
		case 1:
			printf("\nEnter the data you want to add in the  queue \n");
			printf("\n");
			scanf("%d", &data);
			printf("\n");
			printf("\nEnter the correspoding priority\n");
			scanf("%d", &prior);
			printf("\n");
			Insert(data, prior);
			break;

		case 2:
			printf("\nYou decided to dequeue\n");
			printf("\n");
			data = Dequeue();
			if (data) {
				printf("\n %d has been removed from the queue\n",data);
				printf("\n");
			}
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0);
		default:
			printf("\n Invalid choice please choose again\n");
			printf("\n");
		}
		  

	}
}
void Insert(int data, int prior) {
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->data = data;
	temp->priority = prior;
	if (front == NULL ||prior<front->priority) {
		temp->next = front;
		front = temp;
	}
	else {
		NODE *q;
		q = front;
		while (q->next != NULL && q->next->priority <= prior) 
			q = q->next;
		
		temp->next = q->next;
		q->next = temp;
	}
}

int Dequeue() {
	if (front == NULL) {
		printf("\n Sorry there is underflow cannot remove a node from empty queue buddy:\n");
		printf("\n");
		return 0;
	}
	else {
		NODE  *temp;
		temp = front;
		front = front->next;
		int data = temp->data;
		free(temp);
		return data;
       }
}

void Display() {
	if (front == NULL) {
		printf("\n Queue is empty\n");
	}
	else {
		NODE *temp = front;
		printf("\nYour queue is as follows :\n");
		printf("\n");
		while (temp != NULL) {
			printf("\n Data ->%d \t Priority -> %d", temp->data, temp->priority);
			temp = temp->next;
		}
	}
}