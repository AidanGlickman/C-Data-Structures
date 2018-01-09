#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main(){
  int reading = -1;
  int charCount = 0;
  int pushed;
  double param1, param2;
  char current;
  current = getchar();

  while(current != EOF){
    charCount++;
    if(isdigit(current)){
      if(reading == -1){
        reading = current - '0';
      }
      else{
        reading *= 10;
        reading += current - '0';
      }
    }

    else{
      if(isspace(current)){
        if(reading >= 0){
          pushed = push(reading);
          if(pushed == -1){
            printf("ERROR: Stack full when pushing (%d) at position %d.\n", reading, charCount);
            return -1;
          }
          reading = -1;
        }
      }

      else{
        if(getStackSize()<2){
          printf("ERROR: Input error at character %d (%c); too few arguments on stack.\n", charCount, current);
          return -1;
        }
        else{
          param2 = pop();
          param1 = pop();
          if(current == '+'){
            push(param1+param2);
          }
          else if(current == '-'){
            push(param1-param2);
          }
          else if(current == '*'){
            push(param1*param2);
          }
          else if(curerent == '/'){
            push(param1/param2);
          }
        }
      }
    }
    current = getchar();
  }
  if(getStackSize()>1){
    printf("ERROR: Too Many Values, Not Enough Operators.\n");
    return -1;
  }
  else{
    printf("RESULT: %.2f\n", pop());
    return 0;
  }
}
