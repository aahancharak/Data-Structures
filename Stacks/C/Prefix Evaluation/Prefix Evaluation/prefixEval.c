#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable:4996);

# define SIZE 100
# define PREFIXSIZE 100
 
int stack[SIZE];
int top = -1;

void push(int ele) {
	if (top >= SIZE - 1) {
		printf("\nSorry stack overflow cannot continue the operations\n");
	}
	else {
		stack[++top] = ele;
	}
}
int pop() {
	int data;
	if (top < 0) {
		printf("\nSorry there is an stack underflow cannot continue the operations\n");
	}
	else{
		data = stack[top--];
		return data;

	}
}

void evalPrefix(char prefixExp[]) {
	int A, B;
	char cur;
	int val;
	for (int i = 0; prefixExp[i] != ')'; i++) {
		cur = prefixExp[i];
		if (isdigit(cur)) {
			push(cur-'0');
		}
		else if (cur == '+' || cur == '-' || cur == '/' || cur == '*') {
			A = pop();
			B = pop();
			switch (cur) {
			case '+':
				val = A + B;
				break;
			case '-':
				val = A - B;
				break;
			case '*':
				val = A * B;
				break;
			case '/':
				val = A / B;
			default:
				printf("\nInvalid operand\n");
				exit(0);
			}
			push(val);
		}
	}
	printf("\nThe value of the prefix expression is %d\n", pop());
}

void main() {
	char prefixExp[PREFIXSIZE];
	printf("\nEnter the data of the prefix expression\n");
	fgets(prefixExp, PREFIXSIZE, stdin);
	strrev(prefixExp);
	strcat(prefixExp, ")");
	evalPrefix(prefixExp);
}