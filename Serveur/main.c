#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "init.h"
#include "listbook.h"
#include "listgenre.h"
#include "tree.h"

int main() {
    struct nodeAuthor * tree = createNodeAuthor();
    struct listGenre * genres = createListGenre();
    initBDD(tree, genres);
    FILE * request = NULL;
    printf("Scanning for request...\n");
    bool quit = false;
    while(!quit){
        request = fopen(REQUESTFILE, "r");
        if(request != NULL){
            printf("Request found !\n");
            quit = readRequest(tree, genres, request);
            if(!quit)
                printf("Scanning for request...\n");
            usleep((int)5E5);
            remove(REQUESTFILE);
        }else{
            usleep((int)1E5);
        }
    }
    freeBDD(tree, genres, request);
    return 0;
}