#include <coordinate.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add_coordinate(Coordinate *list_end, float x, float y){//add's a coordinate to the end of the linked list
  Coordinate *a = (Coordinate *)malloc(sizeof(Coordinate));
  list_end->next = a;
  a->coord_id = list_end->coord_id+1;
  a->x = x;
  a->y = y;
  a->previous = list_end;
  a->next = NULL;
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
  Coordinate *p = list_beginning;
  int passed = 0;
  int cond =1;
  while(cond){
    if(passed){
      p->coord_id = p->coord_id-1;
    }
    if(p->coord_id == coord_id_to_delete && passed==0){
      if (p->next != NULL){p->next->previous = p->previous ;}
      else p->next = NULL;

      if (p->previous != NULL){p->previous->next = p->next ;}
      else p->previous = NULL;

      passed = 1;
    }
    if(p->next != NULL) p = p->next;
    else{cond = 0;}
  }
  //free(p);
}

int list_length(Coordinate *list_beginning){//return the length of the list
  Coordinate *p = list_beginning;
  while(1){
    if(p->next != NULL) {
      p = p->next;
    }
    else return p->coord_id+1;
  }
}

void closest_to(Coordinate *list_beginning, float x, float y){//find the coordinate that is closest to the given x, y and output the distance between the 2
  int min = sqrt(list_beginning->x-x+list_beginning->y-y);
  Coordinate minC;
  Coordinate p = *list_beginning;

  for(int i = 0; i < list_length(list_beginning); i++){
    if( sqrt(p.x -x+ p.y-y) <= min){
      min = sqrt(p.x -x+ p.y-y);
      minC = p;
      }
      p = *p.next;
  }
  printf("The closest coordinate is frome point %i: dx=%f dy=%f\n", minC.coord_id, minC.x-x, minC.y-y);
}
