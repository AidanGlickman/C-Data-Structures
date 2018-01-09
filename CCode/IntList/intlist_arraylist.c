#include "intlist.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct intlist{
  int* list;
  int arraySize;
  int listSize;
};

typedef struct intlist IntList;

IntList* ilCreate(){
  IntList* created = malloc(sizeof(IntList));

  created->arraySize = 5;
  created->listSize = 0;

  created->list = malloc(sizeof(int)*created->arraySize);
  return created;
}

IntList* ilCopy (IntList *il){
  IntList* copied = ilCreate();

  copied->arraySize = il->arraySize;
  copied->listSize = il->listSize;

  copied->list = malloc(sizeof(int)*copied->arraySize);

  int i;
  for(i=0;i<il->listSize;i++){
    copied->list[i] = il->list[i];
  }

  return copied;
}

void ilExpand (IntList *il){
  int* newarr = malloc(sizeof(int)*(il->arraySize+5));
  int i;
  for(i=0; i<il->listSize; i++){
    newarr[i] = il->list[i];
  }
  il->arraySize += 5;
  il->list = newarr;
}

void ilAppend (IntList *il, int val){
  if(il->listSize >= il->arraySize){
    ilExpand(il);
  }
  il->list[il->listSize++] = val;
}

void ilPrint(IntList* il) {
  int i;
  for(i=0; i<il->listSize; i++){
    int n = il->list[i];
    printf("%d ", n);
  }
  printf("\n");
}

int ilDelete (IntList *il, int pos){
  if(pos>il->listSize || pos<0){
    return -1;
  }
  int i;
  for(i = pos+1; i<il->listSize; i++){
    il->list[i-1] = il->list[i];
  }
  il->listSize--;
  return 0;
}

int ilFind (IntList *il, int val){
  int i;
  for(i=0; i<il->listSize; i++){
    if(il->list[i] == val){
      return i;
    }
  }
  return -1;
}

int ilInsert (IntList *il, int pos, int val){
  int i;
  if(pos>=il->listSize || pos<0){
    return INT_MIN;
  }
  if(il->listSize>=il->arraySize){
    ilExpand(il);
  }
  for(i=il->listSize;i>pos;i--){
    il->list[i]=il->list[i-1];
  }
  il->list[pos]=val;
  il->listSize++;
    return 0;
}

int ilSize(IntList *il){
  return il->listSize;
}

int ilGet (IntList *il, int pos){
  if(pos>=il->listSize || pos<0){
return INT_MIN;
}
return il->list[pos];
}
