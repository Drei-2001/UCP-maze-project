#ifndef TABLE_H
#define TABLE_H


void printMap (char **, int , int );
char **getMap(int , int ); /*get map*/
char **metaToMap(int* , int* , int **, int );
void freeMap(char **, int );
void freeMetaData(int ** ,int);
void printMetaDataTable(int ,int ***);
#endif
