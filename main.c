#include <stdio.h>
#include <stdlib.h>
#include <coordinate.h>
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(NULL)); // randomize seed
    if(argc < 2){
        printf("No argument given\n");
        return 1;
    }
    int lenght = atoi(argv[1]);

    Coordinate start;
    start.x = abs(rand());
    start.y = abs(rand());
    start.coord_id = 0;
    start.previous = NULL;
    start.next = NULL;

    Coordinate *end = &start;

    for(int i = 1; i < lenght; i++) {
        const float x = abs(rand());
        const float y = abs(rand());
        add_coordinate(end,x,y);
        end = end->next;
    }
    int x = abs(rand());
    int y = abs(rand());

    closest_to(&start,x,y);

    return 0;
}
