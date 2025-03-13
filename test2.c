


void metaToMap(int rows, int cols, int **metaDataTable, int metaDataAmount)
{
    int x,y;

    /*counters*/
    int player = 0,goal = 0, wall = 0;
    char**map;
    
    getMetadata(&metaDataTable, &metaDataAmount,&rows,&cols);   /*metaDataTable will be defined in the main function*/
    map = (char**)getMap(rows,cols,metaDataTable,metaDataAmount);

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
                    printf("%c",map[nRows][nCols]);
                    printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]);

                }
                else if (metaDataTable[x][y] == 1)
                {
                    map[nRows][nCols] = 'x';
                    goal++;
                    printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]);
                }
                else if (metaDataTable[x][y] == 2)
                {
                    map[nRows][nCols] = 'o';
                    wall++;
                    printf("row = %d, col = %d , char = %c\n",nRows,nCols,map[nRows][nCols]);
                
                }
                else 
                {
                    printf("problem with loop as meta is %d\n", metaDataTable[x][y]);
                }
            }
        }
    }
    printf("number of players: %d",player);
    printf("number of goals = %d",goal);
    printf("number of walls = %d",wall);


}
