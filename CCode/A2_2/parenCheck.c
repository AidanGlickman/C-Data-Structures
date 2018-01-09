#define STACK_SIZE 100
#define CHECK_SIZE 3
#include <stdio.h>
#include <stdlib.h>

char* stack[STACK_SIZE];
int sp=0;

char opening[3] = {'(', '[', '{'};
char closing[3] = {')', ']', '}'};

int lineCount = 1;
int charCount = 0;

char userIn;
char popped;

int errCheck;


/*
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs.  (Stack full).
 */
int push (char c){
	if(sp >= STACK_SIZE){
		return -1;
	}
	else{
		stack[sp++] = c;
		return 0;
	}
}

/*
 * Pops next character off the stack.
 * Returns the char if successful.
 * Returns -1 if an error occurs.  (Stack empty).
 */
int pop (){
	if(sp<=0){
		return -1;
	}
	else{
		return stack[--sp];
	}
}

/*
 * Returns the current size of the stack.
 */
int stackSize(){
	return sp;
}

int findIndex(char value)
{
    int index = 0;
	int size = CHECK_SIZE;

    while ( index < size && opening[index] != value ) ++index;

    return ( index == size ? -1 : index );
}

int main (){
	int i;
	int n;
	
	userIn = getchar();
	
	while(userIn != EOF){
		if(userIn == "\n"){
			lineCount += 1;
			charCount = 0;
		}
		else{
			charCount += 1;
			for(n=0; n<CHECK_SIZE; n++){
				if(userIn == opening[n]){
					errCheck = push(userIn);
					if(errCheck == -1){
						printf("Error: Stack Full!\n");
						return (0);
					}
					
				}
				else if(userIn== closing[n]){
					popped = pop();
					if(popped == -1){
						printf("Line %d, Char %d: Found %c. No matching character.\n", lineCount, charCount, userIn);
						return (0);
					}
					else if(popped != opening[n]){
						printf("Line %d, Char %d: Found %c, expected %c\n", lineCount, charCount, userIn, popped);
						return (0);
					}
				}
			}
		}
		userIn = getchar();
	}
	if(sp != 0){
		printf("Expecting %c, found end of input.\n", closing[findIndex(pop())]);
		return(0);
	}
	printf("Well formatted input.\n");
}	