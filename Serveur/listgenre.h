#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "listbook.h"

#ifndef LISTGENRE_H
#define LISTGENRE_H

#define ALPHA_SIZE 30

struct listGenre{
    char* name;
    struct listGenre * next;
    struct listBook * books;
};

void insertGenre(struct listGenre* genres, struct book* book); //Insere un genre à une liste de genre
struct listGenre* createListGenre(); //Créer une liste de genre
struct listBook* findByGenre(char* genre, struct listGenre* chain); //Renvois une liste de books d'un genre

#endif
