#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> // memcpy(), memmove()
#include <stdarg.h>

// 표준 라이브러리의 경우 "< >"를 사용하고, 
// 프로젝트에서 본인이 직접 생성한 경우 " "를 사용하는 것이 일반적이다.
// #include "my_functions.h"
// #include "my_structures.h"
// #include "my_headers/my_macros.h" // path


// //// 02
// int main()
// {
//     /* 
//         Program written in C

//         1st. Translating : 번역 단계를 먼저 거친다.
//         2nd. Preprocessing 
//         3rd. Compiling
//         4th. Linkning

//         Executable

//     */

//     /* 
//         International characters 
        
//         - 운영체제에 따라서 언어환경이 다른데, 국제 언어로 작성된 코드를 내부적으로 
//         이해할 수 있는 "문자 집합"으로 바꿔준다.    
        
//     */

    
//     puts("안녕 한글 좋아.\n");

//     /* 
//         Trigraph Sequences
//         - Some keyboards don't provide all the symbols used in C.
//         - Three-character sequences
    
//         Trigraph            Replacement
//         ??=                 #
//         ??/                 \
//         ??'                 ^
//         ...                 ...   
    
//     */

//     /*
//         Diagraphs
//         - Two-character sequences
//     */

//     /* Two physical lines vs One logical line */

//     printf("This very very very very very very very very very very very \
//             very very very long long long long long long long  line.\n");


//     /* 
//         Tokens
//         - Groups separted from each other by spaces, tabs, or line breaks 
//         Whitespace characters -> a single space
//     */

//    int /* a variable to count a number */ n =1;
//    // int n = 1;

//    return 0;

// }


//// 03

// /*
//     Preprocessor directives begins with # symbol at the beginning of a line.
// */

// /*
//     Macro
//     - An instruction that represents a sequence of instructions in abbreviated form.

// */

// /*
// #define         SAY_HELLO       printf("hello world");

// preprocessor    macro(name)     body(or replacement list)
// directive

// Macro expansion
// */

// /*
//     "Object-like macros(추천)" vs Function-like macros

// #define ONE 1
// #define SQUARE(X) X*X
// */

// #define PI 3.141592 /* Symbolic, or manifest, constants */
// #define GRAVITY 9.8

// #define THREE 3
// #define MESSASGE "The greatest glory in living lies not in never falling,  \
// but in rising every time we fall."

// #define NINE THREE*THREE
// #define SAY_HELLO for(int i =0; i< 10; i++) printf("hello world! \n");
// #define FORMAT "number is %d.\n"

//     # define WITH_BLACK 1

// #define MY_CH 'Z'
// #define MY_ST "Z" // Z\0 : 보이지 않는 NULL character가 숨어있다.

// #define LIMIT 20
// const int LTM = 50;
// static int arr1[LIMIT];
// // static int arr2[LIM]; // clang, C++ (doesn't work at gcc)

// const int LIM2 = 2 * LIMIT;
// // const int LIM3 = 2 * LTM; // clang, C++ (doesn't work at gcc)

// /*
//     Tokens


// #define SIXX 3*2
// #define SIX 3 * 2
// #define SIX 3            *             2

// - 컴파일러가 위 선언들을 해석할 떄 이들을 문자로 해석할지, 숫자로 해석할지 등 옵션이 있다.
// - 컴파일러는 이를 의미있는 단위로 쪼갠다.
// - 하지만 전처리기가 이를 어떻게 해석하는지는 조금 애매한 면이 있다.

// */

// /* 
//     Redefining Constants
    
//     - 한 파일 내에서 똑같이 macro이름에 대해 define하는 것은 정말 드물다.(실수일 가능성이 높다.)
//     - 하지만 문법적으론 가능하다.
//     - 다른 헤더파일로부터 include 할 때는 의도치 않게 redefine되는 경우가 있다    
    
// */


// #define SIX 2*3
// #define SIX 2*3

// //#undef SIX
// //#define SIX 2     *        3 // Warning
// // 하지만 이들이 토큰 단위로 봤을 떄 다르다면 warning이 뜬다. 

// int main()
// {
//     int n = THREE;

//     SAY_HELLO; // NOTE the additional
//     n = NINE;

//     printf(FORMAT, n); 
//     printf("%s \n", MESSASGE); // replaced
//     printf("SAY_HELLO NINE \n"); // not replaced

//     return 0;
// }

//// 04-01

// /*
//     Function like macros

    // #define     ADD(X,Y)        ((X)+(Y))

//     X and Y : macro arguments

//     - 주의점: 괄호가 생각하는 것보다 많이 쳐져있는 것을 확인할 수 있다. 
//         - 이들이 전처리기를 지나면서 원치 않는 방향으로 넘어가질 때가 많다. 아래 예시를 살펴보자.
// */

// #define ADD1(X,Y)   X+Y
// #define ADD2(X,Y)   ((X)+(Y)) 
// #define SQUARE(X) X*X       // ((X)*(X))

// int main()
// {
//     int sqr = SQUARE(3);

//     int a = 1;

//     printf("%d \n", 2 * ADD1(1,3)); // 2 * X + Y = 2 * 1 + 3 = 5 -> WRONG!
//     printf("%d \n", 2 * ADD2(1,3)); // 2 * (X + Y) = 2 * ( 1 + 3 )= 8

//     printf("%d\n", SQUARE(1+2)); // 1+2*1+2 = 1+2+2 = 5 -> WRONG!
//     printf("%d\n", 100 / SQUARE(3+1)); // 100/3 + 1*3 + 1 = 33 + 3 + 1 = 37 -> WRONG!
//     printf("%d\n", SQUARE(++a)); // ++a * ++a =  3 * 3 = 9 -> WRONG!
//     // 전위이든 후위이든 증가연산자를 넣을 땐 주의가 필요하다.
//     // 전위 연산자가 두 번 들어가서 1->2, 2->3으로 a값이 바뀐다. 그렇게 되면서 3 * 3이 나온다.
//     // 또한, 컴파일러에 따라 결과가 다를 수도 있다!!!!

//     return 0;


// }



// //// 04-02



// #define SQUARE(X) (X)*(X)
// #define PRINT_SQR1(x) printf("The square of %d is %d.\n", x, SQUARE(x))
// #define PRINT_SQR2(x) printf("The square of " #x " is %d.\n", SQUARE(x))




// /*
//     stringizing operator #
//     - converts macro parameters to string literals

//     - 사용법: 매크로 function의 argument 앞에 #(해쉬)를 붙여주면 이를 "문자열로 바꾸고" -> 컴파일을 진행시켜준다.

// */

// #define XNAME(n) x ## n // x: 그냥 'x' // n은 프로그래머의 입력값에 따라 달라짐
// #define PRT_XN(n) printf("x" #n " = %d\n", x ## n);

// int main()
// {
//     PRINT_SQR1(10);
//     PRINT_SQR2(10);

//     printf("\n");

//     int XNAME(1) = 1;   // int x1 = 1;
//     int XNAME(2) = 2;   // int x2 = 2;

//     PRT_XN(1);      // printf("x1 " = %d\n", x1);
//     PRT_XN(2);      // printf("x2 " = %d\n", x2);

//     return 0;
    

// }



// /* 
//     MACRO or Function? --> 정답: 무조건 function 쓰세요!
//     - no space in the macro name
//     - Use parentheses
//     - Use capital letters for macro function names
//     - Speed up?
// */


// // 아래와 같은 식들은 예전에 많이 사용되었다. 현재는 이들을 전부 제거하고, 함수를 사용하는 방식으로 바뀌고 있다.
// // #define MAX(X,Y)    ( (X) > (Y) ? (X) : (Y))
// // #define MIN(X,Y)    ( (X) < (Y) ? (X) : (Y))
// // #define ABS(X,Y)    ( (X) < 0   ? -(X): (X))



//// 05

// /*
//     Variadic Macros accept a variable number of arguments.
// */


// #define PRINT(X, ...) printf("Message" #X ": " __VA_ARGS__)
// // ... : ellipses.
//     //// argument에 여러 가지가 들어갈 수 있음 (추후 설명)
// // __VA_ARGS: One of the predefined macros
//     //// variadic + arguements
// // 기능: ... 자리에 들어온 것들을 __VA_ARGS__ 자리로 옮겨준다.


// /*
//     printf(...)
//     stdvar.h Variadic arguments
// */

// int main()
// {
//     double x = 48;
//     double y ;

//     y = sqrt(x);
//     PRINT(1, " x = %g\n", x);
//     PRINT(2, " x = %.2f, y = %.4f\n", x, y);

//     return 0;
// }


// //// 06

// /*static*/ int status;

// int main()
// {

// // #include "hello_world.h" // 절대 main() 안에 include를 넣지마라!!

//     printf("PI = %f\n", PI);

//     printf("%p %d\n", &status, status);

//     print_status();

//     printf("%d\n", multiply(51, 2));

//     printf("main()\n");
//     printf("Static function address %p \n", multiply);
//     printf("Static variable address %p \n", &si);
    
//     print_address();

//     return 0;
// }


//// 07 조건따라 컴파일

// /*
//     #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
// */

// /*
//     #undef
// */

// #define LIMIT 400
// // #undef LIMIT // it's ok to undefine previously NOT defined macro.

// int sum(int i, int j)
// {
//     int s = 0;
//     for (int k = i; k<= j; ++k)
//     {
//         s+= k;



// #ifdef _DEBUG // TODO: change in project properties
//         printf("%d %d \n", s, k");
// #endif
//     }

//     return s;
// }


// int main()
// {
//     printf("\n %d \n", sum(1,10));

//     return 0;
// }


//// 08

// //#include "different.h"
// void different_function();

// int main()
// {
//     // 빌드한 시간에 맞춰서 출력될 것이다.
//     printf("__FILE__: %s \n", __FILE__);
//     printf("__DATE__: %s \n", __DATE__);
//     printf("__TIME__: %s \n", __TIME__);
//     printf("__LINE__: %d \n", __LINE__);
//     printf("__func__: %s \n", __func__);

//     different_function();

//     // different_func_in_different_file();
    


// /* define을 통해 강제로 무언가를 바꿔줄 수 있다.*/
// #line 7
//     printf("__LINE__ after #line %d \n", __LINE__);
// #line 1
//     printf("__LINE__ after #line %d \n", __LINE__);
//     printf("__FILE__ : %s \n", __FILE__);

// /* 특정한 조건에 따라 error를 출력하여 컴파일을 하지 않도록 할 수 있다. */
// // 이 코드는 꼭 이런 상황일 때 컴파일되어야 한다! 라는 상황일 때 다음과 같이 define할 수 있다. -> 실무에서 중요하게 사용될 수 있다.

// // #if __LINE__ != 33
// // #error Not line 33 //error: Not line 33
// // #endif

// // #if defined(_WIN64) != 1
// // #error NOT WIN64 platformm
// // #endif

//     return 0;

// }


// void different_function(){
//     printf("This function is %s \n", __func__);
//     printf("This is line %d \n", __LINE__);
// }



//// 09. pragma

// /*
//     #pragma tokens (Ex: once)    
// */

// //// #pragma pack(1) // complie때 1바이트로 패딩해라 == compile을 하지 마라.

// //// _Pragma("pack(1)") // destringizing : remove first and last ", \" -> " 
// // pragma 다음에 와야할 토큰을 문자열로 넣어준다. 해당 문자열을 destringizing 해준다.
// // 이렇게 쓰는 이유: 아래와 같이 매크로로 만들어줄 수 있기 때문에!

// //// #define PACK1 _Pragma("pack(1)")
// //// PACK1

// ////#pragma warning ( disable : 4477)
// // warning을 없애버릴 수도 있다!

// ////#pragma warning ( error : 4477)
// // warning을 error로 처리할 수 있다! <- 해당 warning이 프로그램에서 절대 발생하면 안 되는 경우에 사용

// struct s
// {
//     /* data */
//     int i;
//     char ch;
//     double d;
// };

// int main()
// {
//     struct s A;
//     printf("size of A is : %zd", sizeof(A));




//     return 0;
// }


//// 10

// /*
//     Generic selection expression
//     - Generic programming: code is not specific to a particular type
//         - (특정 자료형에서만 작동하는 코드가 아니라,) 일반적인 자료형 코드를 만드는 것을 의미한다.
//     _Generic : C11 keyword
// */

// #define MYTYPE(X) _Generic( (X), \
//     int : "int", \
//     float: "float", \
//     double: "double", \
//     long: "long", \
//     int*: "int*", \
//     default: "other"\
// )

// int main()
// {
//     int d = 5;

//     printf("%s\n", MYTYPE(d)); // int -> int
//     printf("%s\n", MYTYPE(2.0*d)); // double -> double
//     printf("%s\n", MYTYPE(3L)); // long -> long
//     printf("%s\n", MYTYPE(&d)); // int pointer -> int*

//     return 0;
// }

//// 11

// /*
//     Function call has overhead
//     - set up the call, pass arguments jump to the function code, and return.

//     inline "function specifier"
//     - "Suggests" inline replacements.(to compiler)
    

//     Inline functions shoudl be "short".
//     A function with internal linkage can be made inline. (GCC, clang)
//     You can't take "its address".
// */

// // error: inline int foo() -> internal linkage가 아니기 때문
// static inline int foo()
// {
//     return 5;
// }

// // Driver code
// int main()
// {
//     int ret;

//     // inline function call
//     ret = foo();

//     printf("output is : %d\n", ret);
//     return 0;
// }


//// 12

// #include "MyLibrary.h"

// void say_hello(){
//     printf("Hello \n");
// }

// void say_world()
// {
//     printf("world \n");
// }

//// 13

// int main()
// {
//     printf("%f \n", cos(3.141592));

//     /*
//         Pythagorean theorem
//     */

//    double c = 5.0, b = 4.0, a; //a?
//    a = sqrt( c*c - b*b);
//    printf("a = %f\n", a);

//    float cf = 5.0f, bf = 4.0f, af; //float!!
//    af = sqrtf( cf*cf - bf*bf);
//    printf("af = %f\n", af);

//    // 주의: double로 표현되는 sqrt가 정밀도가 높을 것이다!

//    return 0;
// }

//// 14

// /*
//     rand(), srand(), malloc(), free(), ...
// */

// void goodbye(void)
// {
//     printf("goodbye\n");
// }

// void thankyou(void)
// {
//     printf("thankyou\n");
// }

// int main()
// {
//     printf("Purchased? \n");
//     if (getchar() == 'y')
//         atexit(thankyou);
//         // 프로그램이 종료될 때 어떤 함수를 등록할지 호출해준다!!
//         // 내부적으로 함수 포인터의 리스트 목록을 가지고 있다.

//     while (getchar() != '\n') {};

//     printf("Goodbye message? \n");
//     if (getchar() == 'y')
//         atexit(goodbye);

//     /*
//         exit(0);
//     */


//     /*
//         qsort();
//     */

//     return 0;
// }

//// 15


// //#include <limits.h>
// // _Static_assert(CHAR_BIT == 9, "9-bit char assumed");
// // static assert는 컴파일 타임에서 잡아주는 assert이다.

// int divide(int a, int b);

// int main()
// {

//     int a, b;
//     int f = scanf("%d%d", &a, &b);

//     printf("a/b = %d", divide(a,b));

//     return 0;
// }



// int divide(int a, int b)
// {
//     assert(b!=0);

//     return a/b;
// }


//// 16

// #define LEN 6

// void prt(int *arr, int n)
// {
//     for (int i=0; i<n; ++i)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main()
// {
//     /*
//     - overlapping region
//     - pointer-to-void (datatype is unknown)
//     */

//    int arr1[LEN] = {1,3,5,7,9,11};
//    // int arr2[LEN] = {0,  };

//    int* arr2 = (int*)malloc(LEN * sizeof(int));
//    if (arr2 == NULL) exit(1);

// // case1: memcpy()를 사용하지 않고 for문을 돌면서 요소 하나하나 복사할 때
//     for (int i = 0; i < LEN; i++)
//     {
//         /* code */
//         arr2[i] = arr1[i];
//     }

// // case2: memcpy()를 이용해 메모리 자체를 복사!    
//     //memcpy(void* destination,void* source, size_t)
//     memcpy(arr2, arr1, sizeof(int)*LEN);
//     prt(arr2, LEN);

//     /*

//     현재 arr1 => {1 3 5 7  9 11}
//     바꾸고자 하는 aar1 => {5 7 9 11 9 11}

//     - 다음과 같이 arr1을 바꾸고자 할때, [2]부터 [5]까지 바꾸게 된다. 이때 중간에 두 개의 원소가 겹치는데,
//     - 이때 memcpy()를 쓰면 문제가 발생할 가능성도 있다고 한다.
//     - 하지만, memmove() 같은 경우는 복사할 원소를 어떤 버퍼에 저장했다가 이후 이를 복사하는 방식이기 때문에 겹치는 구간이 있어도 문제가 생기지 않도록 구현했다고 한다.
//     */

//    // memcpy(arr1, &arr1[2], sizeof(int) * 4); //undefined behavior
//    memmove(arr1, &arr1[2], sizeof(int)*4);
//    prt(arr1, LEN);

//    return 0;
// }


//// 17

/*
Variable Arguments
- int prinft(char const* const_Format, ...);

- 1. Provide a function prototype using an ellipsis

void    vaf1(int n, ...); // OK
int     vaf2(const char* s, int k, ...); //OK
char    vaf3(char c1, ..., char c2); //NOT OK, ellipsis should be the last!
double  vaf4(...)l // NOT OK. no parameter

- 2. Create a va_list type variable in the function definition
- 3. Use a macro to initialize the variable to an argument list.
- 4. Use a macro to access the argument list.
*/


double average(int, ...);
double average2(char* format_string, ...);

int main()
{
    double a, b;
    a = average(3, 1.1, 2.2, 3.3);
    b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    
    a = average2("d", 1.1, 2.2, 3.3);
    b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    printf("%lf\n", a);
    printf("%lf\n", b);
}

double average(int num, ...)
{
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, num);
    for (int i = 0; i < num; i++)
    {
        /* code */
        sum += va_arg(ap, double);
    }

    va_end(ap);

    return sum /  (double)num;
    
}

double average2(char* format_string, ...) // 젤 앞 문자열의 수만큼 평균 세기
{
    int num = strlen(format_string);

    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, format_string);
    //va_start에 format_string이 들어가는 이유: 그것의 내용 자체가 중요한 게 아니고 ap 다음부터 variable argument가 들어온다는 것을 표현하기 위해

    for (int i = 0; i < num; i++)
    {
        /* code */
        sum += va_arg(ap, double);
    }
    
    va_end(ap);

    return sum/(double)num;

}