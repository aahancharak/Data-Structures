#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable :4996);

# define MAX 5
int front = -1;
int rear = -1;
int pri_queue[MAX];
int priority[MAX];

void checkData(int data, int pri) {
	int i, j;
	if (priority[rear] <= pri) {
		rear++;
		priority[rear] = pri;
		pri_queue[rear] = data;
		return;
	}
	else if (rear == 0 && priority[rear] < pri) {
		priority[rear + 1] = priority[rear];
		pri_queue[rear + 1] = pri_queue[rear];
		rear++;
		priority[0] = pri;
		pri_queue[0] = data;
		return;
	}
	else {
		for (i = rear - 1; i >= 0; i--) {
			if (priority[i] <= pri) {
				for (j = rear; j >= i + 1; j--) {
					priority[j + 1] = priority[j];
					pri_queue[j + 1] = pri_queue[i];

				}
				rear++;
				priority[i + 1] = pri;
				pri_queue[i + 1] = data;
				return;
			}
		}
	}

}
void insert(int data, int pri) {
	if ((rear + 1) % MAX == 0 && rear!=-1) {
		printf("\nSorry there is stack overflow cannot insert any more elements\n");
		return;
	}
	else if (front == -1 && rear == -1) {
		front++;
		rear++;
		pri_queue[rear] = data;
		priority[rear] = pri;
		return;
	}
	else {
		checkData(data, pri);
	}

}


int delete() {
	if (front < 0) {
		printf("\n Sorry the queue is empty \n");
	}
	else {
		if ((front + 1) % MAX == 0 || front == rear) {
			int data = pri_queue[front];
			front = -1;
			rear = -1;
			return data;

		}
		else {
			int data = pri_queue[front];
			front++;
			return data;

		}
	}
}

void main() {
	printf("\n----------Welcome to the programme ----------\n");
	int ch, data, pri;
	while (1) {
		printf("\n--Here are the operations what would you like to do --");
		printf("\n 1. Insert 2. Delete  3.Exit\n");
		scanf("%d", &ch);
		printf("\n");
		switch (ch) {
		case 1:
			printf("\n Enter the data you want to insert in the priority queue :\n");
			scanf("%d", &data);
			printf("\n Enter the priority of the data you just entered \n");
			scanf("%d", &pri);
			insert(data, pri);
			break;
		case 2:
			data = delete();
			printf("\n %d was deleted from the queue\n", data);
			break;
		case 3:
			exit(0);
		default:
			printf("\n Invalid choice please enter again \n");
		}
	}
}

