#include <stdio.h>
#include <string.h>

int main(){
  char str2[16];
  char str1[16];
  int i;

  for(i=0; i<16; i++){
    str1[i] = '?';
    str2[i] = '\0';
  }
  
  printf("Please Enter a String my liege.");
  gets(str1);
  i=0;
  printf("\n\nstr1: len=%d\n", strlen(str1));
  printf("%s\n", str1);

  prin tf("\n\nstr1: len=%d\n", strlen(str1));
  printf("%s\n", str1);

  printf("   i addr:                   %x %u\n", &i, &i);
  printf("   str1 addr:                %x %u\n", str1, str1);
  printf("   i addr:                   %x %u\n", &str1[2], &i);
  printf("   str2 addr:                %x %u\n", &str1[16], str2);
}
