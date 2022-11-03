//// 12.1


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// //// 12.2
// int main()
// {

//     /* 
//         Object
//         - An Object is simply a block of memory that can store a value.
//         - Object has more developed meaning in C++ and OOP

//         Identifiers
//         - Names for variables, functions, macros, and other entitles.

//     */

//    int var_name = 3; // creates an object called 'var_name'

//    int* pt = &var_name; // pt is an identifier.
//    *pt = 1;         // *pt is not an identifier/ *pt designates an object.

//     int arr[100]; // arr is an identifier. Is arr an object?
//     // No! arr is just an address of the first value

//     arr[0] = 7; // arr[0] is an object. // identifier는 아니지만, expresssion을 통해 메모리 공간에 접근할 수 있다.
    

//     /* 
//         lvalue is an expression 'referring' to an object.

//         L-value: left side of an asssignment
//         R-value: right side, variable, constant, expressions

//     */

//    var_name = 3; // modifiable lvalue

//    pt = &var_name;
//    int* ptr = arr;
//    *pt = 7; // *pt is not an iddentifier but an modifiable lvalue expression.

//    int *ptr2 = arr + 2 * var_name; //addres rvalue(그냥 주소"값"이다)
//     *(arr + 2 * var_name) = 456; // lvalue expression //하지만 indirection을 붙여주면 접근 가능

//     const char* str= "constant sstring"; // str is a modifiable lvalue
//     str = "second string"; // so it cannot be used as a Lvalue (ex. constant string = second string)
//     //str[0] = 'A'; // Error

//     char str2[] = "string in an array";
//     str2[0] = 'A'; // OK
//     //puts(str2);

//     /* 

//         Identifiers have scope.
//         Objects have storage duration.
//         Variables and functions have one of the following linkages"
//             external linkage, internal linkage, or no linkage.s

//     */

//    return 0;    


// }

//// 12-03-a. 파일스코프

// /*
//     Variable scopes(visibility)
//     - block, function, function prototype, file.
// */

// int g_i = 123; //glb variable
// int g_j;

// void func1()
// {
//     g_i++; //uses g_i
// }

// void func2()
// {
//     g_i += 2;
//     //local = 456; error
// }


// int main()
// {
//     int local = 1234;
    
//     func1();
//     func2();

//     printf("%d\n", g_i);    // uses g_i
//     printf("%d\n", local);
//     printf("%d\n", g_j);    //0 // not initialized?
//     // 초기화되지 않은 전역 변수(혹은 정적 변수)들은 bss라는 메모리 공간에 저장되고, 해당 공간내의 변수들은
//     // 프로그램이 시작될 때 전부 0으로 초기화를 해준다.

//     return 0;

// }


//// 12-03-b. block, function, function prototype scope보기

// void f1(int, double); // to the end of the prototype declaration

// double func_block(double d)
// {
//     double p = 0.0;

//     for (int i = 0; i<10; i++)
//     {
//         double q = d* i;
//         p *= q;

//         if (i==5)
//             goto hello; // rarely used
//     }

// hello:
//     printf("Hello, World");

//     return p;

// }

//// 12-03-b. duration

// /* 
//     Storage duration에는 4가지 duration이 있다.
//     - static storage duration: 프로그램의 시작부터 끝까지 'static'하게 머문다.
//     (NOTE: 'static' keyword indicates the linkage type, not the storage duration)
//     - automatic storage duration: 
//     - allocated storage duration: 동적할당과 관련이 있음
//     - thread storage duration: 멀티스레딩 개념
// */

// void count()
// {
//     int ct = 0;
//     printf("count %d\n", ct);
//     ct++;
// }

// void static_count()
// {
//     static int ct =0; // 끝날때까지 재선언되지 않는다.
//     printf("static count = %d \n", ct);
//     ct++;
// }


//// 12-5 자동변수

// /*
//     automatic storage class
//     - Automatic storage duration, block scope, no linkage
//     - Any variable declared in a block or function header
// */

// void func(int k);

// int main() // NOTE; main() is a function
// {
//     auto int a; // keyword auto: a storage-classs specifier
//     // auto를 붙이지 않아도 지역변수가 선언된다. (동일)
//     a = 1024;
//     auto int b = a * 3; // what happends if uninitialized?

//     int i = 1;
//     int j = 2;

//     printf("i %lld \n", (long long)&i);

//     {
//         int i = 3;// name hiding
//         printf("i %lld \n", (long long)&i);

//         // j is visible here: 더 큰 영역에서 이미 지정이 되었기 때문에 가능함
//         printf("j = %d \n", j);

//     }

//     // ii iss not visible here

//     printf("i %lld \n", (long long)&i); // 위쪽 i

//     for (int m = 1; m<2; m++)
//         printf("m %lld \n", (long long)&m); //no block?

//     func(5);  // cannot see any of the variabled defined so far.

//     for (int m = 3; m< 4; m++)
//     {
//         printf("m %lld \n", (long long)&m);
//     }


// }

// void func(int k)
// {
//     int i = k * 2;
//     // do something with i and k
//     printf("i %lld \n", (long long)&i);
// }



//// 12-7

// void count()
// {
//     int ct =0;
//     printf("count = %d %lld \n", ct, (long long)&ct);
//     ct++;

//     // TODO return &ct;
// }

// void static_count()
// {
//     static int ct =0;
//     printf("static count = %d %lld \n", ct, (long long)&ct);
//     ct++;

//     // TODO return &ct;    
// }

// void counter_caller()
// {
//     count();
// }

// void static_counter_caller()
// {
//     static_count();
// }

// int main()
// {
//     count();
//     count();
//     counter_caller();

//     static_count();
//     static_count();
//     static_counter_caller();

//     return 0;
// }

//// 12-08

// /*
//     static variable with external linkage
//     - File scope, external linkage, static sotrage duration
//     - External storage class
//     - External variables
// */

// int g_int = 0;
// double g_arr[1000] = { 0.0, };

// /* initializing External variables */

// int x = 5;          //ok, constant expression
// int y = 1+ 2;       // ok, constant expression
// size_t z = sizeof(int); //ok, sizeof is a constant expressoin
// //int x2 = 2 * x;         // not ok! x is a variable. variable cannot be used when initializing

// void fun()
// {
//     printf("g_int in fun() %d %p \n", g_int, &g_int);
//     g_int +=10;
// }

// int main()
// {
//     /* 
//         defining declaration vs referencing declaration
//     */

//    extern int g_int; // optional
//    // extern int g_int = 1024; // error in block scope

//     //int g_int = 123;

//    extern double g_arr[]; // optional, size is not necessary

//    printf("g_int in main() %d %p \n", g_int, &g_int);
//    g_int += 1;

//    fun();

//    return 0;

// }

//// 12-09, 10. 정적 변수의 내부 연결(internal linkage)

// #include <stdlib.h> // srand()
// #include <time.h> // time()
// #include "my_rand.h"

// int main()
// {
//     /* 
//         rand()
//         - 0 to RAND_MAX (typically INT_MAX)
//         - defined in stdlib.h.
//     */

//    srand(1); // random seed
//    srand((unsigned int) time(0));

//    for (int i = 0; i<3; i++)
//    {
//        //printf("%d \n", rand());
//        //printf("%d \n", rand() % 6 + 1);s
//    }

//     unsigned int next = 1;

//     for (int i = 0; i< 3; ++i)
//     {
//         next = next * 1103515245 + 1234;
//         next = (unsigned int) (next / 65536) % 32768;
//         //printf("%d \n", (int) next);
//     }
    
//     my_srand((unsigned int) time(0));

//     for (int i = 0; i<10; ++i)
//     {
//         printf("%d\n", my_rand() % 6+ 1);
//     }

//     return 0;

// }

//// 12-13 동적할당

// int main()
// {
//     float x;
//     char str[] = "Dancing iwth a Star";
//     int arr[100];

//     /* 
//         malloc(): returns a void type pointer.
//         void* : generic pointer라고 불리기도 한다.(이유: 순수한 주소이기 때문)
//             - void* pointer는 자료형 연산을 사용할 수 없다. 왜냐하면 자료형이 정해지지 않았기 때문이다.
            
//         free() deallocates the memory
//     */

//    double* ptr = NULL;

//    ptr = (double*)malloc(30* sizeof(double)); 
//     // malloc() 내에는 사이즈를 지정해주면 된다.
//     // 추후에는 훨씬 더 큰 메모리를 넣어줘야 할 것이다.
//     // 위과 같이 형변환(타입캐스팅)을 하여 특정한 자료형인 것처럼 사용할 수 있다. 
//     // 배열처럼 사용하게 되는 것이 대부분이다.
    
//     if (ptr == NULL) // memory를 너무 큰 공간을 할당하여 에러가 할당을 못할때(null)도 있다.
//     {
//         puts("memory allocation failed");

//         /* 
//             exit(EXIT_FAILURE) is similar to return 1 IN main().
//             exit(EXIT_SUCCESS) is similar to return 0 IN main().
//         */

//        // memory 가 null인 경우 더이상 프로그램이 진행되지 않을 정도로 심각한 문제이기 때문에, 이를 종료시킨다.
//        // debug 할 때도 자주 사용한다.
//        exit(EXIT_FAILURE);
//     }

//     printf("Before free %p \n", ptr);

//     free(ptr); // no action occurs when ptr is NULL

//     printf("After free %p \n", ptr); // before free address와 동일하다.
//     // 이유: 해당 포인터에 값은 없어지지만, 포인터 "주소"는 남아있을 것

//     ptr = NULL; // optional

//     /* Dynamically Allocated Array */

//     int n = 5;
//     ptr = (double *)malloc(n*sizeof(double)); // variable도 할당 가능

//     if (ptr != NULL) //if(!ptr)
//     {
//         for (int i = 0; i < n; ++i)
//             printf("%f ", ptr[i]);
        
//         printf("\n");
//         printf("\n");

//         for (int i = 0; i<n; ++i)
//             * (ptr + i) = (double)i;
//         printf("\n");
//         printf("\n");

//         for (int i = 0; i < n; ++i)
//             printf("%f ", ptr[i]);
        
//         printf("\n");
//         printf("\n");                  
//     }

//     free(ptr);
//     ptr = NULL;

//     /*
//         comparision to VLA (Variance Length Arrays)

//         VLA
//         - not supported by compilers.
//         - automatic duration, cannot be resized
//         - limited by stack size (when complier plcaes VLA in stack segment)
//     */

//    return 0;

// }

//// 12-14

// int main()
// {
//     printf("Dummy output \n");

//     { // ptr이라는 식별자(idenfier)는 이 블럭 내에서만 살아있다.
//         int n = 1000000; // x86, x64 차이가 있다. 실무에서는 64를 많이 쓸 것
//         int* ptr = (int*)malloc(n*sizeof(int));

//         if (!ptr)
//             printf("Malloc failed \n");
//             exit(EXIT_FAILURE);

//         for (int i =0; i<n; ++i)
//             ptr[i] = i + 1;

//         free(ptr);
//         // ptr = NULL; // 사용하지 않아도 되지만, 명확하게 하려면 사용하는 것을 추천(교수님은 사용)
//     }

//     // what happens?

//     printf("Dummy output \n");
          
//     return 0;
// }

//// 12-15 동적할당메모리를 배열처럼 사용하기

// int main()
// {
    
//    /*
//         1D array
//     */

//    int n =3;
//    int * ptr= (int*)malloc(sizeof(int) * n);
//    if (!ptr) exit(1);

//    ptr[0] = 123;
//    *(ptr + 1) = 456;
//    *(ptr + 2) = 789;

//     free(ptr);
//     ptr = NULL;

//     /*
//         2D array
//     */

//    int row = 3, col =2 ;
//    int (*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row* col);
//    //int (*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col)); // VLA

//     if (!ptr2d) exit(1);

//     for (int r = 0; r < row; r++)
//         for (int c = 0; c< col; c++)
//             ptr2d[r][c] = c + col * r;

//     for (int r = 0; r< row; r++)
//     {
//         for (int c = 0; c < col; c++)
//             printf("%d ", ptr2d[r][c]);
//         printf("\n");
//     }

//     /* 
//         2D array like 1D
//     */

//    int row = 3, col = 2;
//    int* ptr = (int*)malloc(row*col*sizeof(int));
//    if (!ptr) exit(1);

//    for (int r = 0; r < row; r++)
//         for(int c = 0 ; c< col; c++)
//             ptr[c + col*r] = c + col *r;
    
//     for (int r = 0; r< row; r++)
//     {
//         for (int c = 0; c < col; c++)
//             printf("%d ", *(ptr + c + col *r));
//         printf("\n");
//     }

    

// }

//// 12-16

// int main()
// {
//     int n = 10;

//     int* ptr = NULL;

//     //ptr = (int*)malloc*(sizeof(int) * n)
//     ptr = (int*)calloc(n, sizeof(int)); // contiguous allocation
//     if (!ptr) 
//         exit(1);

//     for (int i = 0; i < n; ++i)
//         printf("%d ", ptr[i]);
//     printf("\n");

//     /*
//         realloc() ( = re allocation)
//         - doesn't initialize the bytes added
//         - returns NULL if can't enlarge the memory block
//         - If first argumment is NULL, it behaves like malloc()
//         - if second argument is 0, it fress the memory block.
//     */
   
//     for (int i = 0; i<n; ++i)
//         ptr[i] = i + 1;

//     n = 20;

//     int* ptr2 = NULL;
//     ptr2 = (int*)realloc(ptr, n * sizeof(int));
//     // ptr = (int*)realloc(ptr, n * sizeof(int));

//     printf("%p %p \n", ptr, ptr2);
//     printf("%d \n", ptr[0]);

//     if (!ptr2)
//         exit(1);
//     else
//         ptr = NULL;

//     for (int i =0; i<n; ++i)
//         printf("%d ", ptr2[i]); //copies data

//     free(ptr2);

// }

//// 17. 동적할당 메모리와 저장공간 분류
//// 18 type qualifier

// int main()
// {
//     /*
//         Const
//     */

//    typedef const int zip;
//    const zip q = 8; // == const const int zip 과 같을 것이다. 이러면 에러가 나야 하지만, 이를 에러가 나지 않게 자동으로 처리해준다.

//    const int j = 123;
//    const int arr[] = {1,2,3};

//    float f1 = 3.14f, f2 = 1.2f;

//    const float* pf1 = &f1;
//    // const 변수값은 바뀌지 않지만, pf1이라는 포인터 변수 자체는 다른 값을 가질 수 있다!!
//    pf1 = &f2;
//    // 하지만 indirection을 한 값을 바꿀수는 없다. // *pf1 = 5.0f -> error

//     // 아래와 같이 하면, 반대로 indirection 값을 바꿀수 있고, 포인터 변수를 바꿀 수 없게 된다.
//    float* const pf2 = &f1;
//    *pf2 = 6.0;
//    //pf2 = &f2; // Error!

//     // both of them cannot be
//    const float* const pf3 = &f1;

//    /*
//         global constants
//     */

//    /* 
//         volatile
//         - Do not optimize
//         - ex: hardward clock
//         - 컴파일러가 알 수 없는 값에 의해 값이 바뀔 수 있다!
//         - 결과적으로 컴파일러에게 "너가 최적화하지마라"라는 의미이다.
//     */

//    volatile int vi = 1; //volatile location
//    volatile int* pvi = &vi; // points to a volatile location

//    int i1 = vi;

//     // 변경 사항...

//     int i2 = vi; // 위에서 컴파일러가 모르게 운영체제가 값을 바꿔버리면 i2 값도 바뀔 것이다.
//     // 이를 방지하기 위해서 사용한다.

//     int ar[10] = {1,2,3,4,5,6,7,8,9,10};
//     int* par = ar;

//     /*
//         restrict: pointer가 "동적할당 받아온 메모리"를 다른 포인터나 다른 수단을 이용하여 접근하지 않겠다는 것을 의미한다.
//         - sole initial means of accessing a data object
//         - compiler can't check this restriction
//     */

//     int* __restrict restar = (int*)malloc(10*sizeof(int));
    
//     if (!restar)exit(1);

//     ar[0] += 3;
//     par[0] += 5; // 사실 이 둘은 동일하다. 
//     // par[0] += 8; // 따라서 8을 한번에 더하는 것과 동일할 것이다. 따라서 컴파일러 입장에서는 이렇게 최적화하고 싶을 것이다.
//     // 어찌됐든 컴파일러 입장에서 이들은 다른 이름이기 때문에 최적화를 못 해준다.

//     restar[0] += 3;
//     restar[0] += 5;
//     // restar[0] += 8; // 하지만 restrict 선언을 해주면 compiler가 자동으로 이를 수행해줄 수도 있다. 
//     // 왜냐하면 "(int*)malloc(10*sizeof(int));"에 접근할 수 있는 게 어차피 restar 밖에 없기 때문에 이들이 동일한 것을 지칭한다는 것을 이해할 수 있게 된다.

//     free(restar);

//     return 0;
// }

//// 19 멀티스레딩

#include <unistd.h> // sleep()
#include <pthread.h>
#include <stdatomic.h>

//티스토리 blog image참고