/* Exercise 1-24. Write a program to check a C program for rudimentary 
   syntax errors like unmatched parentheses, brackets and braces. Don't 
   forget about quotes, both single and double, escape sequences, and 
   comments. (This program is hard if you do it in full generality.) */

/* Algorithm -
   1. if a open parenthesis '{' is detected look increment parenthesis count by 1, do the same for bracket and braces
   2. decrement count by one if found a closing parenthesis, bracket or braces.
   3. keep a stack kind of structure to push when open bracket/brace/parenthesis occurs and pop when closing bracket/braces/
 	  parenthesis occur, the stack data structure will keep the order of brackets/braces and parenthesis in check
   4. Do the same for double quotes and single quotes
   5. */

void push(int c);
void pop(void);
int peek(void);
void bracket_check(int c, int close_b, int open_b);

#include <stdio.h>

main() {
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '{')
			push(c);
		else if (c == '[')
			push(c);
		else if (c == '(')
			push(c);
		bracket_check(c, '}', '{');
		bracket_check(c, ']', '[');
		bracket_check(c, ')', '(');
	}
}

void bracket_check(int c, int close_b, int open_b) {
	int tos; //top of stack
	if (c == close_b) {
		if ((tos = peek()) != open_b)
			printf("Mismatched %c%c\n",open_b, close_b);
		else
			pop();
	}
}

#define STACK_SIZE	100
static int stackBuff[STACK_SIZE];
static int stackptr = -1;

void push(int c) {
	if (stackptr < STACK_SIZE)
		stackBuff[++stackptr] = c;
	else
		printf("push: failed, stack full\n");
}

void pop(void) {
	if (stackptr >= 0)
		stackptr--;
	else
		printf("pop: failed, stack empty\n");
}

int peek(void) {
	if (stackptr >= 0)
		return stackBuff[stackptr];
	else
		printf("peek: failed, stack empty\n");
}

