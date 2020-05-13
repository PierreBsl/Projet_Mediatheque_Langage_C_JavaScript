#include "tree.h"

void insertTree(struct nodeAuthor* ptrAuthor, struct book* aBook) {

    int lenght = strlen(aBook->author);
    for (int i = 0; i < lenght; i++) {
        char c = aBook->author[i];
        int position = charToIndex(c);
        if(position < 0 || position > ALPHA_SIZE)
            position = getCustomPos(c);
        if(ptrAuthor->letters[position] == NULL){
            ptrAuthor->letters[position] = createNodeAuthor();
            ptrAuthor->letters[position]->letter = c;
        }
        ptrAuthor = ptrAuthor->letters[position];
    }
    ptrAuthor->isAuthor = true;
    ptrAuthor->books = addBookInList(ptrAuthor->books, aBook);
}

int getCustomPos(char c){
    if(c == ' '){
        return 26;
    }else if(c == '\''){
        return 27;
    }else if(c == '-'){
        return 28;
    }
}
struct listBook* findByAuthor(char* name, struct nodeAuthor* tree){
    struct listBook* books = createEmptyListBook();
    recursiviteAuthor(tree, books, name);
    if(books->book == NULL){
        printf("None book found with the author %s\n", name);
    }
    return books;
}
struct listBook* getAllBooks(struct nodeAuthor* tree){
    struct listBook* books = createEmptyListBook();
    recursiviteAll(tree, books);
    return books;
}
struct listBook* findByName(char* name, struct nodeAuthor* tree){
    struct listBook* books = createEmptyListBook();
    recursiviteName(tree, books, name);
    if(books->book == NULL){
        printf("None book found with the name %s\n", name);
    }
    return books;
}
struct nodeAuthor* createNodeAuthor() {
    struct nodeAuthor* ptrAuthor = (struct nodeAuthor*) malloc(sizeof(struct nodeAuthor));
    for (int i = 0; i < ALPHA_SIZE; i++) {
        ptrAuthor->letters[i]=NULL;
    }
    ptrAuthor->isAuthor = false;
    return ptrAuthor;
}


void recursiviteAuthor(struct nodeAuthor* node, struct listBook* books, char* name){
    if(node == NULL)
        return;
    for(int i = 0; i < ALPHA_SIZE; i++){
        struct nodeAuthor* next = node->letters[i];
        if(next != NULL){
            recursiviteAuthor(next, books, name);
        }
    }
    if(node->isAuthor){
        struct listBook* aBooks = node->books;
        while(aBooks != NULL){
            if(strAreEquals(name, aBooks->book->author)){
                addBookInList(books, aBooks->book);
            }
            aBooks = aBooks->next;
        }
    }
}
void recursiviteName(struct nodeAuthor* node, struct listBook* books, char* name){
    if(node == NULL)
        return;
    for(int i = 0; i < ALPHA_SIZE; i++){
        struct nodeAuthor* next = node->letters[i];
        if(next != NULL){
            recursiviteName(next, books, name);
        }
    }
    if(node->isAuthor){
        struct listBook* aBooks = node->books;
        while(aBooks != NULL){
            if(strAreEquals(name, aBooks->book->name)){
                addBookInList(books, aBooks->book);
            }
            aBooks = aBooks->next;
        }
    }
}
void recursiviteAll(struct nodeAuthor* node, struct listBook* books){
    if(node == NULL)
        return;
    for(int i = 0; i < ALPHA_SIZE; i++){
        struct nodeAuthor* next = node->letters[i];
        if(next != NULL){
            recursiviteAll(next, books);
        }
    }
    if(node->isAuthor){
        struct listBook* aBooks = node->books;
        while(aBooks != NULL){
            addBookInList(books, aBooks->book);
            aBooks = aBooks->next;
        }
    }
}
bool strAreEquals(char* str1, char* str2){
    int lenght1 = strlen(str1);
    int lenght2 = strlen(str2);
    if(lenght1 > lenght2)
        return false;
    for(int i = 0; i < lenght1; i++){
        char c1 = str1[i];
        char c2 = str2[i];
        if(tolower(c1) != tolower(c2)){
            return false;
        }
    }
    return true;
}
int charToIndex(char c){
    if((int)c <= 90)
        c+= 32;
    return ((int)(c - 'a'));
}
