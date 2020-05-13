#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#ifndef LISTBOOK_H
#define LISTBOOK_H

#define ALPHA_SIZE 30

struct book{
    char* name;
    char* author;
    char* genre;
    int pages;
};

struct listBook{
    struct book* book;
    struct listBook * next;
};

struct book* stringToBook(char * str, int start); //Renvois un book en fonction d'un ligne du type auteur;nomLivre;pages;genre
struct book* createEmptyBook(); //Créer un book empty
struct listBook* createEmptyListBook(); //Créer une list vide de books
struct listBook* addBookInList(struct listBook* head, struct book* aBook); //Ajouter un livre à une liste

#endif
