#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/time.h>
#include "listbook.h"
#include "tree.h"
#include "listgenre.h"

#ifndef INIT_H
#define INIT_H
#define RESULTFILE "../../Client/results.txt"
#define READYFILE "../../Client/ready.txt"
#define REQUESTFILE "../../Communication/request.txt"
#define MAX_STRING 250
#define ALPHA_SIZE 30

void initBDD(struct nodeAuthor* tree, struct listGenre* genres); //Initialise la bdd
bool readRequest(struct nodeAuthor* tree, struct listGenre* genres, FILE* request); //lis la requete request.txt, renvois true si l'utilisateur demande la fin du programme
void freeBooks(struct listBook* books); //Libère la mémoire de livres
void freeBDD(struct nodeAuthor* tree, struct listGenre* genres, FILE* request); //Libère la mémoire de la base de donnée
void freeTree(struct nodeAuthor* node); //Libère la mémoire de l'arbre
void writeResult(struct listBook* books, double time); //Créer le result.txt et ready.txt

#endif
