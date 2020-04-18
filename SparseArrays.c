#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

int* matchingStrings(int str, char* strings[], int qry, char* query[]);

int main(){

    int str,qry, len,count=0;
    char tmp[MAXLINE];
    char *strings[MAXLINE];
    char *query[MAXLINE];

    scanf("%d", &str);
    for(int i=0;i<str;i++){
        scanf("%s", tmp);
        len=strlen(tmp)+1;
        strings[i]=(char *)malloc(sizeof(char)*len);
        strcpy(strings[i], tmp);
    }
    scanf("%d", &qry);
    for(int i=0;i<qry;i++){
        scanf("%s", tmp);
        len=strlen(tmp)+1;
        query[i]=(char *)malloc(sizeof(char)*len);
        strcpy(query[i], tmp);
    }

    int *result=matchingStrings(str, strings, qry, query);

    for(int j=0;j<qry;j++){
        printf("%d\n",*(result+j));
    }
    return 0;
}

int* matchingStrings(int str, char* strings[], int qry, char* query[]) {

    int correct, m=0;
    int *result;

    result=(int*)malloc(qry*sizeof(int));
    
    for(int i=0;i<qry;i++){
        correct=0;
        for(int j=0;j<str;j++){
            if(!strcmp(query[i], strings[j]))
                correct++;
        }
        *(result+i)=correct;
    }
    return result;

}
