#define STACK_SIZE 10
#include <stdio.h>
#include <math.h>
#include "stack.h"

double stack[STACK_SIZE];
int sp=0;

int push (double d){
	if(getStackSize() >= STACK_SIZE){
		return -1;
	}
	else{
		stack[sp++] = d;
		return 0;
	}
}

double pop(){
	if(sp<=0){
		return NAN;
	}
	else{
		return stack[--sp];
	}
}

int isStackEmpty(){
	if(sp == 0)
		return 1;
	return 0;
}

int getStackSize(){
	return sp;
}

void emptyStack(){
	sp = 0;
}

void printStack(){
	printf("Stack: ");
	int i;
	for(i = 0; i<sp; i++){
		printf("%f, ", stack[i]);
	}
	printf("\n");
}
