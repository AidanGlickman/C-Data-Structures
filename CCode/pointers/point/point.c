#include <stdio.h>
#include <stdlib.h>
#include "point.h"

struct point{
  float x;
  float y;
};

Point* createPoint(float x, float y){
  Point *p = malloc(sizeof(Point));

  p->x = x;
  p->y = y;

  return p;
}

void translatePoint(Point *p, float dx, float dy){
  p->x += dx;
  p->y += dy;
}

void dilatePoint(Point *p, float factor){

}
