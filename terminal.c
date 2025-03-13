#include<stdio.h>
#include<termios.h>
#include"terminal.h"

void test20()
{
    char ch;

    printf("please enter one character below:\n");

    disableBuffer();
    scanf(" %c", &ch);
    enableBuffer();

    printf("the char you enter is %c\n", ch);

}

void disableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

void enableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}