#define STACK_SIZE 100
#include <stdio.h>

char stack[STACK_SIZE];
int sp=0;


/*
 * Pushes character c onto the stack.
 * Returns 0 if successful.
 * Returns -1 if an error occurs.  (Stack full).
 */
int push (char c)
{
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
int pop ()
{
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
int stackSize()
{
	return sp;
}

/*
 * Tests if the stack is correctly implemented
 */
int main ()
{
  int i;
  int ch;
  int result;
  
  if (stackSize() == 0)
    printf ("Passed 1\n");
  else
    printf ("Failed 1\n");
  
  /* Make sure a pop of an empty stack returns -1.*/
  ch = pop();
  if (ch == -1)
    printf ("Passed 2\n");
  else
    printf ("Failed 2\n");
  
  push('A');
  push('B');
  
  ch = pop();
  if (ch == 'B')
    printf ("Passed 3\n");
  else
    printf ("Failed 3\n");
  
  push('C');
  push('D');
  push('E');
  
  if (stackSize() == 4)
    printf ("Passed 4\n");
  else
    printf ("Failed 4\n");
  
  if (pop() == 'E')
    printf ("Passed 5\n");
  else
    printf ("Failed 5\n");
  
  if (pop() == 'D')
    printf ("Passed 6\n");
  else
    printf ("Failed 6\n");
  
  if (pop() == 'C')
    printf ("Passed 7\n");
  else
    printf ("Failed 7\n");
  
  if (stackSize() == 1)
    printf ("Passed 8\n");
  else
    printf ("Failed 8\n");
  
  pop();
  
  for (i=0; i<STACK_SIZE; i++)
    result = push ('z');
  
  if (push('j') == -1)
    printf ("Passed 9\n");
  else
    printf ("Failed 9\n");
}