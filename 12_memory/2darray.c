#include<stdio.h>

int main()
{
        int ar2[10000][3] =
        {1, };

        int (*pa)[3];

        pa = ar2;

        printf("%p\n", pa); // 0xfffff824dcd0
        printf("%p\n", pa+1); // 0xfffff824dcdc
        
        
        printf("%d\n", **(pa)); // 0xfffff824dcdc
        printf("%d\n", **(pa+1)); // 0xfffff824dcdc
        printf("%d\n", **(pa+99)); // 0xfffff824dcdc
        printf("%d\n", **(pa+999)); // 0xfffff824dcdc



        return 0;
}