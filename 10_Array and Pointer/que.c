#include <stdio.h>

int main()
{
    int ar2[3][2] = 
    {
        {1,2},
        {3,4},
        {5,6}
    };

    int (*pa)[2]; // int type의 인덱스를 "2개 가지고 있는 배열" 을 가리키는 포인터. 하나의 포인터라고 생각하면된다.
    
    pa =ar2;

    printf("%p \n", pa); 
    printf("%p \n", pa+1); 

    return 0;

}