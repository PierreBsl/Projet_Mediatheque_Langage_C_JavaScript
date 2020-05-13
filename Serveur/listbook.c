#include "listbook.h"

struct book* stringToBook(char * string, int start){
    if(!strcmp(string, "\r\n")){
        printf("/!\\Empty line\n");
        return NULL;
    }
    struct book* bookT = createEmptyBook();
    int index = 0;
    char* str = malloc(sizeof(char) * strlen(string) +1);
    str[strlen(string)] = '\0';
    strcpy(str, string);
    bool isComplete = false;
    char *split = strtok(str, ";"); //Split de la ligne par les ";"
    while(split != NULL){ //Loop pour chaque string entre ";"
        if(index >= start){ //Demarre au rang voulu
            switch(index - start){
                //met les valeurs dans le book
                case 0:
                    bookT->author = malloc(sizeof(char) * (strlen(split)+1));
                    strcpy(bookT->author, split);
                    break;
                case 1:
                    bookT->name = malloc(sizeof(char) * (strlen(split)+1));
                    strcpy(bookT->name, split);
                    break;
                case 2:
                    bookT->pages = atoi(split);
                    break;
                case 3:
                    bookT->genre = malloc(sizeof(char) * strlen(split) +1);
                    split = strtok(split, "\r\n");
                    strcpy(bookT->genre, split);
                    isComplete = true;
                    break;
                default:
                    break;
            }
        }
        split = strtok(NULL, ";");
        index ++;
    }
    free(str);
    if(!isComplete)
        bookT = NULL; //En cas de mauvaise saisie du livre dans le .txt
    return bookT;
}


struct book* createEmptyBook(){
    struct book* bookT = (struct book*)malloc(sizeof(struct book));
    bookT->pages = 0;
    return bookT;
}


struct listBook* createEmptyListBook(){
    struct listBook* new = (struct listBook*)malloc(sizeof(struct listBook));
    new->next = NULL;
    new->book = NULL;
    return new;

}

struct listBook* addBookInList(struct listBook* head, struct book* aBook) {
    if (head == NULL) {
        head = createEmptyListBook();
        head->book = aBook;
    }else{
        struct listBook* tmpHead = head;
        while(tmpHead != NULL){
            if(tmpHead->book == NULL || strcmp(tmpHead->book->name, aBook->name) > 0){
                struct book* tmp = tmpHead->book;
                struct listBook* tmp2 = tmpHead->next;
                tmpHead->book = aBook;
                tmpHead->next = createEmptyListBook();
                tmpHead->next->book = tmp;
                tmpHead->next->next = tmp2;
                break;
            }else if(tmpHead->next == NULL){
                tmpHead->next = createEmptyListBook();
                tmpHead->next->book = aBook;
                break;
            }
            tmpHead= tmpHead->next;
        }
    }
    return head;

}
