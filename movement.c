#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

void findChar(char **map, int rows,int cols, char ch,int *charRow,int *charPos)
{
    int i,j;
    int found = 0;
    /*int charPos[2]; */

    for(i = 0; i <rows;i++)
    {
        for(j = 0;j < cols;j++)
        {
            if (map[i][j] == ch)
            {
                *charRow = i;
                *charPos = j;
                found ++;
            }
            
        }
    }
}


void movePlayer(char **map,int *currRow,int *currCol,char move,int totalRow, int totalCol)
{
    switch (move)
    {
        case 'w':   /*move row UP*/
                if (map[*currRow-1][*currCol] == 'o' || map[*currRow-1][*currCol] == '-' || map[*currRow-1][*currCol] == '|')
                {
                    /* wall hit,change direction */
                    map[*currRow][*currCol] = '^';
                }
                else {
                    map[*currRow -1][*currCol] = '^';
                    map[*currRow][*currCol] = ' ';
                    *currRow = *currRow - 1;
                }
                
            break; 
        case 'a':   /*move col LEFT*/
                if (map[*currRow][*currCol -1] == 'o' || map[*currRow][*currCol -1] == '-' || map[*currRow][*currCol -1] == '|')
                {
                    /* wall hit,change direction */
                    map[*currRow][*currCol] = '<';

                }
                else {
                    map[*currRow][*currCol -1] = '<';
                    map[*currRow][*currCol] = ' ';
                    *currCol = *currCol - 1;
                }
            break;
        case 's':   /*move row DOWN*/
                if (map[*currRow +1][*currCol] == 'o' || map[*currRow +1][*currCol] == '-' || map[*currRow +1][*currCol] == '|')

                {
                    /* wall hit,change direction */
                    map[*currRow][*currCol] = 'v';
                }
                else {
                    map[*currRow +1][*currCol] = 'v';
                    map[*currRow][*currCol] = ' ';
                    *currRow = *currRow + 1;
                }
            break;
        case 'd':   /*move col RIGHT*/
                if (map[*currRow][*currCol +1] == 'o' || map[*currRow][*currCol +1] == '-' || map[*currRow][*currCol +1] == '|')
                {
                    /* wall hit,change direction */
                    map[*currRow][*currCol] = '>';

                }
                else {
                    map[*currRow][*currCol +1] = '>';
                    map[*currRow][*currCol] = ' ';
                    *currCol = *currCol + 1;
                }
            break;
    }
}

