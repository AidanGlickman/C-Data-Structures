int main(){
  int a=14, *b, c[4], *d, **e;

  d = malloc(sizeof(int)*5);
  b = c;

  b[2] = 7;

  b = &a;

  *b = 19;

  printf("%d" ,*b);

  e = &b;

  **e = 45;

  printf("%d", **e);
}
