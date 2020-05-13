#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "listbook.h"

#ifndef TREE_H
#define TREE_H

#define ALPHA_SIZE 30

struct nodeAuthor{
    bool isAuthor;
    char letter;
    struct nodeAuthor* letters[ALPHA_SIZE];
    struct listBook* books;
};

void insertTree(struct nodeAuthor* author, struct book* aBook); //Insere un livre dans l'arbre des auteurs
struct listBook* findByAuthor(char* name, struct nodeAuthor* tree); //Renvois la liste des livres d'un auteur en parcourant l'arbre
struct listBook* findByName(char* name, struct nodeAuthor* arbre); //Renvois la liste des livres en fonction d'un nom
struct nodeAuthor* createNodeAuthor(); //Créer un noeud pour l'arbre d'auteur
struct listBook* getAllBooks(struct nodeAuthor* tree); //Renvois tout les livres de la BDD
void recursiviteAuthor(struct nodeAuthor* node, struct listBook* books, char* name); //Recursivite pour le parcours de l'arbre pour le findByAuthor
void recursiviteName(struct nodeAuthor* node, struct listBook* books, char* name);//Recursivite pour le parcours de l'arbre pour le findByName
void recursiviteAll(struct nodeAuthor* node, struct listBook* books); //Recursivite pour parcourir tout les livres dans l'arbre
bool strAreEquals(char* str1, char* str2); //return true si le un string est égale au début de l'autre
void endBDD(struct nodeAuthor* ptrAuthor, struct book* aBook); //Met fin au programme en vidant l'espace mémoire
int getCustomPos(char c); //Renvois une position spéciale pour les caractère spéciaux
int charToIndex(char c); //Renvois la position dans l'alphabet d'une lettre

#endif
