#include <stdio.h>
#include <stdlib.h>
#include "table.h"

char **getMap(int rows, int cols) /*get map*/
{
    int h,i,j;
    /*create map*/
    char **map;
    map = (char **)malloc(sizeof(char *) * (rows));
    for(h = 0; h < rows;h++)
    {
        map[h] = (char*)malloc(sizeof(char)*(cols));
    }
    for(i = 0; i <rows; i++)
    {
        for(j = 0; j <cols;j++) /*if pointer is at top or bottom border,*/
        {
            if(i ==0|| i ==rows-1)
            {
                if(j ==0 || j == cols -1) /* if pointer is at edge AND at corner*/
                {
                    map[i][j] = '#';
                }
                else 
                {
                    map[i][j] = '-';
                }
            }
            else 
            {
                if( j ==0 || j ==  cols -1) /* if pointer is at edge ONLY*/
                {
                    map[i][j] = '|';
                }

                else /* CENTRES PLAYABLE AREA */
                {
                    map[i][j] = ' '; /*temporary space. will be filled with objects later*/
                }
            }
        } 
    }
    return map;
}

void printMap (char **map, int rows, int cols)
{
    int i,j;
    for (i = 0; i < rows;i++)
    {
        for (j = 0 ;  j < cols; j++)
        {
            if (j == cols -1) 
            {
                printf("%c\n",map[i][j]);
            }
            else 
            {
                printf("%c",map[i][j]);
            }
        }   
    }
}

void freeMap(char **map, int rows)
{
    int i;
    for(i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
}


char** metaToMap(int *rows, int *cols, int **metaDataTable, int metaDataAmount)
{
    int x,y;

    /*counters*/
    int player = 0,goal = 0, wall = 0;
    char**map;
    
    map = (char**)getMap(*rows,*cols);

    for (x= 0; x < metaDataAmount; x++)
    {
        int *rptr,*cptr;
        int nRows,nCols;

        rptr = &nRows;
        cptr = &nCols;

        for(y= 0; y <3;y++)
        {
            
            if (y ==0)
            {
                *rptr = metaDataTable[x][y];
            }
            else if (y == 1)
            {
                    *cptr = metaDataTable[x][y];
            }
            else if ( y ==2)
            {
                if (metaDataTable[x][y] == 0)
                {
                    map[nRows][nCols] = '^';
                    player++;
                    /*printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]); */

                }
                else if (metaDataTable[x][y] == 1)
                {
                    map[nRows][nCols] = 'x';
                    goal++;
                    /*printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]); */
                }
                else if (metaDataTable[x][y] == 2)
                {
                    map[nRows][nCols] = 'o';
                    wall++;
                    /*printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]); */
                
                }
                else 
                {
                    printf("problem with loop as meta is %d\n", metaDataTable[x][y]);
                }
            }
        }
    }
     /*printf("number of players: %d\n",player);
    printf("number of goals = %d\n",goal);
    printf("number of walls = %d\n",wall); */
    return map;
}
void freeMetaData(int **arr ,int metaDataAmount)
{
    int i;
    for(i = 0; i < metaDataAmount;i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void printMetaDataTable(int metaDataAmount,int ***metaDataTable)
{
    int i,j;
    for (i = 0; i >metaDataAmount; i++)
    {
        for (j = 0; j >=3;j++)
        {
            printf("%d,", *metaDataTable[i][j]);
        }
        
    }
}
