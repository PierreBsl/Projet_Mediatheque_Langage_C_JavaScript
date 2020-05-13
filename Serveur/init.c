#include "init.h"

void initBDD(struct nodeAuthor * tree, struct listGenre* genres){
    FILE * file = fopen("mediathequeBD.txt", "r");
    char line[MAX_STRING];
    tree->letter = '$'; //On met un dollar sur la racine de l'arbre
    printf("Data base is beeing initialized.. \n");
    struct timeval  tv1, tv2; //Pour le calcul du temps d'initialisation
    gettimeofday(&tv1, NULL);
    if(file != NULL){
        while(fgets(line, MAX_STRING, file) != NULL){
            struct book * booktemp = stringToBook(line, 0);
            struct book * booktemp2 = stringToBook(line, 0);//Tout les livres de la mediatheque passent par là
            if(booktemp != NULL){
                insertTree(tree, booktemp);
                insertGenre(genres, booktemp2);
            }
        }
    }else{
        printf("Error when loading the library.");
    }
    gettimeofday(&tv2, NULL);
    double time = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
    printf("Data base initialized in %f seconds\n", time);
}

bool readRequest(struct nodeAuthor* tree, struct listGenre* genres, FILE* request){
    remove(RESULTFILE);
    remove(READYFILE); //Suppression des file result.txt et ready.txt
    char line[MAX_STRING];
    fgets(line, MAX_STRING, request);
    char linecpy[MAX_STRING];
    strcpy(linecpy, line); //Copie de la ligne dans une autre variable car strtok modifie le str
    char *str = strtok(linecpy, ";"); //Premier string de la ligne
    struct listBook* books = createEmptyListBook();
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);
    if(str == NULL){
        printf("Invalid request ! \n");
        return false;
    }else if(!strcmp(str, "insert")){
        struct book * bookT = stringToBook(line, 1);
        struct book * bookT2 = stringToBook(line, 1);
        insertTree(tree, bookT);
        insertGenre(genres, bookT2);
        if(bookT != NULL)
            printf("Book %s by %s (%d pages, %s genre) inserted\n", bookT->name, bookT->author, bookT->pages, bookT->genre);
        free(books);
        return false;
    }else if(!strcmp(str, "findByAuthor")){
        str = strtok(NULL, ";");
        books = findByAuthor(str, tree);
    }else if(!strcmp(str, "findByName")){
        str = strtok(NULL, ";");
        books = findByName(str, tree);
    }else if(!strcmp(str, "findByGenre")) {
        str = strtok(NULL, ";");
        books = findByGenre(str, genres);
    }else if(!strcmp(str, "getAll")){
        books = getAllBooks(tree);
    }else if(!strcmp(str, "end")){
        printf("End of the programm !\n");
        free(books);
        return true;
    }else{
        printf("Invalid request ! \n");
        free(books);
        return false;
    }


    gettimeofday(&tv2, NULL);
    double time = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
    writeResult(books, time);
    free(books);
    return false;
}

void freeBDD(struct nodeAuthor* tree, struct listGenre* genres, FILE* request){
    while(genres != NULL){
        free(genres->name);
        freeBooks(genres->books);
        struct listGenre* tmp = genres->next;
        free(genres);
        genres = tmp;
    }
    freeTree(tree);
}

void freeTree(struct nodeAuthor* node){
    if(node == NULL)
        return;
    for(int i = 0; i < ALPHA_SIZE; i++){
        struct nodeAuthor* next = node->letters[i];
        if(next != NULL){
            freeTree(next);
        }
    }
    freeBooks(node->books);
    //free(node);
    node->letter = '\0';
}

void freeBooks(struct listBook* books){
    if(books == NULL)
        return;
    freeBooks(books->next);
    free(books->book->name);
    free(books->book->genre);
    free(books->book->author);
    books->book->pages = 0;
    free(books->book);
    free(books);

}

void writeResult(struct listBook* booksT, double time) {

    FILE* resultFile = fopen(RESULTFILE, "a");

    fprintf(resultFile,"%f", time);
    struct listBook* booksT2 = booksT;
    if(booksT != NULL && booksT->book != NULL && booksT->next != NULL){
        fputs("\r\n", resultFile); //Retour à la ligne si la liste des livres n'est pas vide
    }
    int i = 0;
    while(booksT != NULL && booksT->book != NULL && booksT->next != NULL){
        fputs(booksT->book->author, resultFile);
        fputs(";", resultFile);

        fputs(booksT->book->name, resultFile);
        fputs(";", resultFile);

        fprintf(resultFile,"%d", booksT->book->pages);
        fputs(";", resultFile);

        fputs(booksT->book->genre, resultFile);
        booksT = booksT->next;
        if(booksT->next != NULL) {
            fputs("\r\n", resultFile);
        }
        i ++;
    }
    if(booksT2 != NULL && booksT2->book != NULL)
        printf("Number of books found : %d\n", i);
    fclose(resultFile);
    FILE* readyFile = fopen(READYFILE, "a");
    fclose(readyFile);
    printf("Search done in %f seconds\n", time);
    free(booksT);
}