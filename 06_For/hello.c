#include <stdio.h>


int main()
{
    int i, j, num;

    printf("input a number:1~100\n");
    scanf("%d", &num);

    i =0;

    while (i<num)
    {

        for (j=0; j <=i; j++)
        {
            printf("*");
        }

        printf("\n");
        i++;

    }
    return 0;

}