#include <coordinate.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add_coordinate(Coordinate *list_end, float x, float y){//add a coordinate to the end of the linked list
  Coordinate *a = (Coordinate *)malloc(sizeof(Coordinate));
  list_end->next = a;
  a->coord_id = list_end->coord_id+1;
  a->x = x;
  a->y = y;
  a->previous = list_end;
  a->next = NULL;
}

void forward_display(const Coordinate *list_beginning){//displays all coordinates from beginning to end
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

void backward_display(const Coordinate *list_end){//displays all coordinates from end to beginning
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
  double min = sqrt(pow(list_beginning->x-x,2)+pow(list_beginning->y-y,2));
  Coordinate minC = *list_beginning;
  Coordinate *p = list_beginning;

  for(int i = 1; i < list_length(list_beginning); i++){
    const double norm = sqrt(pow(p->x -x,2) + pow(p->y-y,2));
    if( norm <= min){
      min = norm;
      minC = *p;
      }
      p = p->next;
  }
  printf("The closest point id is %d: dx=%f dy=%f\n", minC.coord_id, fabs(minC.x-x), fabs(minC.y-y));
}
