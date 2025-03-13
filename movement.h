#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "map.h"
#define RESET(x,y,z,i) (x[y][z]=i)

void findChar(char **map, int rows,int cols, char ch,int *charRow,int *charPos);
void movePlayer(char **map,int *currRow,int *currCol,char move,int totalRow, int totalCol);

#endif