#include <stdio.h>
#include <stdlib.h>
#include <coordinate.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(NULL)); // randomize seed
    if(argc < 2){
        printf("No argument given\n");
        return 1;
    }
    int lenght = atoi(argv[1]);

    Coordinate start;
    start.x = fabs(rand()/100);
    start.y = fabs(rand()/100);
    start.coord_id = 0;
    start.previous = NULL;
    start.next = NULL;

    Coordinate *end = &start;

    for(int i = 1; i < lenght; i++) {
        const double x = fabs(rand()/100);
        const double y = fabs(rand()/100);
        add_coordinate(end,x,y);
        end = end->next;
    }

    printf("Forward display\n----------------------\n");
    forward_display(&start);
    printf("Backward display\n----------------------\n");
    backward_display(end);
    printf("Length\n----------------------\n");
    printf("%d\n", list_length(&start));
    printf("Delete coordinate 6\n----------------------\n");
    delete_coordinate(&start,6); //use at least 7 element in your list
    printf("New lenght\n----------------------\n");
    printf("%d\n", list_length(&start));
    printf("Closest point to (x:500, y:230) \n----------------------\n");
    closest_to(&start,500,230);

    return 0;
}
