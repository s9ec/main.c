#include <stdio.h>
#include "book_management.h"
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "check.h"
#include "borrow_return.h"
extern Student a[100];
extern record b[100];
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
int xx;
void load_borrowed(){
    char g[100] ;
//    strcpy(g,a[current_num].username);
//    const char * filename = strcat(g,".txt");
    FILE *fp ;
    char s[100];
    if ((fp = fopen("record.txt", "rt")) == NULL) {
        printf("Error\nBook file does not exist: %s\n", fp);
        return ;}

    while (fgets(s, 128, fp) != NULL) {
//        printf("ddqef");
        strcpy(g,s);
        b[xx].username=(char*) malloc(sizeof(g));
        sscanf(s,"%s %d\n",b[xx].username, &b[xx].id);
        xx++;
    }

}


void borrow(){
    printf("Enter the ID number of the book you wish to borrow:");
    int id;
    scanf("%d",&id);
    fflush(stdin);
    if (id>theLibrary->length||id<=0){
        printf("no this book");
        return;
    }
//    Book *p=theLibrary->list->next;
    int sx =check4(id);
    if (sx==1){
        printf("Sorry, you already have a copy of this book on loan");
        return;
    } else {
        b[xx].id= id;
        Book *x = theLibrary->list->next;
//        int nCount = 1;
        while (x) {
//            printf("%d %d\n",a[current_num].id[a[current_num].booknum],nCount);
            if (b[xx].id == x->id) {
                if (x->copies>0){
                    b[xx].username=a[current_num].username;
                    x->copies--;
                    printf("borrow successfully");
                    xx++;
                    return;
                } else{
                    printf("the copies are 0, no this book");
                    b[xx].id = 0;
                    return;
                }


                }


            else {
                x = x->next;

            }
        }

    }
}
void loan_users2(){
    FILE *fp;
    fp = fopen("record.txt", "w+");
    if (!fp) {
        fprintf(stderr, "Failed in opening %s\n", fp);
        return ;
    }
    for (int i = 0; i < xx; ++i) {
        fprintf(fp, "%s %d\n",b[i].username,b[i].id);
    }
    fclose(fp);

}

int returnbooks(int hu) {
    int x = 0;
    int m=0;
    for (int i = 0; i < xx; ++i) {
        if (hu == b[i].id&&strcmp(a[current_num].username,b[i].username)==0) {
            x = i;
            m++;
        }
    }
    if (m==0){
        return 0;
    }
    while (x < xx) {
        b[x].id = b[x+1].id;
        b[x].username=b[x+1].username;
        x++;
    }
    xx--;
    return 1;
}
void huan(){
//    int temp=0;
//    for(int k=0;k<xx-1;k++)
//    {
//        for(int j=1;j<xx-k;j++)
//        {
//            if(b[j].id<b[j-1].id&&strcmp(b[j].username,b[j-1].username)==0)
//            {
//                temp=b[j-1].id;
//                b[j-1].id=b[j].id;
//                b[j].id=temp;
//            }
//        }
//    }
    printf("Below is the list of Books you are currently borrowing:\n");
    printf("%s\t", "ID");
    printf("%s\t\t\t\t\t\t", "Title");
    printf("%s\t\t\t\t   ", "Authors");
    printf("%s  \n", "year");
    Book *q = theLibrary->list ->next;
    int sx=0;
    while (q!=NULL)
    {
        printf("%d\n",b[sx].id);
        printf("%s\n",b[sx].username);
        printf("%d\n",q->id);
        printf("%s\n",a[current_num].username);
        if (b[sx].id == q->id&& strcmp(a[current_num].username,b[sx].username)==0)
        {
//            printf("%d\n",b[sx].id);
//            printf("%d\n",q->id);
//            printf("%s\n",a[current_num].username);
//            printf("%s\n",b[sx].username);
            printf("%-8d",q->id);
            printf("%-48s",q->title);
            printf("%-35s",q->authors);
            printf("%-10d\n",q->year);
            q->copies++;
            sx++;
        }
        else
        {
            sx++;
            q = q->next;
        }
    }
    printf("Enter the ID number of the book you wish to return:");
    scanf("%d",&hu);
    fflush(stdin);
    int sw= returnbooks(hu);
    if (sw==1){
        printf("Returned book successfully!");
        return;
    } else{
        printf("failure!!!");
        return;
    }

}
