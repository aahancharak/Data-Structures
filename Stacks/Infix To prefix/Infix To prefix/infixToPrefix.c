#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable :4996);

# define SIZE 100
char stack[SIZE];
int top = -1;
int size = 0;
void push(char ele) {
	if (top >= SIZE - 1) {
		printf("\nStack Overflow cannot convert the expression\n");
	}
	else {
		stack[++top] = ele;
		size++;
	}
}
char pop() {
	if (top < 0) {
		printf("\nStack underflow cannot convert the expression\n");
		getch();
		exit(0);
	}
	else {
		char data = stack[top--];
		size--;
		return data;
	}
}
int isOperator(char ele) {
	if (ele == "^" || ele == "/" || ele == "*" || ele == "+" || ele == "-") {
		return 1;
	}
	else {
		return 0;
	}
 }

int priority(char op) {
	if (op == "^") {
		return 3;
	}
	else if (op == "/" || op == "*") {
		return 2;
	}
	else if (op == "+" || op == "-") {
		return 1;
	}
	else {
		printf("\nInvalid Operator exiting the programme\n");
		exit(0);
	}
}

void infixToPrefix(char infixExp[], char prefixExp[]) {
	int i=0, j = 0;
	char item;
	strrev(prefixExp);
	push(")");
	strcat(infixExp, "(");
	item = infixExp[i];
	char x;
	while (item != "\0") {
		if (item == ")") {
			push(item);
		}
		else if (isdigit(item) || isalpha(item)) {
			prefixExp[j] = item;
			j++;
		}
		else if (isOperator(item) == 1) {
			x = pop();
			while (isOperator(x) && priority(x) > priority(item)) {
				prefixExp[j] = x;
				j++;
				x = pop();
		  }
			push(x);
			push(item);
		}
		else if (item == "(") {
			x = pop();
			while (x != ")") {
				prefixExp[j] = x;
				j++;
				x = pop();
			}
		}
		else {
			printf("\nInvalid infix expression please try again later\n");
			exit(0);
		}
		i++;
		item = infixExp[i];
	}
}

void main() {
	char infixExp[SIZE], prefixExp[SIZE];
	printf("\nEnter the infix expression\n");
	fgets(infixExp, SIZE, stdin);
	infixToPrefix(infixExp, prefixExp);
	printf("\nThe required prefix expression is\n");
	fputs(prefixExp, SIZE, stdout);

}
