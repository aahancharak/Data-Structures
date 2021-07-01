#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#pragma warning(disable :4996);

# define CAPACITY 5

//We will use the queue as the new struct node equivalent
typedef struct node {
	int data;
	struct node* next;
}Queue;

unsigned int size = 0;
int enqueue(Queue **rear,Queue **front,int data) {
	Queue *newNode = NULL;
	if (isFull()) {
		return 0;
	}
	else {
	newNode = (Queue *)malloc(sizeof(Queue));
	newNode->data = data;
	newNode->next = NULL;
	//If no rear exists
	if ((*rear)) {//Here *rear has the same use as that of rear coz in this function **rear is double pointer
		(*rear)->next = newNode;//prev rear points to the new node
		}

	//To make rear point to newNode
	
	(*rear) = newNode;

	//Link the first node to the front
	if (!(*front)) {
		*front = *rear;
	}

	size++;
	return 1;
	
	}

	
}

int dequeue(Queue **front) {
	int data;
	if (isEmpty()) {
		return INT_MIN;
	}
	else {
		//Create a temporary queue
		Queue* toDequeue = NULL;
		toDequeue = *front;
		data = toDequeue->data;
		//Move front ahead
		*front = (*front)->next;
		size--;
		free(toDequeue);
		return data;

	}
}

int isEmpty() {
	if (size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if (size >= CAPACITY) {
		return 1;
	}
	else {
		return 0;
	}
}


void main() {

	int ch, data;
	Queue  *rear, *front;
	rear = NULL;
	front = NULL;
	while (1) {
		printf("\n Welcome ,here are your choices \n");
		printf("\n 1->Enqueue \n");
		printf("\n 2->Dequeue \n");
		printf("\n 3->Get First \n");
		printf("\n 4->Get last \n");
		printf("\n 5->Size \n");
		printf("\n 6->exit \n");
		printf("\n\n Enter your choice \n");
		scanf("%d", &ch);
		printf("\n");
		switch (ch) {
		case 1:
			printf("\n Enter the data you want to enter in the queue \n");
			scanf("%d", &data);
			printf("\n");

			if (enqueue(&rear, &front, data)) {
				printf("\n The element has been added to the queue \n");
			}
			else {
				printf("\n Sorry the queue is full \n");
			}
			break;

		case 2:
			printf("\n Option is to remove the first element from the queue \n");
			data = dequeue(&front);
			if (data !=  INT_MIN) {
				printf("\n %d has been removed from the queue \n", data);
				printf("\n");
			}
			else {
				printf("\n The queue is already empty \n");
			}
			break;
		case 3:
			if (isEmpty()) {
				printf("\n Sorry the queue is empty \n");
				printf("\n");
			}
			else {
				printf("\n The first element is %d", front->data);
				printf("\n");
			}
			break;
		case 4:
			if (isEmpty()) {
				printf("\n Sorry the queue is empty \n");
				printf("\n");
			}
			else {
				printf("\n The required element is %d\n", rear->data);
				printf("\n");
			}
			break;
		case 5:
			if (isEmpty()) {
				printf("\n Sorry empty \n");
				printf("\n");
			}
			else {
				printf("\n The size is %d\n", size);
				printf("\n");
			}
			break;
		case 6:
			exit(0);


		}
	
	}
}