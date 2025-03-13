#include <stdio.h>
#include <stdlib.h>
#include "test.h"

/*https://stackoverflow.com/questions/32289187/what-is-the-purpose-of-a-triple-pointer-for-2d-array*/


void test()
{
    int nRows = 8, nCols = 10;
    int metaDataAmount = 10;
    int **metaDataTable;
    int *playerLoc = (int*)malloc(sizeof(int)*2);
    int i;

    char**map;

    getMetadata(&metaDataTable,&metaDataAmount,&nRows,&nCols);  /*return the right values */
    
    map = metaToMap(&nRows,&nCols,metaDataTable,metaDataAmount);
    printMap(map,nRows,nCols);
    printf("map = %c\n",map[6][3]);
    printf("mapRow = %d\n",nRows);
    printf("metadataAmount = %d\n",metaDataAmount);


    
    /*free */
    free(playerLoc);
    freeMap(map,nRows);
    freeMetaData(metaDataTable,metaDataAmount);
}




