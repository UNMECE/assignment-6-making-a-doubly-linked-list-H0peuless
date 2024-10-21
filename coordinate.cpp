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

void backward_display(Coordinate *list_end){//displays all coordinates from end to beginning
  Coordinate p = *list_end;
  int cond = 1;
  while(cond){
    printf("%f %f\n", p.x, p.y);
    if(p.previous != NULL){
      p = *p.previous;
    }else{
      cond = 0;
    }
  }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete){//removes a coordinate from the linked list (free memory!)
  Coordinate p = *list_beginning;
  int passed = 0;
  int cond =1;
  while(cond){
    if(passed){
      p.coord_id--;
    }
    if(p.coord_id == coord_id_to_delete && passed==0){
      p.next->previous = p.previous ;
      p.previous->next = p.next ;
      free(p.previous);
      free(p.next);
      passed = 1;
    }
    if(p.next != NULL) p = *p.next;
  }
}