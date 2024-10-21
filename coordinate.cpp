#include <coordinate.h>
#include <stdio.h>
#include <stdlib.h>

void add_coordinate(Coordinate *list_end, float x, float y){//add's a coordinate to the end of the linked list
  Coordinate a = {.coord_id = list_end->coord_id+1 ,.x = x, .y = y, .previous = list_end,.next = NULL};
  list_end->next = &a;
}

void forward_display(Coordinate *list_beginning){//displays all coordinates from beginning to end
  Coordinate p = *list_beginning;
  int cond = 1;
  while(cond){
    printf("%f %f\n", p.x, p.y);
    if(p.next != NULL){
      p = *p.next;
    }else{
      cond = 0;
    }
  }
}

