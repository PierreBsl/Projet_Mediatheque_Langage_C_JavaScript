#include "listgenre.h"
#include "tree.h"
void insertGenre(struct listGenre* genres, struct book* book){
    if(!strcasecmp(genres->name, "")){ //Si la liste des genres est vide
        genres->name = malloc(sizeof(char)* strlen(book->genre));
        strcpy(genres->name, book->genre);
        genres->books = addBookInList(genres->books, book);
        return;
    }
    while(genres != NULL){
        if(!strcasecmp(genres->name, book->genre)){ //Si le genre du livre correspond au genre pointé
            genres->books = addBookInList(genres->books, book);
            return;
        }
        if(genres->next == NULL){ //Si on arrive à la fin de la liste
            genres->next = createListGenre();
            genres->next->name = malloc(sizeof(char)* strlen(book->genre));
            strcpy(genres->next->name, book->genre);
            genres->next->books = addBookInList(genres->next->books, book);
            return;
        }
        genres = genres->next;
    }
}


struct listGenre* createListGenre(){
    struct listGenre* ptrGenre = malloc(sizeof(struct listGenre));
    ptrGenre->name = "";
    ptrGenre->next = NULL;
    ptrGenre->books = NULL;
    return ptrGenre;
}
struct listBook* findByGenre(char* genre, struct listGenre* chain){
    while(chain != NULL){
        if(strAreEquals(genre, chain->name)){
            return chain->books;
        }
        chain = chain->next;
    }
    printf("None book found with the %s genre has been found\n", genre);
    return NULL;
}
