#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include <string.h>
record b[100];

extern Student a[100];
extern int stunum;
extern int iflog;
extern int current_num;
extern int nn;
extern int numbers;
extern int hu;
extern int h;
extern BookList *theLibrary;
extern Book *end;
extern int id;
int xx;

int load_books(FILE *file) {
    if ((file = fopen("books.txt", "rt")) == NULL) {
        printf("Error\nBook file does not exist: %s\n", file);
        return 0;
    }else{
        theLibrary->length=0;
        end=theLibrary->list;
        char b[100];
        int tit[128];
        int aut[128];
        Book *p;
        while( fgets(b,128, file) != NULL ) {
            numbers++;
            if((numbers)%5==1){
                p= (Book*) malloc(sizeof(Book));
                p -> next = NULL;
                sscanf(b,"%d\n",&p->id);
            }
            if((numbers)%5==2){
                strcpy(aut, b);
                p->title= (char*)malloc(sizeof (aut));
                strcpy(p->title, b);
                p->title[strlen(p->title) - 1] = '\0';

            }
            if((numbers)%5==3){
                strcpy(tit, b);
                p->authors= (char*)malloc(sizeof (tit));
                strcpy(p->authors, b);
                p->authors[strlen(p->authors) - 1] = '\0';
            }
            if((numbers)%5==4){
                sscanf(b,"%d\n",&p->year);
            }
            if((numbers)%5==0){
                sscanf(b,"%d\n",&p->copies);
                end->next=p;
                end=p;

            }
        }


    }
    theLibrary->length=end->id;
    fclose(file);
}
BookList find_book_by_year(unsigned int year){
    printf("%s\t", "ID");
    printf("%s\t\t\t\t\t\t", "Title");
    printf("%s\t\t\t", "Authors");
    printf("%s      ", "year");
    printf("%s\n", "copies");
    Book *q = theLibrary->list;
    int x=0;
    while (q!=NULL){
        if (q->year==year){
            printf(" %-7d",q->id);
            printf("%-48s",q->title);
            printf("%-24s",q->authors);
            printf("%-10d",q->year);
            printf("%-10d\n",q->copies);
            q = q->next;
            x++;
        } else{
            q = q->next;
        }
    }

}
BookList find_book_by_author (const char *author){
    printf("%s\t", "ID");
    printf(" %s\t\t\t\t\t\t", "Title");
    printf("%s\t\t\t", "Authors");
    printf("%s      ", "year");
    printf("%s\n", "copies");
    Book *q = theLibrary->list->next;
    int x=0;
    while (q!=NULL){
        if (strcmp(q->authors,author)==0){
            printf(" %-8d",q->id);
            printf("%-47s",q->title);
            printf("%-24s",q->authors);
            printf("%-10d",q->year);
            printf("%-10d\n",q->copies);
            q = q->next;
            x++;
        } else{
            q = q->next;
        }
    }
}
BookList find_book_by_title (const char *title){
    printf("%s\t", "ID");
    printf(" %s\t\t\t\t\t\t", "Title");
    printf("%s\t\t\t", "Authors");
    printf("%s      ", "year");
    printf("%s\n", "copies");
    Book *q = theLibrary->list->next;
    int x=0;
    while (q!=NULL){
        if (strcmp(q->title,title)==0){
            q->title[strlen(q->title) - 1] = '\0';
            printf("%-9d",q->id);
            printf("%-47s",q->title);
            printf("%-24s",q->authors);
            printf("%-10d",q->year);
            printf("%-10d\n",q->copies);
            q = q->next;
            x++;
        } else{
            q = q->next;
        }
    }
}
int store_books(FILE *file){
    FILE *fp;
    fp = fopen(file, "w+");
    if (!fp) {
        fprintf(stderr, "Failed in opening %s\n", file);
        return -1;
    }
    end = theLibrary->list ->next;
    while (end!= NULL) {
        fprintf(fp,"%d\n",end->id);
        fprintf(fp,"%s\n",end->title);
        fprintf(fp,"%s\n",end->authors);
        fprintf(fp,"%d\n",end->year);
        fprintf(fp,"%d\n",end->copies);
        end=end->next;
    }
    fclose(fp);
    return 0;
}
int add_book(Book book){
    Book *temp = theLibrary->list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Book* s = (Book *)malloc(10000);
    s->title= (char*)malloc(100);
    s->authors= (char*)malloc(100);
    s->id=book.id;
    s->year=book.year;
    s->next = NULL;
    strcpy(s->title,book.title);
    strcpy(s->authors,book.authors);
    s->copies=book.copies;
    temp->next=s;
    return 0;
}
void removes(){
    printf("Enter the id of the book you wish to remove:");
    scanf("%d",&h);
    fflush(stdin);
    Book* temp = theLibrary->list -> next;
    int a=0;
    while (temp!=NULL){
        if(temp -> id > a) a = temp->id;
        temp=temp->next;
    }
//    printf("%d",temp->id);
    if(h>a){
        printf("no this book\n");
        return;
    }
    Book s;
    s.id = h;
    int cd=remove_book(s);
    if (cd==0){
        printf("remove successfully\n");
    }
}
int remove_book(Book book){
    Book *new= (Book *)malloc(10000);
    Book *s=theLibrary->list->next;
    while (s!=NULL&&book.id !=s->id)
    {
        new=s;
        s=s->next;
    }

    if(s->id == book.id)
    {
        if(s == theLibrary->list->next)
        {
            theLibrary->list->next = theLibrary->list->next->next;
        }
        else
        {
            new->next = s->next;
        }
    }
    else
    {
        printf("error\n");
        return -1;
    }
//    s=NULL;
    return 0;
}
void year(){
    printf("Please enter year:");
    int year = 0;
    scanf("%d",&year);
    fflush(stdin);
    find_book_by_year ( year);

}
void author(){
    printf("Please enter author:");
    char* author;
    int aut[100];
    author= (char*)malloc(sizeof (aut));
    getchar();
    scanf("%[^\n]",author);
    find_book_by_author (author);

}

void title(){
    printf("Please enter title:");
    char* title;
    int tit[100];
    title= (char*)malloc(sizeof (tit));
    getchar();
    scanf("%[^\n]",title);
    find_book_by_title (title);
}

void add(){
    theLibrary->length=0;
    Book *s=theLibrary->list;
    while(s != NULL)
    {
        theLibrary->length++;
        s = s->next;
    }
    Book *new= (Book *)malloc(10000);
    new->title= (char*)malloc(100);
    new->authors= (char*)malloc(100);
    Book* temp = theLibrary->list -> next;
    while (temp!=NULL){
        if(temp -> id > id) id = temp->id;
        temp=temp->next;
    }
    char tit[100];
    char aut[100];
    new->id=id + 1;
    printf("Enter the title of the book you wish to add:");
    getchar();
    scanf("%[^\n]",tit);
    if (strlen(tit)>20){
        printf("too long\n");
        return;
    }
    strcpy(new->title,tit);
    getchar();
    printf("Enter the author of the book you wish to add:");
    scanf("%[^\n]",aut);
    if (strlen(aut)>20){
        printf("too long\n");
        return;
    }
    strcpy(new->authors,aut);
    printf("Enter the year of the book:");
    scanf("%d",&new->year);
    fflush(stdin);
    if(new->year<=2022 && new ->year > 0){
        printf("Enter the number of copies of the book that you wish to add:");
        scanf("%d",&new->copies);
        fflush(stdin);
        if (new->copies > 0 &&new->copies<10000) {
            Book book;
            book.title= (char*)malloc(100);
            book.authors= (char*)malloc(100);
            book.id=new->id;
            book.next = NULL;
            strcpy(book.title,new->title);
            strcpy(book.authors,new->authors);
            book.year=new->year;
            book.copies=new->copies;
            int ab = add_book(book);
            if (ab==0){
                printf("add successfully!\n");
                return;
            }
        }
        else{
            printf("Sorry, you attemped to add an invalid book, pelase try it again\n");
            return;
        }
    } else{
        printf("Sorry, you attemped to add an invalid book, pelase try it again\n");
        return;
    }


}

void printbooks(){
    printf("%s\t ", "ID");
    printf("%s\t\t\t\t\t\t ", "Title");
    printf("%s\t\t\t    ", "Authors");
    printf("%s      ", "year");
    printf("%s\n", "copies");
    end = theLibrary->list ->next;
    while (end!= NULL) {
        printf(" %-8d",end->id);
        printf("%-48s",end->title);
        printf("%-35s",end->authors);
        printf("%-10d",end->year);
        printf("%-10d\n",end->copies);
        end=end->next;
    }
}
void Display(){
    printbooks();
}
