//// 9-1 function

#define _CRT_NOSECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

/* #define WIDTH 40
#define NAME "ChangHyun Oh"
#define ADDRESS "CA, USA"

void print_chars(char c, int n_stars, bool endl)
{
    for (int i =0; i < n_stars; ++i)
        printf("%c",c);
    if (endl == true)
        printf("\n");

}

void print_centered_str(char str[])
{

    int n_blanks = 0;

    n_blanks = (WIDTH - strlen(str)) / 2; // 좌우에 들어갈 수 계산
    print_chars(' ', n_blanks, false); //빈칸 넣어주기

    printf("%s\n", str);
}

int main()
{
    print_chars('*', WIDTH, 1);

    print_centered_str(NAME);
    print_centered_str(ADDRESS);
    print_centered_str("nice to meet you!");

    print_chars('*', WIDTH, 0);

    return 0;
} */


//// 9-2. 프로토타입

//// 9-3. 함수 자료형

// int int_min(int, int);

// int main()
// {
//     int i1, i2;

//     while(1)
//     {
//         printf("Input two integers: ");

//         if(scanf("%d %d", &i1, &i2) != 2) break;

//         int lesser = int_min(i1, i2);
//         // int lesser = min;
//         printf("The lesser of %d and %d is %d \n", i1, i2, lesser);

//         //printf("The lesser of %d and %d is %d \n", i1, i2, int_min(i1, i2));
//     }
// }

// int int_min( int i, int j)
// {
//     return (i < j) ? i:j; // ternary operation
// }

////9-4. scope, variable

////9-5. stack

//// 9-6 Recursion
//// 9-7. stack

// void my_func(int);

// int main()
// {
//     my_func(1);
//     return 0;
// }

// void my_func(int n)
// {
//     printf("level %d, address of variable n = %d \n", n, (int)& n);

//     if (n<4)
//         my_func(n+1);

//     //Stop condition

//     //Tail recursion
//     printf("level %d, address of variable n = %d \n", n, (int)& n);

// }


//// 9-10 재귀호출

/* 
    loop vs recursion
    factorial : 3! = 3 2 1, 0! = 1
    5! = 5 * 4! = 5 * 4 * 3! = ... = 5*4*3*2*1*0!
*/

// long loop_factorial(int n);
// long recursive_factorial(int n);

// int main()
// {
//     int num = 3;

//     printf("%ld \n", loop_factorial(num));
//     printf("%ld \n", recursive_factorial(num));

//     return 0;
// }

// long loop_factorial(int n)
// {
//     long ans;

//     for (ans = 1; n > 1; n--)
//         ans *= n;

//     return ans; 
// }

// long recursive_factorial(int n)
// {

//     if (n > 0)
//     {
//         return n * recursive_factorial(n-1); // tail(end) recursion
//     }
//     else
//         return 1;
// }

//// 09-09. binary

// void print_binary(unsigned long n);
// void print_binary_loop(unsigned long n);

// int main()
// {
//     unsigned long num =10;

//     print_binary_loop(num);
//     print_binary(num);

//     printf("\n");

//     return 0;
// }

// // note: printing order is reversed!

// void print_binary_loop(unsigned long num)
// {
//     while(1)
//     {
//         int quotient = num/2;
//         int remainder = num %2;

//         printf("%d", remainder); //remainder is 0 or 1

//         num = quotient;
//         if (num ==0) break;
//     }
//     printf("\n");
// }

// void print_binary(unsigned long num)
// {

//     int remainder = num % 2;

//     if (num >=2)
//         print_binary(num/2);
//     printf("%d", remainder);
//     return;

// }

////09-10, 피보나치

// int fibonacci(int number);

// int main()
// {
//     for (int count = 1; count < 13; ++count)
//         printf("%d ", fibonacci(count));
//     return 0;
// }

// int fibonacci(int number)
// {
//     if (number > 2)
//         return fibonacci(number -1) + fibonacci(number -2);
//     else
//         return 1;
// }
// //note: memery (in)efficiency, redundant computation

//// 09-11 헤더파일
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// void print_hello()
// {
//     printf("hello \n");
//     //many more lines
// }

// void print_hi()
// {
//     printf("Hi \n");

// }

// void print_str(char* str)
// {
//     printf("%s\n", str);
// }

// int main()
// {
//     print_hello();
//     print_hi();

//     print_hello();
//     print_hi();

//     print_str("No one lives forever.");
//     print_str("Valar morghulis");

//     return 0;
// }

////09-12. Pointer
////09-13. pointer

/* int main()
{
    int a, b;

    a=123;

    int *a_ptr; // * : asterisk

    a_ptr = &a; // & : address of operator

    printf("%d %d %p \n", a, *a_ptr, a_ptr);

    *a_ptr = 456; // *: re-direction or de-referencing

    printf("%d %d %p \n", a, *a_ptr, a_ptr);

    b = *a_ptr; // int b 변수에 a_ptr 대입하기

    printf("%d \n", b);

    *a_ptr = 789;
    
    printf("%d \n",b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b); // a,b 주소가 다름을 확인할 수 있다.
    
}
 */

//// 09-14. 포인터와 코딩 스타일

/* 
int main()
{
    // int *a_ptr vs int* a_ptr
    // int *my_ptr, sec_ptr;
    int *a, b;




}
 */

//// 09-15. NULL pointer와 런타임 에러

// int main()
// {

//     int a =1234;
//     printf("%p \n", &a);
//     printf("%d \n", a);

//     // int *ptr;

//     // printf("%p \n", ptr);
//     // printf("%p \n", *ptr);

//     int *safer_ptr = NULL;

//     int b;

//     scanf("%d", &b);

//     if (b%2==0)
//         safer_ptr = &a;

//     if (safer_ptr != NULL)
//         printf("%p \n", safer_ptr);

//     if (safer_ptr != NULL)
//         printf("%d \n", *safer_ptr);

//     return 0;
// }

//// # 09-16. 디버거로 메모리 들여다보기

/* #include <stdio.h>

int main()
{
    int a=3, b=5, c=7, d=9;
    int *a_ptr = &a, *b_ptr = &b, *c_ptr = &c, *d_ptr = &d;
    
    printf("%p %p %p %p", &a, &b, &c, &d );
    
    return 0;
} */

//// 09-17. 포인터 변수의 크기

// void main()
// {
//     char a;
//     float b;
//     double c;

//     char* ptr_a = &a;
//     float* ptr_b = &b;
//     double* ptr_c = &c;

//     printf("%zd %zd %zd \n", sizeof(a), sizeof(b), sizeof(c));
//     printf("%zd %zd %zd \n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));
//     printf("%zd %zd %zd \n", sizeof(&a), sizeof(&b), sizeof(&c));
//     printf("%zd %zd %zd \n", sizeof(char*), sizeof(float*), sizeof(double*));
// }

//// 09-18. 포인터형 매개변수

void swap(int* a, int* b)
{   
    printf("%p %p \n", a, b);

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a= 123;
    int b= 456;
    //swap code
    int* a_ptr = &a;
    int* b_ptr = &b;

    printf("%p %p\n", &a, &b);
    
    swap(a_ptr, b_ptr);
    
    printf("%d %d\n", a, b);
    return 0;
}