#include <coordinate.h>
#include <stdio.h>
#include <stdlib.h>

void add_coordinate(Coordinate *list_end, float x, float y){//add's a coordinate to the end of the linked list
  Coordinate *p = list_end;
  Coordinate a = {.x = x, .y = y, .previous = p};
  p->next = &a;
}

