#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include "users.h"
#include <string.h>

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
int store_users(FILE *file){
    FILE *fp;
    fp = fopen(file, "w+");
    if (!fp) {
        fprintf(stderr, "Failed in opening %s\n", file);
        return -1;
    }
    for (int i = 0; i < stunum; ++i) {
        fprintf(fp, "%s\n",a[i].username);
        fprintf(fp, "%s\n",a[i].password);
    }
    fclose(fp);
    return 0;
}
void load_users(FILE *fp){
    char use[100];
    char pass[100];
    char s[100];
    if ((fp = fopen("users.txt", "rt")) == NULL){
        printf("error!!!");
        return ;
    }
    while (fgets(s, 128, fp) != NULL) {
        s[strlen(s) - 1] = '\0';
        if (nn % 2 == 0) {
            strcpy(use,s);
            a[stunum].username=(char*) malloc(sizeof(use)) ;
            strcpy(a[stunum].username, s);
        } else {
            strcpy(pass,s);
            a[stunum].password=(char*) malloc(sizeof(pass)) ;
            strcpy(a[stunum].password, s);
            stunum++;
        }
        nn++;
    }
}





