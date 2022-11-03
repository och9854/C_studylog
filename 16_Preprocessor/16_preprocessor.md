# 16-01. Preprocessor가 해주는 일들
---

프로그램을 작성할 때, 코드를 가장 먼저 보는 게  전처리기이다. "컴파일러"의 "전에" 처리를 해주기 때문에 전처리기이다.

<img width="881" alt="image" src="https://user-images.githubusercontent.com/78291267/172290823-74340ce6-8b43-4536-990b-7bdc460e15c8.png">

최근에는 다양한 플랫폼에서 상품화를 하는 경우가 많다. 윈도우, 앱스토어, 리눅스 등에서 돌아가게 해주는 게 필요하다. C, C++ 언어를 사용할 때 전처리기에 어떻게 코드를 컴파일할지 결정할 수 있도록 도와주는(조건적으로 도와주는) 가능을 사용하면 좋을 것이다.

# 16-02. 전처리를 준비하는 번역 단계(Translation phases)
----

```c
//// 02
int main()
{
    /* 
        Program written in C

        1st. Translating : 번역 단계를 먼저 거친다.
        2nd. Preprocessing 
        3rd. Compiling
        4th. Linkning

        Executable

    */

    /* 
        International characters 
        
        - 운영체제에 따라서 언어환경이 다른데, 국제 언어로 작성된 코드를 내부적으로 
        이해할 수 있는 "문자 집합"으로 바꿔준다.    
        
    */

    
    puts("안녕 한글 좋아.\n");

    /* 
        Trigraph Sequences
        - Some keyboards don't provide all the symbols used in C.
        - Three-character sequences
    
        Trigraph            Replacement
        ??=                 #
        ??/                 \
        ??'                 ^
        ...                 ...   
    
    */

    /*
        Diagraphs
        - Two-character sequences
    */

    /* Two physical lines vs One logical line */

    printf("This very very very very very very very very very very very \
            very very very long long long long long long long  line.\n");


    /* 
        Tokens
        - Groups separted from each other by spaces, tabs, or line breaks 
        Whitespace characters -> a single space
    */

   int /* a variable to count a number */ n =1;
   // int n = 1;

   return 0;

}
```


# 16-03. Define 매크로
---

```c


/*
    Preprocessor directives begins with # symbol at the beginning of a line.
*/

/*
    Macro
    - An instruction that represents a sequence of instructions in abbreviated form.

*/

/*
#define         SAY_HELLO       printf("hello world");

preprocessor    macro(name)     body(or replacement list)
directive

Macro expansion
*/

/*
    "Object-like macros(추천)" vs Function-like macros

#define ONE 1
#define SQUARE(X) X*X
*/

#define PI 3.141592 /* Symbolic, or manifest, constants */
#define GRAVITY 9.8

#define THREE 3
#define MESSASGE "The greatest glory in living lies not in never falling,  \
but in rising every time we fall."

#define NINE THREE*THREE
#define SAY_HELLO for(int i =0; i< 10; i++) printf("hello world! \n");
#define FORMAT "number is %d.\n"

    # define WITH_BLACK 1

#define MY_CH 'Z'
#define MY_ST "Z" // Z\0 : 보이지 않는 NULL character가 숨어있다.

#define LIMIT 20
const int LTM = 50;
static int arr1[LIMIT];
// static int arr2[LIM]; // clang, C++ (doesn't work at gcc)

const int LIM2 = 2 * LIMIT;
// const int LIM3 = 2 * LTM; // clang, C++ (doesn't work at gcc)

/*
    Tokens


#define SIXX 3*2
#define SIX 3 * 2
#define SIX 3            *             2

- 컴파일러가 위 선언들을 해석할 떄 이들을 문자로 해석할지, 숫자로 해석할지 등 옵션이 있다.
- 컴파일러는 이를 의미있는 단위로 쪼갠다.
- 하지만 전처리기가 이를 어떻게 해석하는지는 조금 애매한 면이 있다.

*/

/* 
    Redefining Constants
    
    - 한 파일 내에서 똑같이 macro이름에 대해 define하는 것은 정말 드물다.(실수일 가능성이 높다.)
    - 하지만 문법적으론 가능하다.
    - 다른 헤더파일로부터 include 할 때는 의도치 않게 redefine되는 경우가 있다    
    
*/


#define SIX 2*3
#define SIX 2*3

//#undef SIX
//#define SIX 2     *        3 // Warning
// 하지만 이들이 토큰 단위로 봤을 떄 다르다면 warning이 뜬다. 

int main()
{
    int n = THREE;

    SAY_HELLO; // NOTE the additional
    n = NINE;

    printf(FORMAT, n); 
    printf("%s \n", MESSASGE); // replaced
    printf("SAY_HELLO NINE \n"); // not replaced

    return 0;
}

```

define의 편리한 점은 프로그래머가 기호적 상수를 이용하여 gravity, PI 등의 숫자들을 기호적으로 프로그래밍 할 수 있다는 것이다. 

문법을 하는 컴파일러는 매크로 처리된 기호를 볼 일이 없다! 전처리기가 이를 먼저 처리하여 컴파일러에게 넘겨주기 때문이다.



# 16-04. 함수 같은 매크로
---

메크로를 함수처럼 사용하는 방법에 대해 알아보자.


## 04-01

```c

/*
    Function like macros

    #define     ADD(X,Y)        ((X)+(Y))

    X and Y : macro arguments

    - 주의점: 괄호가 생각하는 것보다 많이 쳐져있는 것을 확인할 수 있다. 
        - 이들이 전처리기를 지나면서 원치 않는 방향으로 넘어가질 때가 많다. 아래 예시를 살펴보자.
*/

#define ADD1(X,Y)   X+Y
#define ADD2(X,Y)   ((X)+(Y)) 
#define SQUARE(X) X*X       // ((X)*(X))

int main()
{
    int sqr = SQUARE(3);

    int a = 1;

    printf("%d \n", 2 * ADD1(1,3)); // 2 * X + Y = 2 * 1 + 3 = 5 -> WRONG!
    printf("%d \n", 2 * ADD2(1,3)); // 2 * (X + Y) = 2 * ( 1 + 3 )= 8

    printf("%d\n", SQUARE(1+2)); // 1+2*1+2 = 1+2+2 = 5 -> WRONG!
    printf("%d\n", 100 / SQUARE(3+1)); // 100/3 + 1*3 + 1 = 33 + 3 + 1 = 37 -> WRONG!
    printf("%d\n", SQUARE(++a)); // ++a * ++a =  3 * 3 = 9 -> WRONG!
    // 전위이든 후위이든 증가연산자를 넣을 땐 주의가 필요하다.
    // 전위 연산자가 두 번 들어가서 1->2, 2->3으로 a값이 바뀐다. 그렇게 되면서 3 * 3이 나온다.
    // 또한, 컴파일러에 따라 결과가 다를 수도 있다!!!!

    return 0;


}
```



## 04-02

```c

//// 04-02



#define SQUARE(X) (X)*(X)
#define PRINT_SQR1(x) printf("The square of %d is %d.\n", x, SQUARE(x))
#define PRINT_SQR2(x) printf("The square of " #x " is %d.\n", SQUARE(x))




/*
    stringizing operator #
    - converts macro parameters to string literals

    - 사용법: 매크로 function의 argument 앞에 #(해쉬)를 붙여주면 이를 "문자열로 바꾸고" -> 컴파일을 진행시켜준다.

*/

#define XNAME(n) x ## n // x: 그냥 'x' // n은 프로그래머의 입력값에 따라 달라짐
#define PRT_XN(n) printf("x" #n " = %d\n", x ## n);

int main()
{
    PRINT_SQR1(10);
    PRINT_SQR2(10);

    printf("\n");

    int XNAME(1) = 1;   // int x1 = 1;
    int XNAME(2) = 2;   // int x2 = 2;

    PRT_XN(1);      // printf("x1 " = %d\n", x1);
    PRT_XN(2);      // printf("x2 " = %d\n", x2);

    return 0;
    

}



/* 
    MACRO or Function? --> 정답: 무조건 function 쓰세요!
    - no space in the macro name
    - Use parentheses
    - Use capital letters for macro function names
    - Speed up?
*/


// 아래와 같은 식들은 예전에 많이 사용되었다. 현재는 이들을 전부 제거하고, 함수를 사용하는 방식으로 바뀌고 있다.
// #define MAX(X,Y)    ( (X) > (Y) ? (X) : (Y))
// #define MIN(X,Y)    ( (X) < (Y) ? (X) : (Y))
// #define ABS(X,Y)    ( (X) < 0   ? -(X): (X))


```

# 16-05. 가변 인수 매크로
---

가변 인수 매크로는 가변 파라미터(...)를 사용하여 함수를 보다 유연하게 해 준다.. 


```c


/*
    Variadic Macros accept a variable number of arguments.
*/


#define PRINT(X, ...) printf("Message" #X ": " __VA_ARGS__)
// ... : ellipses.
    //// argument에 여러 가지가 들어갈 수 있음 (추후 설명)
// __VA_ARGS: One of the predefined macros
    //// variadic + arguements
// 기능: ... 자리에 들어온 것들을 __VA_ARGS__ 자리로 옮겨준다.


/*
    printf(...)
    stdvar.h Variadic arguments
*/

int main()
{
    double x = 48;
    double y ;

    y = sqrt(x);
    PRINT(1, " x = %g\n", x);
    PRINT(2, " x = %.2f, y = %.4f\n", x, y);

    return 0;
}

```

# 16-06. #include와 헤더 파일
---

이번 강의에서는 복습겸 중요한 부분들을 짚고 넘어가자.

```c
/*static*/ int status;

int main()
{

// #include "hello_world.h" // 절대 main() 안에 include를 넣지마라!!

    printf("PI = %f\n", PI);

    printf("%p %d\n", &status, status);

    print_status();

    printf("%d\n", multiply(51, 2));

    printf("main()\n");
    printf("Static function address %p \n", multiply);
    printf("Static variable address %p \n", &si);
    
    print_address();

    return 0;
}

```

# 16-07. 조건에 따라 다르게 컴파일하기(Conditional Compliation)
----

전처리 지시자를 이용하여 조건에 따라 다르게 컴파일하는 방법을 알아보자.

header guard란 #define이 중복해서 되는 것을 막아준다.

```c

#ifndef HEADER_A
#define HEADER_A

#include <stdio.h>

static void test_function_A()
{
    printf("Hello, header_A\n");
}

#endif

```

위와 같이 선언을 해주고, 마지막에는 #endif를 사용해 종료해준다.

또한, 조건문을 지정하여 include할 파일도 지정해줄 수 있다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/172593842-45564a54-e6c2-40a8-9e2e-4c53af00c346.png">





# 16-08. 미리 정의된 매크로들, #line, #error
---

여러 전처리 지시자들의 사용법을 알아보자.

```c

different.h"
void different_function();

int main()
{
    // 빌드한 시간에 맞춰서 출력될 것이다.
    printf("__FILE__: %s \n", __FILE__);
    printf("__DATE__: %s \n", __DATE__);
    printf("__TIME__: %s \n", __TIME__);
    printf("__LINE__: %d \n", __LINE__);
    printf("__func__: %s \n", __func__);

    different_function();

    // different_func_in_different_file();
    


/* define을 통해 강제로 무언가를 바꿔줄 수 있다.*/
#line 7
    printf("__LINE__ after #line %d \n", __LINE__);
#line 1
    printf("__LINE__ after #line %d \n", __LINE__);
    printf("__FILE__ : %s \n", __FILE__);

/* 특정한 조건에 따라 error를 출력하여 컴파일을 하지 않도록 할 수 있다. */
// 이 코드는 꼭 이런 상황일 때 컴파일되어야 한다! 라는 상황일 때 다음과 같이 define할 수 있다. -> 실무에서 중요하게 사용될 수 있다.

// #if __LINE__ != 33
// #error Not line 33 //error: Not line 33
// #endif

// #if defined(_WIN64) != 1
// #error NOT WIN64 platformm
// #endif

    return 0;

}


void different_function(){
    printf("This function is %s \n", __func__);
    printf("This is line %d \n", __LINE__);
}


```


# 16-09. #pragma 지시자
----

컴파일러에게 어떻게 컴파일해달라라고 지시할 수 있는 pragma 전처리 지시자에 대해 알아보자.

```c


/*
    #pragma tokens (Ex: once)    
*/

//// #pragma pack(1) // complie때 1바이트로 패딩해라 == compile을 하지 마라.

//// _Pragma("pack(1)") // destringizing : remove first and last ", \" -> " 
// pragma 다음에 와야할 토큰을 문자열로 넣어준다. 해당 문자열을 destringizing 해준다.
// 이렇게 쓰는 이유: 아래와 같이 매크로로 만들어줄 수 있기 때문에!

//// #define PACK1 _Pragma("pack(1)")
//// PACK1

////#pragma warning ( disable : 4477)
// warning을 없애버릴 수도 있다!

////#pragma warning ( error : 4477)
// warning을 error로 처리할 수 있다! <- 해당 warning이 프로그램에서 절대 발생하면 안 되는 경우에 사용

struct s
{
    /* data */
    int i;
    char ch;
    double d;
};

int main()
{
    struct s A;
    printf("size of A is : %zd", sizeof(A));




    return 0;
}

```


# 16-10. _Generic 표현식
---

```c


/*
    Generic selection expression
    - Generic programming: code is not specific to a particular type
        - (특정 자료형에서만 작동하는 코드가 아니라,) 일반적인 자료형 코드를 만드는 것을 의미한다.
    _Generic : C11 keyword
*/

#define MYTYPE(X) _Generic( (X), \
    int : "int", \
    float: "float", \
    double: "double", \
    long: "long", \
    int*: "int*", \
    default: "other"\
)

int main()
{
    int d = 5;

    printf("%s\n", MYTYPE(d)); // int -> int
    printf("%s\n", MYTYPE(2.0*d)); // double -> double
    printf("%s\n", MYTYPE(3L)); // long -> long
    printf("%s\n", MYTYPE(&d)); // int pointer -> int*

    return 0;
}


```


# 16-11. inline 함수
---

작은 함수가 여러 차례 반복될 때 실행횟수를 끌어올릴 수 있는 inline 문법에 대해 알아보자.

```c
/*
    Function call has overhead
    - set up the call, pass arguments jump to the function code, and return.

    inline "function specifier"
    - "Suggests" inline replacements.(to compiler)
    

    Inline functions shoudl be "short".
    A function with internal linkage can be made inline. (GCC, clang)
    You can't take "its address".
*/

// error: inline int foo() -> internal linkage가 아니기 때문
static inline int foo()
{
    return 5;
}

// Driver code
int main()
{
    int ret;

    // inline function call
    ret = foo();

    printf("output is : %d\n", ret);
    return 0;
}
```

inline 함수를 사용할 때는 보통은 c main 프로그램 안에 넣지 않는다. 헤더파일을 만들어 사용하는 것이 일반적이다.

# 16-12. 라이브러리
---

라이브러리들을 불러올 때 어떤식으로 불러와지고, 어떻게 사용하는지 알려면 라이브러리를 만들어보면 바로 이해할 것이다.

library는 필요한 책들이 잔뜩 모여있는 도서관(library)을 연상하면 된다. 참고로 컴파일(complie)은 영어에서 책을 출판하기 위해 '편집한다'는 의미이다. 

- 순서: 라이브러리를 include -> 라이브러리에 만들어져있는 선언들을 컴파일러에게 알려줌 -> linking 과정에서 내부적으로 알아서 구현된 것들을 찾아서 연결해줌

이번 강의에서는 위 순서를 정확히 이해하기 위해 라이브러리를 직접 만들어보자.

라이브러리에는 2가지 라이브러리가 있다.
- .dll: Dynamic Library. (프로그램 자체가 라이브러리를 가지는 게 아니라) 프로그램이 실행될 때 동적으로 사용한다.
- .lib: Static Library. 프로그램을 만들 때, 해당 프로그램 내에 라이브러리가 "포함"된다.

- Mac OS setting을 해두지 않아서 따라하지는 못했다. 

- 강의 포인트
  - 여러 개발 환경의 도움으로 개발을 편하게 했다. 이는 컴파일러를 개발하는 사람들이 표준 라이브러리까지 함께 개발을 한 덕분이다.
  - 이번 강의에서 라이브러리를 직접 만들고, 다른 프로젝트에서 미리 만들어 둔 라이브러리를 가져와 사용하는 과정을 직접 해 보았기 때문에, 컴파일러가 만들어지는 과정을 이해하게 되었다.
  - 물론, 현대 프로그래밍에서는 이런 자잘한 것들보다는 프로그래밍에 더 집중할 수 있다. 다만, 내부적으로 어떤 과정으로 진행되는지는 한 번쯤은 공부해 두는 걸 추천한다.

# 16-13. 표준 수학 라이브러리
---

c언어에는 많은 표준 수학 라이브러리가 존재한다. 이 중 레퍼런스 메뉴얼을 둘러보면서 찾아보게 된다. 

```c


int main()
{
    printf("%f \n", cos(3.141592));

    /*
        Pythagorean theorem
    */

   double c = 5.0, b = 4.0, a; //a?
   a = sqrt( c*c - b*b);
   printf("a = %f\n", a);

   float cf = 5.0f, bf = 4.0f, af; //float!!
   af = sqrtf( cf*cf - bf*bf);
   printf("af = %f\n", af);

   // 주의: double로 표현되는 sqrt가 정밀도가 높을 것이다!

   return 0;
}

```

# 16-14. 표준 유틸리티 라이브러리
---


```c


/*
    rand(), srand(), malloc(), free(), ...
*/

void goodbye(void)
{
    printf("goodbye\n");
}

void thankyou(void)
{
    printf("thankyou\n");
}

int main()
{
    printf("Purchased? \n");
    if (getchar() == 'y')
        atexit(thankyou);
        // 프로그램이 종료될 때 어떤 함수를 등록할지 호출해준다!!
        // 내부적으로 함수 포인터의 리스트 목록을 가지고 있다.

    while (getchar() != '\n') {};

    printf("Goodbye message? \n");
    if (getchar() == 'y')
        atexit(goodbye);

    /*
        exit(0);
    */


    /*
        qsort();
    */

    return 0;
}
```


# 16-15. assert 라이브러리
---

디버깅을 할때 유용하게 사용할 수 있는 assert 라이브러리를 사용해보자.

```c


//#include <limits.h>
// _Static_assert(CHAR_BIT == 9, "9-bit char assumed");
// static assert는 컴파일 타임에서 잡아주는 assert이다.

int divide(int a, int b);

int main()
{

    int a, b;
    int f = scanf("%d%d", &a, &b);

    printf("a/b = %d", divide(a,b));

    return 0;
}



int divide(int a, int b)
{
    assert(b!=0);

    return a/b;
}

```

static assert는 VS에서 사용할 수 없고, C++에서 사용이 가능하다.

# 16-16. memcpy()와 memmove()
---

메모리의 내용을 카피하거나 이동하는 함수이다. string.h를 include하면 사용가능하다.

```c


#define LEN 6

void prt(int *arr, int n)
{
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    /*
    - overlapping region
    - pointer-to-void (datatype is unknown)
    */

   int arr1[LEN] = {1,3,5,7,9,11};
   // int arr2[LEN] = {0,  };

   int* arr2 = (int*)malloc(LEN * sizeof(int));
   if (arr2 == NULL) exit(1);

// case1: memcpy()를 사용하지 않고 for문을 돌면서 요소 하나하나 복사할 때
    for (int i = 0; i < LEN; i++)
    {
        /* code */
        arr2[i] = arr1[i];
    }

// case2: memcpy()를 이용해 메모리 자체를 복사!    
    //memcpy(void* destination,void* source, size_t)
    memcpy(arr2, arr1, sizeof(int)*LEN);
    prt(arr2, LEN);

    /*

    현재 arr1 => {1 3 5 7  9 11}
    바꾸고자 하는 aar1 => {5 7 9 11 9 11}

    - 다음과 같이 arr1을 바꾸고자 할때, [2]부터 [5]까지 바꾸게 된다. 이때 중간에 두 개의 원소가 겹치는데,
    - 이때 memcpy()를 쓰면 문제가 발생할 가능성도 있다고 한다.
    - 하지만, memmove() 같은 경우는 복사할 원소를 어떤 버퍼에 저장했다가 이후 이를 복사하는 방식이기 때문에 겹치는 구간이 있어도 문제가 생기지 않도록 구현했다고 한다.
    */

   // memcpy(arr1, &arr1[2], sizeof(int) * 4); //undefined behavior
   memmove(arr1, &arr1[2], sizeof(int)*4);
   prt(arr1, LEN);

   return 0;
}

```


# 16-17. 가변 인수(variable arguments)
---

함수가 받아들이는 인수가 그때그때 달라질 수 있는 가변 인수에 대해 알아보도록 하자.

C언어 함수 중 일부는 가변 인수로 이뤄져있다. 가변 인수를 사용하는 함수를 만들고 싶다면 **<stdarg.h>**를 include해야한다.

```c


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

```


