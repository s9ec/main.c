#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "check.h"
#include "borrow_return.h"
#include "first.h"
#include "enroll_login.h"
#define RECORD_FILE "users.txt"
#define RECORD_FILE2 "books.txt"

Student a[100];
record b[100];
int stunum = 0;
int iflog = 0;
int current_num = 0;
int nn =0;
int numbers=0;
int hu;
int h=0;
BookList *theLibrary;
Book *end;
int id = 0;
int xx;

char *ask_question(const char *question) {
    printf("%s",question);
}
void menu4(){
    while (1) {
        char *answer = ask_question(
                "\nPlease choose an option:\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) log out\nchoice: ");
        char choice[100];
        scanf(" %s", choice);
        if (strlen(choice)==1&&choice[0]=='1') {
            add();
            printf("(login in as librarian)");
        } else if (strlen(choice)==1&&choice[0]=='2') {
            removes();
            printf("(login in as librarian)");
        } else if (strlen(choice)==1&&choice[0]=='3') {
            menu3();
            printf("(login in as librarian)");
        } else if (strlen(choice)==1&&choice[0]=='4') {
            Display();
            printf("(login in as librarian)");
        }
        else if (strlen(choice)==1&&choice[0]=='5') {
            return;
        }else {
            printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }
}
void menu3() {
    while (1) {
        char *answer = ask_question(
                "\nPlease choose an option:\n1) Find books by title\n2) Find books by author\n3) Find books by year\n4) Return to previous menu\nchoice: ");
        char choice[100];
        scanf(" %s", choice);
        if (strlen(choice)==1&&choice[0]=='1') {
            title();
        } else if (strlen(choice)==1&&choice[0]=='2') {
            author();
        } else if (strlen(choice)==1&&choice[0]=='3') {
            year();
        } else if (strlen(choice)==1&&choice[0]=='4') {
            return;
        } else {
            printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }
}
void remenu(){
    load_borrowed();
    while(1){

        char * answer = ask_question("\nPlease choose an option:\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\nchoice: ");
        char choice[100];
        scanf(" %s",choice);
        if(strlen(choice)==1&&choice[0]=='1'){
            borrow();
        }
        else if(strlen(choice)==1&&choice[0]=='2'){
            huan();
        }
        else if(strlen(choice)==1&&choice[0]=='3'){
            menu3();
            if(iflog == 2)
                check(a[current_num].username,a[current_num].password );
        }
        else if(strlen(choice)==1&&choice[0]=='4'){
            Display();
            if(iflog == 2)
                check(a[current_num].username,a[current_num].password );
        }
        else if(strlen(choice)==1&&choice[0]=='5'){
            printf("Logging out...\n");
            iflog = 0;
            loan_users2();
            return ;
        }
        else{
            printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }

}
void main_menu() {

    while(1){

        char * answer = ask_question("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\nchoice: ");
        char choice[100];
        scanf("%s",choice);
        if(strlen(choice)==1&&choice[0]=='1'){
            enroll();
        }
        else if(strlen(choice)==1&&choice[0]=='2'){
            int k = login();
            if(k == 1)
                remenu();
        }
        else  if(strlen(choice)==1&&choice[0]=='3'){
            menu3();
            if(iflog == 2)
                check(a[current_num].username,a[current_num].password );
        }

        else  if(strlen(choice)==1&&choice[0]=='4'){
            Display();
            if(iflog == 2)
                check(a[current_num].username,a[current_num].password );
        }
        else if(strlen(choice)==1&&choice[0]=='5'){
            printf("Goodbye!");
            iflog = 0;
            return ;
        }
        else{
            printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }
    return;
}
void interface() {
//    Book S;
//    int a = 5;
//    int = 5
//    BookList  bookList;
//    bookList.list = (Book*) malloc(sizeof(Book));
//    bookList.list->id
    theLibrary = (BookList *)malloc( sizeof(BookList) );
    theLibrary->list=(Book*) malloc(sizeof(Book));
    theLibrary->list ->next = NULL;
    FILE *fp ;
    load_books(fp);
    main_menu();
    return;
}
int main()
{
    load_users(RECORD_FILE);
    interface();
    store_users(RECORD_FILE);
    store_books(RECORD_FILE2);
    return 0;
}