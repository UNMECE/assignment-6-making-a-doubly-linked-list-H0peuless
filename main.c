#include <stdio.h>
#include <stdlib.h>
#include <coordinate.h>
#include <time.h>

int main(int argc, char *argv[]){
    int lenght = 0;
    if(argc > 2) {
        lenght = atoi(argv[1]);
    }
    printf("%d\n", lenght);
}
