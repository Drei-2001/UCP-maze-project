#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    int nRows = 8, nCols = 10;
    int metaDataAmount = 10;
    int **metaDataTable;

    char**map;
    char move;

    int playerRow;
    int playerCol;
    int goalRow;
    int goalCol;

    getMetadata(&metaDataTable,&metaDataAmount,&nRows,&nCols);  /*return the right values */
    
    map = metaToMap(&nRows,&nCols,metaDataTable,metaDataAmount);
    findChar(map,nRows,nCols,'^',&playerRow,&playerCol);   /*get player position */
    findChar(map,nRows,nCols,'x',&goalRow,&goalCol);         /*get goal position */


    system("clear");
    disableBuffer();
    while(!((goalCol == playerCol) && (playerRow == goalRow)))
    {
            system("clear");

             /*printf("EndGoal is at row %d and column %d\n", goalRow,goalCol);
            printf("rows = %d\n",playerRow);
            printf("cols = %d\n",playerCol); */

            printMap(map,nRows,nCols);
            scanf("%c",&move);
            movePlayer(map,&playerRow,&playerCol,move,nRows,nCols); 
    }
    system("clear");
    printMap(map,nRows,nCols);
    enableBuffer();
    printf("Congratulations!\n");


    /*free */
    freeMap(map,nRows);
    freeMetaData(metaDataTable,metaDataAmount);
    return 0;
}



