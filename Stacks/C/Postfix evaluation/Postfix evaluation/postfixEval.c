#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable :4996);

# define SIZE 100
# define POSTFIXSIZE 100

int stack[SIZE];
int top = -1;

void push(int ele) {
	if (top >= SIZE - 1) {
		printf("\nSorry there is stack underflow cannot proceed further\n");
	}
	else {
		stack[++top] = ele;
	}
}
int pop() {
	int data;
	if (top < 0) {
		printf("\nUnderflow cannot proceed further\n");
		exit(0);
	}
	else {
		data = stack[top--];
		return data;

	}
}

void evalPostFix(char postFixExp[]) {
	int A, B;
	char cur;
	int val;
	for (int i = 0; postFixExp[i] != ')'; i++) {
		cur = postFixExp[i];
		if (isdigit(cur)) {
			push(cur-'0');
		}
		else if (cur == '+' || cur == '-' || cur == '*' || cur == '/') {
			A = pop();
			B = pop();
			switch (cur) {
			case '+':
				val = B + A;
				break;
			case '-':
				val = B - A;
				break;
			case '/':
				val = B / A;
				break;
			case'*':
				val = B * A;
				break;
			default:
				printf("\nInvalid Operand present exiting\n");
				exit(0);

			}
			push(val);
		}

	}
	printf("\nThe result of the postfix expression is %d\n", pop());

}

void main() {
	char postFixExp[POSTFIXSIZE];
	printf("\nEnter the postfix expression\n");
	fgets(postFixExp, POSTFIXSIZE, stdin);
	strcat(postFixExp,")");
	evalPostFix(postFixExp);
}