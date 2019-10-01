#include <stdio.h>

int i, j;

int Op2(int i)
{
    printf("Hello from 2\n");
    if (i > 1)
        Op2(i - 1);

    return 0;
}

int Op1(int i)
{
    printf("Hello from 1\n");
    if (i < 10)
        Op1(i + 1);
    else
    {
        Op2(i - 1);
    }

    return 0;
}


int main()
{
    Op1(10);
    return 0; 
}