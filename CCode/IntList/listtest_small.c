#include <stdio.h>
#include <limits.h>
#include "intlist.h"

int main() {
  IntList *list1;

  list1 = ilCreate();

  ilAppend (list1, 14);
  ilAppend (list1, 35);
  ilAppend (list1, 3);

  ilPrint(list1);
}
