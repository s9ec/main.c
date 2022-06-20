#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "check.h"
#include "borrow_return.h"
#include "first.h"
#define RECORD_FILE "users.txt"
#define RECORD_FILE2 "books.txt"
#include "enroll_login.h"
extern Student a[100];
extern int stunum;
extern int iflog;
extern int current_num;
extern int nn ;
extern int numbers;
extern int h;
extern int hu;
extern BookList *theLibrary;
extern Book *end;
extern int id;
record b[100];
int xx;


void enroll() {

    char s[30],m[30];
    printf("Please enter a username:");
    scanf("%s",s);
    printf("please enter a password:");
    scanf("%s",m);
    char use[100];
    char pass[100];
    int w=check3(s,m);
    if (w==1){
        return;
    } else{
        strcpy(use,s);
        a[stunum].username=(char*) malloc(sizeof(use)) ;
        strcpy(pass,m);
        a[stunum].password=(char*) malloc(sizeof(pass)) ;
        strcpy(a[stunum].username,s);
        strcpy(a[stunum].password,m);
        stunum ++;
        printf("Registered library account successfully");
    }

}



int login() {
    if (stunum==0){
        printf("please register first");
        return 0;
    }
    char i[30];
    char o[30];
    printf("Please enter your username:");
    scanf("%s",i);
    printf("please enter your password:");
    scanf("%s",o);
    if (strcmp(i,"librarian")==0&& strcmp(o,"librarian")==0){
        printf("(login in as %s)", i);
//        iflog = 2;
        menu4();
        return 2;
    }
    int k = check2(i,o);
    if(k == 1){
        return 1;
    }
    return 0;
}


