#include <stdio.h>
#include "book_management.h"
#include "users.h"
#include <string.h>
#include "check.h"
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

int check3(char *s,char *m){
    for (int j = 0; j < stunum; ++j) {
        if(strcmp(s,a[j].username)==0&&strcmp(m,a[j].password)==0){
            printf("username and password have existed!");
            return 1;
        }
    }
    return 0;
}

int check(char *i, char *o){

    for (int j = 0; j < stunum; ++j) {
        if(strcmp(i,a[j].username)==0&&strcmp(o,a[j].password)==0){
            printf("(login in as %s)",i);
            iflog = 2;
            return 1;
        }
    }
    return 0;
}

int  check2(char *i,char *o) {
    for (int j = 0; j < stunum; ++j) {
        if (strcmp(i, a[j].username) == 0 && strcmp(o, a[j].password) == 0) {
            printf("(login in as %s)", i);
            iflog = 2;
            current_num = j;
            return 1;
        }
    }
    printf("the information is wrong\n");
    return 0;
}

int check4(int d){
    for (int i = 0; i < xx; ++i) {
        if (b[i].id==d&&b[i].username==a[current_num].username){
            return 1;
        }
    }
    return 0;
}
