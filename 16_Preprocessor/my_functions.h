#pragma once

extern int status;
// 여러 함수에서 공통적인 변수를 사용하고 싶을 때 사용한다.
// 이 부분을 잘 숙지하지 못하면 나중에 linking error가 날 수 있다.

extern static int si = 0;
// static: file scope. "include한 파일"의 scope 내에서 사용할 수 있게 된다.

extern int add(int a, int b);

static int multiply(int a, int b){
    return a * b;
}

// int subtract(int a, int b)
inline int subtract(int a, int b)
{
    return a - b;
}

void print_status()
{
    printf("Address = %p, Value = %d\n", &status, status);
}

void print_address()
{
    printf("print_address() \n");
    printf("Static function address %p \n", multiply);
    printf("Static variable address %p \n", &si);

}