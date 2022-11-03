#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // strlen(), strcmp()
#include <string.h> // strcmp(string compare)
#include <stdlib.h> // malloc(), free()
#include <stdbool.h> // C99
#include <ctype.h>
#include <time.h>
//// 14-2

/* struct person{
        ...
    };
*/

// #define MAX 41

// struct person /* person is a tag of structure */
// {
//     char name[MAX];     // member
//     int age;    // member
//     float height;   // member
// };

// int main()
// {
//     int flag; //receives return value of scanf()

//     /* structure variable */

//     struct person genie;

//     /* dot(.) is structure membership operator(member access oprator, member operator) */

//     strcpy(genie.name, "Will Smith");
//     //strncpy(genie.name, "Will Smith")

//     genie.age = 1000;

//     // dot(.) has higher precedence than &
//     flag = scanf("%f", &genie.height); //&(genie.height)
//     printf("%f\n", genie.height);
    
//     /* Initialization */

//     struct person princess = { "Naomi Scott", 18, 160.0f};
//     struct person princess2 = {

//         "Naomi Scott",
//         18,
//         160.0f
//     };
    
//     strcpy(princess.name, "Naomi Scott");
//     princess.age = 18;
//     princess.height = 160.0f;
    
//     /* designated initializers */
//     // designated initializers는 이렇게 순서와 싱관없이 지정이 가능하게 해 준다.
//     struct person beauty = {
//         .age = 19,
//         .name = "Bell",
//         .height = 150.0f
//     };

//     /* pointer to a structure variable */
//     struct person* someone;

//     someone = &genie;
//     // someone = (struct Person*)malloc(sizeof(struct person)); // and free later

//     /* Indirect member(ship) operator (or structure pointer operator) */

//     someone -> age = 1001; // arrow operator
//     // 포인터일 경우에는 다음과 같이 화살표를 사용한다.  

//     printf("%s %d \n", someone -> name, (*someone).age);
//     // "(*someone).age"와 같이 indirection을 하고 접근을 할 수도 있다.
    
// }   

//// 14-3

// int main()
// {
//     /*
//         Well aligned structure
//     */

//    struct Aligned
//    {
//        int a;
//        float b;
//        double c;
//    };
   

//    /* 
//    |int a | float b | double c|
//     4 + 4 + 8 = 16
//     */

//    struct Aligned a1, a2;

//    /*
//     padding (struct member alignment)
//     - 1 word: 4 bytes in x86, 8 bytes in x64
//     */

//    struct Padded1
//    {
//        char a;
//        float b;
//        double c;
//    };

//    /* without padding: 빈 공간이 생기며, 효율성이 높지 않다.
//    | char a | float b | double c | ? ? ?
//    1 + 4 + 8 = 13
//     */

//    /* with padding: 기본 아이디어 -> 어차피 빈 공간이 생길 거라면, 줄을 맞춰서 연산 효율을 높이자.
//    | char a | float b | double c        |
//    4(char?) + 4 + 8 = 16
//    */


//     struct Padded2
//     {
//         float a;
//         double b;
//         char c;
//     };

//     /* size
//     | float a | double b | char c |
//     8(float?) + 8 + 8(char?) = 24
//     */

//     // padded1, padded2의 사이즈를 출력하면 각각 16, 24가 나온다.
//     // 자료형이 선언되는 순서만 달라져도 이렇게 비효율적이게 바뀔 수 있다.
//     // 이유: 컴파일러가 double b가 짤리지 않기 위해 양옆에 패딩을 넣어주기 때문

//     struct Padded3
//     {
//         char a;
//         double b;
//         double c;
//     };

//     /* size
//     | char a | double b | double c |
//     8(char?) + 8 + 8(char?) = 24
//     */

//    /* 구조체의 배열로 사용할 때 */

//    struct Person
//    { 
//         char name[41];
//         int age;
//         float height;    
//    };

//    struct Person mommy;

//    struct Person f[4];

//    printf("Sizeof a structure array %zd\n", sizeof(f)); 

//    /* 
//    | f[0].name              | f[0].age | ... |f[3].name | f[3].age |   f[3].height|
//    */

//   return 0;

// }


//// 14-04

// #define MAX_TITLE 40
// #define MAX_AUTHOR 40
// #define MAX_BOOKS 3 /* maximum number of books */

// char* s_gets(char* st, int n)
// {
//     char* ret_val;
//     char* find;

//     ret_val = fgets(st, n, stdin); // vs. scanf(): 빈칸을 받지 못함

//     if (ret_val)
//     {
//         find = strchr(st, '\n'); // look for newline
//         if (find)                // if the address is not NULL
//             * find = '\0';       // place a null character there
//         else
//             while (getchar() != '\n')
//                 continue; // dispose of rest of line
                
//     }

//     return ret_val;
// }

// struct book
// {
//     char title[MAX_TITLE];
//     char author[MAX_AUTHOR];
//     float price;
// };

// int main()
// {   
//     struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, }; // array of book structures */
//     int count = 0;
    

//     while (1)
//     {
//         printf("Input a book title or press [Enter] to stop/\n>>");
//         //TODO: input title
//         //TODO: break if the first character of the input title is '\0'
//         if( s_gets(library[count].title, MAX_TITLE) == NULL) break;
//         if ( library[count].title[0] == '\0') break;


//         printf("Input the author. \n>>");
//         //TODO: input author
//         s_gets(library[count].author, MAX_AUTHOR);        

    
//         printf("Input the price. \n>>");
//         // TODO: input price
//         // TODO: clear buffer
//         int flag = scanf("%f", &library[count].price);
//         while (getchar() != '\n')
//             continue; /* clear input line */

//         count++;

//         if (count == MAX_BOOKS)
//         {
//             printf("No more books.\n");
//             break;
//         }

//         if (count > 0)
//         {
//             printf("\n The list of books:\n");
//             for (int index = 0; index < count; index++)
//                 printf("\"%s\" written by %s: $%.1f\n",
//                 library[index].title, library[index].author, library[index].price );
            
//         }
//         else
//             printf("No books to show. \n");


//     }
//     return 0;
// }



//// 05

// #define LEN 20

// struct names {
//     char given[LEN]; //first name
//     char family[LEN]; //last name
// };

// struct reservation // Another structure
// {
//     struct names guest; // a nested structure
//     struct names host; // one more nested structure

//     char food[LEN];
//     char place[LEN];

//     // time
//     int year;
//     int month;
//     int day;
//     int hours;
//     int minutes;
// };


// int main(void)
// {
//     struct reservation res = {
//         .guest = {"Nick", "Carraway"},
//         .host = {"Jay", "Gatsby"},
//         .place = {"the Gatsby mansion"},
//         .food = {"Escargot"},
//         .year = 1925,
//         .month = 4,
//         .day =10,
//         .hours = 18,
//         .minutes = 30
//     };


// /* 
// TODO

// Dear Nick Carraway
// I would like to serve you Escargot.
// Please visit the Gastby mansion on 10/4/1925 at 18:30.
// Sincerly,
// Jay Gatsby
// */

//     printf("Dear %s %s\n", res.guest.given, res.guest.family);
//     printf("I would like to serve you %s.\n", res.food);
//     printf("Please visit %s on %d/%d/%d at %d:%d.\n", res.place, res.day, res.month, res.year, res.hours, res.minutes);
//     printf("Sincerly,\n%s %s", res.host.given, res.host.family);

//     return 0;

// }


//// 6,7,8

// #define NLEN 30

// struct name_count {
//     char first[NLEN];
//     char last[NLEN];
//     int num;
// };

// void receive_input(struct name_count*);
// void count_characters(struct name_count*);
// void show_result(const struct name_count*);
// char* s_gets(char* st, int n);

// int main()
// {
//     struct name_count user_name;

//     receive_input(&user_name);
//     count_characters(&user_name);
//     show_result(&user_name);

//     return 0;    
// }

// char* s_gets(char* st, int n)
// {
//     return "none";
// }

// void receive_input(struct name_count* ptr_nc)
// {
//     int flag;
//     printf("input your first name: \n >>");

//     //s_gets(ptr_nc->first, NLEN);
//     flag = scanf("%[^\n]%*c", ptr_nc->first);
//     // % 기호 뒤 대괄호 안에 ^\n의 의미는: "\n(줄바꿈)"이 나타날 때까지 입력을 받아라. // ^: cap operator
//     // *c의 의미는: c를 하나 무시해라.(줄바꿈 기호를 먹어버린다.)
//     // 결과적으로 사용자가 입력한 문자열에서 줄바꿈을 빼고 입력을 받아주게 된다.

//     if (flag != 1)
//         printf("wrong input");

//     printf("input your last name: \n >> ");

//     flag = scanf("%[^\n]%*c", ptr_nc->last);

//         printf("wrong input");

// }



// void count_characters(struct name_count* ptr_nc)
// {
//     ptr_nc->num = strlen(ptr_nc -> first) + strlen(ptr_nc -> last);
// }



// void show_result(const struct name_count* ptr_nc)
// {
//     printf("hi, %s %s. Your name has %d characters.\n",
//      ptr_nc->first, ptr_nc->last, ptr_nc->num);
// }


//// 9

// #define SLEN 81

// struct namect {
//     char* fname; // use malloc()
//     char* lname; // use malloc()
//     int letters;
// };

// void getinfo(struct namect*); // allocate memory
// void makeinfo(struct namect*); 
// void showinfo(const struct namect*); 
// void cleanup(struct namect*);  // free memory when done
// char* s_gets(char* st, int n);

// int main()
// {
//     struct namect p = { "jake" , "oh"};
//     /* recommended usage */

//     char buffer[SLEN] = {0, };
//     int f2 = scanf("%[^\n]%*c", buffer);
//     p.fname = (char*)malloc(strlen(buffer) + 1);
//     if (p.fname != NULL)
//         strcpy(p.fname, buffer);
//     printf("%s %s \n", p.fname, p.lname);


//     /* problem */
    
//     struct namect person;

//     getinfo(&person);
//     makeinfo(&person);
//     showinfo(&person);
//     cleanup(&person);


//     return 0;
// }


// char* s_gets(char* st, int n)
// {
//     return "none";
// }

// void cleanup(struct namect* pst)
// {
//     free(pst -> fname);
//     free(pst -> lname);
// }

// void makeinfo(struct namect* pst)
// {
//     pst -> letters = strlen(pst -> fname) + strlen(pst -> lname);
// }

// void showinfo(const struct namect* pst)
// {
//     printf("%s %s your name contains %d letters. \n",
//         pst-> fname, pst->lname, pst->letters);
// }


//// 15

// int main()
// {
//     /*
//         Union
//         - Store different data types in the same memory space
//         - structure vs Union
//         - 구조체와의 차이
//             - 구조체와 달리, data type이 다르더라도 메모리를 하나로 모아주어 같이 사용한다!
//     */

//     union my_union
//     {
//         /* data */
//         int i;
//         double d;
//         char c;
//     };
    

//     union my_union uni;

//     printf("%zd\n", sizeof(union my_union)); // 8: 가장 큰 데이터 타입을 따르게 된다!
//     printf("%lld\n",(long long)&uni);
//     printf("%lld %lld %lld \n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);
//     // 세 주소 모두 동일한 값이 나온다! 메모리를 공유하기 떄문

    

// }


//// 16, 17

// /*
//     unions and structures
// */

// struct personal_owner
// {
//     /* data */
//     char rrn1[7]; // Resident Registration Number
//     char rrn2[8]; // ex: 981119-1230988
// };

// struct company_owner
// {
//     /* data */
//     char crn1[4]; // company registration number
//     char crn2[3]; // ex: 111-22-33333
//     char crn3[6];
// };





// struct car_data
// {
//     /* data */ 
//     char model[15];
//     int status; /* 0 = personal, 1 = company */
//     union {
//     /* data */
//     struct personal_owner   po;
//     struct company_owner    co;
//     // personal owner와 company owner 모두인 경우는 없다!!
//     };
// };

// void print_car(struct car_data car)
// {
//     printf("------------------------- \n");
//     printf("Car model : %s \n", car.model);

//     if ( car.status == 0)
//         printf("Personal owner : %s - %s \n",
//             car.po.rrn1, car.po.rrn2);
//     else
//         printf("company owner : %s - %s - %s \n",
//         car.co.crn1, car.co.crn2, car.co.crn3);

//     printf("------------------------- \n");

    
// }


//// 18

/** Motivation
CASE1)
int c= 0; // red:0, orange:1, yellow:2, green:3, ...
if ( c== 2)
    printf("yellow");
// 각각의 색들이 정수 자료형에 대응된다고 생각하고 대응을 해주는 것이 필요하다.
// 색이 더 다양해지면 가독성이 더 줄어들고, 유지보수가 힘들어진다.
*/

/*
CASE2) define -> symbolic constant 교체
- 이들은 컴파일러 입장에서 볼때 yellow가 나타나면 3을 복사해서 붙여넣기를 해준다.
- 이는 기계적으로 값들을 변환하여 교체해버리는 것이다. 
- 따라서, 컴파일러 타임에서 오류를 잡아줄 수 있는 게 없다.

#define RED 1
#define ORANGE 2
#define YELLOW 3

int c = YELLOW;
if (c ==YELLOW)
    pirntf("yellow");
 */

/*
CASE 3) 따라서 열거형을 이용하여 프로그래밍을 조금 더 편하게 할 수 있다.
*/

// int main()
// {
//     /*
//         Enumerated type
//         - Symbolic names to represent integer constants
//         - Improve readability and make it easy to maintain
//         - enim-specifier (struct-specifier, union-specifier)

//         Enumerators
//         - The symbolic constants
//     */

//     enum spectrum {red, orange, yellow, green, blue, violet}; // 이들은 내부적으로는 정수이다.

//     enum spectrum color;
//     color = blue;

//     if (color  == yellow)
//         printf("yellow"); // note: enumerates are not strings

//     for (color = red; color <= violet; color++) // NOTE: ++ operator doesnt allowed in C+++, use type int.
//         printf("%d\n", color);


//     printf("red = %d, orange = %d\n", red, orange);

//     enum kids {jackjack, dash, snoopy, nano, pitz};
//     // nina has a value of 3
//     enum kids my_kid = nano;
//     printf("nano %d %d \n", my_kid, nano);

//     enum levels { low = 100, medium = 500, high = 2000};

//     enum pet { cat, dog = 10, lion, tiger};
//     // puma has a value of 11
//     printf("cat %d \n", cat);
//     printf("lion %d\n", lion);

//     return 0;


// }

 
//// 19 열거형 연습문제

//// 20

// int iamfunction{
//     return 0;
// }

// int main()
// {
//     /* 
//         Namespace
//         - Identify parts of a program in which a name is recognized
//         - You can use the same name for one variable and on tag.
//         - C++: use 'namespace' to use the smae identifiers in the duplicated scopes.
//     */

//    {
//        int myname = 345;
//        // double myname = 3.14; //ERROR
//    }

//     struct rect { double x; double y;};

//     // int rect =123; // OK in C(but not ok in C++)
//     struct rect rect = {1.1, 2.2}; // struct rect and rect are in different categories

//     /*
//         typedef struct rect rect;
//         rect rect = {1.1, 2.2}; // NOT ok
//     */

//    // int iamfunction = iamfunction(); // error

//    /*
//         Namespace pollution(KNK p.465)
//         - Names in different files accidentally conflicting with each other
//         - 외울 필요는 없지만, 프로그램을 작성하다보면 한 번씩 겪게 될 일이다.
//     */

//    // printf("%d \n", a); // other.c

//    return 0;
// }


//// 21 22



// void ToUpper(char* str)
// {
//     while (*str)
//     {
//         *str = toupper(*str);
//         str++;
//     }
// }

// void ToLower(char* str)
// {
//     while (*str)
//     {
//         *str = tolower(*str);
//         str++;
//     }
// }

// void UpdateString(char* str, int (*pf)(int)) // 함수와 여기에 사용될 함수 자체를 파라미터로 받는다. 
// // 함수 포인터를 통해 기능을 구현할 함수 포인터를 매개변수로 받는다. 그 포인터를 통해 뭔가를 실행시킨다.
// {
//     while (*str)
//     {
//         *str = (*pf)(*str); // 이 줄만 다른 함수와 다르다!!
//         str++;
//     }
// }

// int main()
// {
//     char str[]  = "Hello, world!";

//     void (*pf)(char*);

//     pf = ToUpper; // Name of a function is a pointer
//     // pf = &ToUpper; // Acceptable
//     // pf = ToUpper(str); // Not acceptable in C

//     printf("string literal %lld\n", (long long)("hello world"));
//     printf("Function pointer %lld\n", (long long)ToUpper);
//     printf("Variable %lld\n", (long long)str);

//     (*pf)(str);
//     //pf(str);// K&R X, ANSI OK

//     printf("ToUpper %s \n", str);

//     pf = ToLower;

//     pf(str);

//     printf("ToLower %s\n", str);

//     /* 
//         Passing function pointers to funtions
//     */

//    UpdateString(str, toupper);

//    printf("ToUpper %s \n", str);

//    UpdateString(str, tolower);

//    printf("ToLower %s\n", str);

//    // NOTE: __cdecl is function calling convention
//    // 함수 포인터를 선언할 때 // 함수 호출 규약에 대해 추후 공부하게 될 것(windows API 할때 알 것)

//    return 0;
    

// }

//// 23


// // 조금 더 복합하게 typedef를 사용할 때는 어떻게 하는지 살펴보자.

// /* 
//     One good way to synthesize declarations is 
//     in small steps with typedef, ...
//     - K&R book chapter 5.12
// */

// /* Complicated Function Declarations *//

// char char3[3] = { 'A', 'B', 'C'};

// char(*complicated_function1())[3] // function returns pointer To Char[3]
// {
//     return &char3; // Returns a pointer to char[3] array
// }

// // case1: typedef를 사용하지 않은 경우
// char(*(*fptr1)())[3] = complicated_function1;
// //// 복잡함을 알 수 있다.

// // case2: typedef를 사용한 경우
// typedef char(*FRPTC())[3]; // Function Returns Pointer to char[3]
// typedef char(*(*PFRPTC())[3]; 

// FRPTC3 *fptr2 = complicated_function1;
// PFRPTC3 fptr3 = complicated_function1;

// //// 다음과 같이 아주 간결하게 사용할 수 있다.


// //// 여기서 더욱 간단하게 이용할 수도 있는데, 다음과 같이 이용하면 된다.
// /* Use typedef to make declarations simpler */

// typedef char c3[3]; // 이렇게 typedef [3] 으로 선언해준다.

// c3* complicated_function2() // 그러면 다음과 같이, 아주 간단하게 선언할 수 있다.
// {
//     return &char3; // Returns a pointer to char[3]
// }



// int main()
// {
//     /* 
//         typedef specifier
//         - Give symbolic names (or aliases) to types
//             - 어떠한 자료형을 새로운 이름으로 다시 정의해준다.
//         - Doesn't create new types.
//             - 주의: 이름만 바꿔주는 것이지, 새로운 자료형을 만드는 것은 아니다!
//         - 
//     */

//    typedef unsigned char BYTE; // note the scope of BYTE
//     // 다음과 같이 긴 길이의 타입을 계속 사용할 때 편리하다.

//    BYTE x, y[10] = {0, }, * z = &x;

//    {
//        typedef unsigned char byte; // You can use lowercases as well.

//         /* Portable data types */
        
//         size_t s = sizeof(byte); // unsigned int (x86), unsigend long long (x64)
//         // unsigned int s = sizeof(byte); // x86
//         // unsigned long long s = sizeof(byte) // x64

//    }

//    // byte b; // typedef definition has a scope 

//    /*
//         This function returns the time since 00:00:00 UTC, January 1, 1970 (unit timestamp)
//         in seconds.
//     */

//    time_t t = time(NULL);

//    printf("%lld \n", t);

//    /*
//         typedef vs #define
//     */

//    typedef char* STRING;

//    STRING name = "John wick", sign = "world";

//    /*
//         - typedef interpretation is performed by the complier, not the preprocessor
//             - define은 전처리에 의해 처리됨(복사 붙여넣기로 처리됨) 
//             - typedef는 컴파일러에 의해 전처리됨
//         - More flexible than #define

//         #define STRING char*

//         SRTING name, sign;
//         char * name, sign; // Note the type of sign
//         //// 문제점: 이렇게 되면 문법 상 sign은 포인터가 아니게 된다!

//     */

//     typedef struct complex {
//         float real;
//         float imag;
//     } COMPLEX; // typedef struct complex COMPLEX

// }

//// 24. 복잡한 선언을 해석하는 요령

int main()
{

    /* 
    흔히들 아래 3가지 유형의 조합으로 복잡해진다.
        - *   indicates a pointer
        - ()  indicates a function
        - []  indicates an array
    */

   /* Deciphering Complex Declarations (KNN 18.4)
       - Always read declarations from the inside out.
       - 중요: When there's a choice, always favor [] and () over *(asterisk)/
    */

   int* ap[10]; // Identifier ap is an array of pointers

   typedef int* pint;
   pint ap2[10];

   float* fp(float); // fp is a function that returns a pointer

   typedef float* pfloat;
   pfloat fp2(float);

    void (*pf)(int);
    /*
        void (*pf)(int);
              1             1. pointer to
                    2       2. function with int argument
        3                   3. returning void
    */

   int* (*x[10])(void);
   /*
        int* (*x[10])(void);
                1           1. array of
              2             2. pointers to
                        3   3. functions with no arguments
        4                   4. returning pointer to int
    */

   /* A function can't return an array */
    // int f(int)[]; // wrong!

   /* BUT it can return "a pointer to an array" */
   int(*f(int))[];

    /* A function can't return a function */
    // int g(int)(int); // Wrong!

    /* BUT it can return a pointer to a function */
    int (*g(int))(int);

    /* An array of functions aren't possible */
    // int a[10](int); // Wrong!

    /* BUT an array of function pointers are possible */
    int (*x2[10])(int);

    /* Using typedef to simplify declarations */

    typedef int FCN(int);   // int type
    typedef FCN* FCN_PTR;   // pointer
    typedef FCN_PTR FCN_PTR_ARRAY[10]; // Array
    FCN_PTR_ARRAY x3; // x3 has same type with x2

}