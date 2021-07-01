#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable :4996);

# define SIZE 100
char stack[SIZE];
int top = -1;

void push(char item) {
	if (top >= SIZE - 1) {
		printf("\nStack Overflow\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

char pop() {
	if (top < 0) {
		printf("\nSorry Stack underflow,the stack is empty cannot pop\n");
		return;
	}
	else {
		char data = stack[top--];
		return data;
	}
}

int isOperator(char symbol) {
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
		return 1;
	}
	else {
		return 0;
	}
}
int priority(char operator) {
	if (operator=='^') {
		return(3);
	}
	else if (operator =='/' || operator =='*') {
		return(2);
	}
	else if (operator=='+' || operator=='-') {
		return(1);
	}
	else
		return(0);
}
void  infixToPostfix(char infixExp[], char postfixExp[]) {
	int i = 0;
	int j = 0;
	char x;
	push('(');
	strcat(infixExp, ")");
	char item = infixExp[0];
	while (item != '/0') {
		if (item == '(') {
			push(item);
		}
		else if (isdigit(item) || isalpha(item)) {
			postfixExp[j] = item;
			j++;
		}
		else if (isOperator(item) == 1) {
			printf("%d", isOperator(item));
			x = pop();
			while (isOperator(x) == 1 && priority(x) >= priority(item)) {
				postfixExp[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if (item == ')') {
			x = pop();
			while (x != '(') {
				postfixExp[j] = x;
				j++;
				x = pop();
			}

		}
		else {
			printf("%c", item);
			printf("\nInvalid infix expression\n");
			getchar();
			exit(1);
		}
		i++;
		item = infixExp[i];
	}
	if (top < 0 ||top>=SIZE) {
		printf("\nInvalid infix expression");
 }
	postfixExp[j] = '/0';
}

int main() {
	char infix[SIZE], postFix[SIZE];
	printf("\nEnter the infix expression\n");
	fgets(infix, SIZE, stdin);
	infixToPostfix(infix, postFix);
	printf("\nThe postfix expression is \n");
	fputs(postFix, stdout);
	return 0;
}