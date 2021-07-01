#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>
#pragma warning(disable :4996);

# define SIZE 10
int queue[SIZE];
int front = 0;
int rear = SIZE - 1;
int size = 0;

bool isFull() {
	if (size >= SIZE) {
		return true;
	}
	else {
		return false;
	}
}
bool isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int enqueue(int data) {
	if (isFull()) {
		return 0;
	}
	else {
		rear = (rear + 1) % SIZE;
		queue[rear] = data;
		size++;
		return 1;
	}
}
int dequeue() {
	int data = INT_MIN;
	if (isEmpty()) {
		return data;
	}
	else {
		data = queue[front];
		front = (front + 1) % SIZE;
		size--;
		return data;
		 
	}
	

}

void main() {
	int ch, data;
	while (1) {
		printf("\nEnter to the queue application.What would you like to do?\n");
		printf("\n 1.Enqueue\n2.Dequeue\n3.Size\n4.Top\n5.Rear\n6.Exit");
		printf("\nPlease enter your choice \n");
		scanf("%d", &ch);
		
		switch (ch) {
		case 1:
			printf("\n Enter the data to enqueue \n");
			scanf("%d", &data);
			if (enqueue(data)) {
				printf("\n The data was added to the queue \n");
			}
			else {
				printf("\n Sorry but the queue is full\n");

			}
			break;
		case 2:
			printf("\nData is being removed");
			data = dequeue();
			if (data !=  INT_MIN) {
				printf("\n %d was removed from the queue\n", data);
			}
			else {
				printf("\nSorry cannot remove from an empty queue\n");
			}
			break;
		case 3:
			printf("\n Size is -> %d", size);
			break;
		case 4:
			if (isEmpty()) {
				printf("\n Queue is empty \n");
			}
			else {
				printf("\n%d\n", queue[front]);
			}
			break;
		case 5:
			if (isEmpty()) {
				printf("\n Queue is empty \n");
			}
			else {
				printf("\n%d\n", queue[rear]);
			}
			break;
		case 6:
			exit(0);
		default:
			printf("\n Please enter a value between 1 and 6 \n");

		}
		
	}
}