#define _CRT_SECURE_NO_WARNINIGS
#include <stdio.h>

//// 10-01. array, memory
//// 10-02. 배열의 기본적인 사용방법

// #define MONTHS 12 //symbolic constant, macro

// int main()
// {

//     int high[MONTHS] = {2,5,11,18,23,27,29,30,26,20,12,4};

//     // Address

//     printf("%p %p \n", high, &high[0]);
//     for (int i =0; i < MONTHS; ++i)
//         printf("%lld \n", (long long)&high[i]); // 10진수로 출력하여 4씩 증가하는지 확인(int이므로)
//     printf("\n");

//     ///* complier doesn't check whether indices are valid!! */
//     // high[12] = 4; //compiler는 에러를 출력하지 않는다!! -> 나중에 Runtime Error를 발생시킴

//     /* const and array */
//     const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};
//         // low[]를 바꾸지 못하게 할 수 있다!!

//     /* omitting size */
//     const int power_of_tons[] = {1,2,4,8,16,32,64}; // 다음과 같이, []내에 수를 지정하지 않더라도 컴파일러가 이를 count해준다.
//     printf("%d \n", sizeof(power_of_tons));         // 하지만 동적할당에서는 이렇게 하면 안된다!
//     printf("%d \n", sizeof(int));
//     printf("%d \n", sizeof(power_of_tons[0]));

//     for (int i =0; i< sizeof power_of_tons / sizeof power_of_tons[0]; ++i)
//         printf("%d ", power_of_tons[i]);

//     printf("\n");

//     /* Designated initalizers */

//     int days[MONTHS] = {31,28, [4] = 31,30,31}; // array의 첫번째 값을 29로 지정해줄 수 있다! // 지정되지 않은 값들은 0으로 채워진다.
//     for (int i = 0; i<MONTHS; ++i)
//         printf("%d ", days[i]);
    
// }

//// 10-3

// int main()
// {
//     int* ptr= 0; // try double*, long long*, char*, void*
//     // 원래는 NULL을 넣는 것이 맞지만, 이번 강의에서 포인터의 이해를 돕기 위해 0으로 지정함. 추후에 와닿을 것
//     // 절대 평소에는 0을 넣지 말것

//     printf("%p %lld \n", ptr, (long long)ptr);

//     ptr ++; //try -=, ++, --, -, +
//     // 1이 아니라! 자료형의 사이즈만큼 더해주게 된다!!
//     // 즉, 주소값에 어떤 값을 더해주는 게 아니라 자료형에 맞춰서 건너뛰어간다는 의미가 크다

//     printf("%p %lld \n", ptr, (long long)ptr);

//     // 단항연산자는 작동하지 않는다!!
//     //ptr = -ptr; 주소의 값을 음수로 바꾼다는 것 자체가 의미가 없다
//     //ptr = +ptr;

//     /*substraction*/
//     double arr[10];
//     double* ptr1= &arr[3], * ptr2 = &arr[5];

//     // ptr2 = ptr1 + ptr2; //not working: cannot add two pointer
//     int i = ptr2 - ptr1; //working -> meaning: 두 메모리 주소 차이가 두 칸이라는 것!! 
//     // e.g. 아파트 301호와 303호 비교하기

//     printf("%lld %lld %d \n", (long long)ptr1, (long long)ptr2, i);
//     // 메모리 주소간 차이는 16 -> double은 8 -> 16 / 8 = 2라는 결과가 나옴(주어진 주소값에 인덱스 차이가 2)

//     return 0;

     
// }

//// 10-4

// int main()
// {
//     int arr[10];
//     int num = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < num ; ++i)
//         arr[i] = (i+1)*100;

//     int* ptr = arr;

//     printf("%p %p %p \n", ptr, arr, &arr[0]); // 세 값이 같음!

//     ptr += 2;

//     printf("%p %p %p \n", ptr, arr+2, &arr[2]); // arr+2 = &arr[2] 값 동일!

//     // Note : arr += 2; // invalid

//     printf("%d %d %d\n", *(ptr+1), *(arr+3), arr[3]); // All the same

//     // warning
    
//     //printf("%d %d %d \n", *ptr + 1, *arr + 3, arr[3]); // 301, 103, 400 // they are all different!!

//     //

//     for (int i = 0, *ptr = arr; i<num; ++i)
//     {
//         printf("%d %d \n", *ptr++, arr[i]);
//         // printf("%d %d \n", *(ptr + i), arr[i]); // 위 식과 동일함

//     }

// }

//// 10-5

// int main()
// {
//     int arr[2][3] = {{1,2,3},
//                      {4,5,6}};

//     // for (int j =0; j < 2; ++j)   
//     // {
//     //     for (int i = 0; i<3; ++i)
//     //         printf("%d ", arr[j][i]);

//     //     printf("\n");
//     // }
//     // printf("\n");

//     //Note : inner loop uses i. why?

//     int *ptr = &arr[0][0];
//     for (int k =0; k< 6; ++k)
//         printf("%d ", ptr[k]);

//     printf("\n\n");

//     printf("%zd %zd \n", sizeof(arr), sizeof(arr[0]));
//     printf("\n");

//     /* 3D array */
//     int arr_3d[2][3][4] = {
//                             {
//                                 {000, 001, 002, 003},
//                                 {010, 011, 012, 013},
//                                 {020, 021, 022, 023},
//                                                         },
//                             {
//                                 {100, 101, 102, 103},
//                                 {110, 111, 112, 113},
//                                 {120, 121, 122, 123},
//                                                         },
//                                                             };

//     for (int k=0; k<2; ++k)                                                            
//     {
//         for (int j = 0; j<3; ++j)
//         {
//             for (int i =0; i<4; ++i)
//                 printf("%d ", arr_3d[k][j][i]);
//             printf("\n");
//         }
//         printf("\n");
        
//     }

//     return 0;

// }

//// 10-6 2차원 배열 연습문제

// #define MONTHS 12
// #define YEARS 3

// int main()
// {
//     double year2016[MONTHS] = {1,2,3,4,5,6,7,8,9,10,11,12};
//     double year2017[MONTHS] = {13,14,15,16,17,18,19,20,21,22,23,24};
//     double year2018[MONTHS] = {25,26,27,28,29,30,31,32,33,34,35,36};

//     /* Your code */
//     // 1. Use 2D array
    
//     int year_all[YEARS][MONTHS] = {
//         {1,2,3,4,5,6,7,8,9,10,11,12},
// {13,14,15,16,17,18,19,20,21,22,23,24},
// {25,26,27,28,29,30,31,32,33,34,35,36},
//     };

//     // 2. Print array
//     printf("[Temperature Data]\n");
//     printf("Year Index: ");
    
//     for (int i = 1 ; i <= MONTHS; ++i)
//     {
//         printf("\t%d ", i);
//     }   
//     printf("\n");

//     for (int y = 0; y < YEARS; ++y)
//     {
//         printf("Year %d     : ", y);
//         for (int m= 0; m < MONTHS; ++m)
//         {
//             printf("\t%.1d ", year_all[y][m]);
//         }
//         printf("\n");
//     }

//     // 3. yearly avg temperatures of 3 years
//     printf("[Yearly average temperatures of 3 years] \n");
//     for (int y=0; y<YEARS; ++y)
//     {
//         double avg_temp = 0.0;

//         for (int m= 0; m < MONTHS; ++m)
//             avg_temp += year_all[y][m];
        
//         avg_temp /= (double)MONTHS;
//     }    
//     printf("\n");

//     // 4. Monthly avg temperatures for 3 years
//     printf("[Monthly average temperatures for 3 years]\n");
//     printf("motth index : ");

//     for (int m = 0; m < MONTHS; ++m)
//     {
//         printf("\t%d ", m + 1);
//     }
//     printf("\n");

//     printf("avg temps   : ");
//     for (int m = 0; m<MONTHS; ++m)
//     {
//         double avg_temp = 0;
//         for (int y=0; y < YEARS; ++y)
//         {
//             avg_temp += year_all[y][m];
//         }
//         avg_temp /= (double)YEARS;
//         printf("\t%.1f ", avg_temp);
//     }
//     printf("\n");


// }


//// 10-07. 배열을 함수에게 전달해주는 방법

// double average(double * data_array, int n) // 함수에서는 배열로 받는 게 아니라 포인터로 받는다!! // arr size도 함께 받아야 함!
// {
//     printf("size = %zd in function average\n", sizeof(data_array));

//     double avg = 0.0;
//     for (int i =0; i < n; ++i) // arr의 수만큼 돌림!
//     {
//         avg += data_array[i];
//     }
//     avg /= (double)n;
    
//     return avg;
// }

// int main()
// {
//     double arr1[5] = {10, 13, 12, 7, 8};
//     double arr2[3] = {11, 12, 12};

//     printf("Address = %p\n", arr1);
//     printf("Size = %zd\n", sizeof(arr1));
 
//     printf("Address = %p\n", arr2);
//     printf("Size = %zd\n", sizeof(arr2));

//     printf("Avg = %.1f\n", average(arr1, 5));
//     printf("Avg = %.1f\n", average(arr2, 3));

// }

////  10-08. 두 개의 포인터로 배열을 함수에게 전달하는 방법

// double average(double* start, double* end)
// {
//     int count = end - start; //앞서 배웠듯이, end와 start 차이는 인덱스가 몇 칸 차이인지를 나타낼 수 있다.
//     double avg = 0.0;
//     while (start < end)
//     {
//         avg += *start++;
//         //count++;
//     }
//     avg /= (double)count;

//     return avg;
// }

//// 10-09. 포인터 연산 총정리
////  10-10. const와 배열과 포인터

// int main()
// {
//     // type qualifiers: const, volatile

//     const double PI = 3.14159;
//     //PI = 2.14159; // Error because of const qualifier

//     const int arr[5] = {1, 2, 3, 4, 5}; // 배열 "각각의 원소"를 바꿀 수 없게 된다.
//     //arr[1] = 123;

//     const double arr2[3] = {1.0, 2.0, 3.0};
//     //arr2[0] = 100.0;

//     const double * pd = arr2;
//     //*pd = 3.0;      //same with : pd[0] = 3.0 ; arr2[0] = 3.0;
//     // 다음과 같이 derefencing을 하고 3을 집어넣게 된다면, pd의 주소 자체는 arr2의 첫 번째 주소를 가리키기 때문에 수정이 된다.

//     //pd[2] = 1024.0; //same with : arr2[2] = 4.0;
//     // 여기서 에러가 날 것이다. 왜냐하면 *pd가 const이기 때문에 값을 바꿔주지 못하기 때문이다.

//     printf("%f %f \n", pd[2], arr2[2]);

//     pd++; // allowed: 변수 내의 원소값을 바꿀 수는 없지만, 주소값은 바꿀 수 있다.

//     printf("%f %f \n", pd[2], arr2[2]); // 참조할 원소 인덱스가 없기 때문에 0.00000이라는 이상한 값이 나온다!

//     return 0;
// }

//// 10-11. 배열 매개변수와 const

// void print_array(const int arr[], const int n)
// {   
//     for (int i =0; i < n; ++i)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// void add_value(int arr[], const int n, const int val)
// {
//     int i;
//     for (i =0; i < n; i++)
//         arr[i] += val;
// }

// int sum(const int ar[], const int n) // 여기 배열에 const를 붙여주게 되면 아래에서 배열값을 바꾸는 실수를 잡아줄 수 있다!
// {
//     int i;
//     int total = 0;
//     for ( i= 0; i<n; i++)
//         total += ar[i];
    
//     return total;
// }


// int main()
// {
//     int arr[] = {1,2,3,4,5};
//     const int n = sizeof(arr)/sizeof(arr[0]);

//     print_array(arr, 5);
//     add_value(arr, 5, 100);
//     print_array(arr, 5);

//     int s = sum(arr, n);

//     printf("sum is %d \n", s);
//     print_array(arr, 5);

//     return 0;
// }

//// 10-12. 포인터에 대한 포인터(2중 포인터)의 작동원리

//// 10-13. 포인터의 배열과 2차원 배열

// int main()
// {
//     /* Two of 1D arrays */

//     int arr0[3] = {1,2,3};
//     int arr1[3] = {4,5,6};

//     int* parr[2] = {arr0, arr1}; // an array of pointers

//     for (int j=0; j<2; ++j)
//     {
//         for (int i = 0; i<3; ++i)
//             printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), (*(parr + j))[i] ); // all same
//         printf("\n");
//     }
//     printf("\n");


//     /* 2D arrays are arrays of 1D arrays */

//     int arr[2][3] = { {1,2,3}, {4,5,6}};

//     int *parr0 = arr[0];
//     int *parr1 = arr[1];

//     for (int i =0; i<3; ++i)
//         printf("%d ", parr0[i]);
//     printf("\n");
    
//     for (int i =0; i<3; ++i)
//         printf("%d ", parr1[i]);
//     printf("\n");

//     /* arrays of pointers works like a 2D array */

//     //int* parr[2] = { arr[0], arr[1]};

//     for (int j=0; j<2; ++j)
//     {
//         for (int i = 0; i<3; ++i)
//             printf("%d %d %d %d\n",
//                     arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j)+i) );
//         printf("\n");
                   
//     }

//     printf("\n");




//     ///* Notes
//     // - parr[0] and parr[1] do not point valid memory by default
//     // - &parr[0] != &arr[0]
//     // - &parr[0] != parr[0] but &arr[0] = arr[0]
//     //*/

//     int arr[2][3] = { {1,2,3}, {4,5,6}};

//     int* parr[2]; 
//     parr[0] = arr[0];
//     parr[1] = arr[1];

//     printf("%p \n", &parr[0]); //different! //point array 자체 주소 
//     printf("\n");
    
//     // 아래 5개의 printf의 결과값은 동일하다
//     printf("%p \n", parr[0]); 
//     printf("%p \n", arr); // 배열의 이름은 첫번째 원소의 주소인 것처럼 사용할 수 있다. 
//                             //하지만, 주소를 저장하는 별도의 메모리를 가지지는 않는다.
//     printf("%p \n", &arr[0]);
//     printf("%p \n", arr[0]); 
//     printf("%p \n", &arr[0][0]);




//     /* array of string of diverse lengths example */

//     char* name[] = {"Aladdin", "Jasmine", "Magic carpet", "Genie"};

//     const int n = sizeof(name) / sizeof(char*); // pointer의 변수에 4개의 원소가 담겨있고, 그 4개가 각 문자열의 첫번째 주소를 가리킨다.

//     for (int i=0; i<n; ++i)
//         printf("%s at %llu \n", name[i], (unsigned long long)name[i] ); //Use ull in x64 build
//     printf("\n");

//     char aname[][15] = {"Aladdin", "Jasmine", "Magic carpet", "Genie", "Jafar"};

//     const int an = sizeof(aname)/sizeof(char[15]); //앞과 다르게 포인터가 아니며, 메모리 사이즈가 이미 정해져 있는 경우

//     for (int i=0; i< an; ++i)
//         printf("%s at %llu \n", aname[i], (unsigned long long)aname[i] ); //Use ull in x64 build
//         // char 15만큼 메모리르 할당하여 사용한다.
//     printf("\n");
// }


//// 10-14. 2차원 배열과 포인터

// int main()
// {
    // float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

    // printf("%llu \n", (unsigned long long)arr2d); // use ull in x64
    // printf("%llu \n", (unsigned long long)arr2d[0]);
    // printf("\n");
    
    // // arr2d points to arr2d[0] (not arr2d[0][0])
    // // 배열의 이름이 주소를 가리킨다는 것은 알고 있을 것이다. arr2d[0](주소)와 arr2d[0][0](값)의 주소가 같다
    // // 하지만 개념,문법상 arr2d가 가리키는 것은 "arr2d[0]"이라는 것을 짚고 넘어가자!

    // printf("%llu \n", (unsigned long long)* arr2d);
    // printf("%llu \n", (unsigned long long)& arr2d[0]);
    // printf("%llu \n", (unsigned long long)& arr2d[0][0]);
    // printf("%f %f \n", arr2d[0][0], **arr2d);
    // printf("\n");

    // printf("%llu \n", (unsigned long long)(arr2d+ 1) );
    // printf("%llu \n", (unsigned long long)(&arr2d[1]) );
    // printf("%llu \n", (unsigned long long)(arr2d[1]) );
    // printf("%llu \n", (unsigned long long)(*(arr2d+ 1)) );
    // printf("%llu \n", (unsigned long long)( &arr2d[0]+ 1) );
    // printf("%llu \n", (unsigned long long)( &arr2d[1][0]) );
    // printf("\n");

    // printf("%f \n", *(*(arr2d+1) + 2) ); //7.0000
    // printf("\n");

    // for (int j = 0; j<2; ++j)
    // {
    //     printf("[%d] = %llu, %llu \n", j, (unsigned long long)(arr2d[j]), (unsigned long long) * (arr2d+j));
    //     for (int i = 0; i< 4; ++i)
    //     {
    //         printf("[%d][%d] = %f, %f \n", j,i, arr2d[j][i], *(*(arr2d+j)+i));
            
    //         *(*(arr2d+j)+i) += 1.0f; // arr2d[j][i] += 1.0f;
    //     }
    // }
    // printf("\n");  


// }


//// 10-15 

// int main()
// {
    /* pointer Compatibility */

    // int n =5;
    // double x;
    // x = n; //no error
    // int* p1 = &n;
    // double* pd = &x;
    // //pd = p1; // Warning!! -> Type이 맞지 않음! 절대 권장하지 않음

    // int* pt;
    // int(*pa)[3];
    // int ar1[2][3] = {3,};
    // int ar2[3][2] = {7,};
    // int** p2; // a pointer to a pointer

    // pt = &ar1[0][0]; //pointer to int
    // pt = ar1[0]; // pointer to int
    // //pt = ar1; // warning(error)
    
    // p2 = &pt; // pointer to int * // 이중포인터이기 때문에, "포인터의" 주소를 담을 수 있다.
    // *p2 = ar2[0]; //pointer to int
    // //p2 = ar2; // warning(error)

    // // Notes 
    // // - p2: pointer to pointer to int
    // // - ar2: a pointer to array-of-two-ints


    /* pointer and const */

    // int x = 20;
    // const int y = 23;
    // const int* p1 = &x;
    // const int* p2 = &y;
    // const int** pp2 = &p1;
    //p1 = p2; // warning error!

    //*p2 = 123; // Error: 이는 const인 y의 값을 바꾸려는 행위와 동일하기 때문!
    //p2 = p1;

    // int x2 = 30;
    // int* p3 = &x2;
    // *pp2 = p3;
    // pp2 = &p1;

    /* another example */

    // const int** pp2;
    // int* p1;
    // const int n = 13;
    // pp2 = &p1; // const?
    // *pp2 = &n; // sets p1 to point at n
    // *p1 = 10;   //change n 

    
// }

//// 10-16. 다차원 배열을 함수에게 전달해주는 방법

// #define ROWS 3
// #define COLS 4

// int sum2d_1(int ar[ROWS][COLS]);
// int sum2d_2(int ar[][COLS], int row);
// int sum2d_3(int* ar,int row, int col);

// int main()
// {
//     int data[ROWS][COLS] = {
//                                 {1,2,3,4},
//                                 {5,6,7,8},
//                                 {9,0,1,2}
//     };

//     printf("%d\n", data[2][3]);

//     int* ptr = &data[0][0];
//     printf("%d\n", *(ptr+3+ COLS*2));

//     printf("Sum of all elements = %d\n", sum2d_1(data));
//     printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
//     printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));


// }

// int sum2d_1(int ar[ROWS][COLS])
// {
//     int r, c, tot = 0;
//     for (r=0; r< ROWS; r++)
//         for (c =0; c<COLS; c++)
//             tot += ar[r][c];
//     return tot;
// }

// int sum2d_2(int ar[][COLS], int row)
// {
//     int r, c, tot = 0;
//     for (r=0; r< row; r++)
//         for (c =0; c<COLS; c++)
//             tot += ar[r][c];
//     return tot;
// }

// int sum2d_3(int* ar,int row, int col) // row, col을 변수로 넘겨주고 있기 때문에, 심볼릭 필요없음
// {
//     int r, c, tot = 0;
//     for (r=0; r< row; r++)
//         for (c =0; c<col; c++)
//             tot += *(ar + c + col*r); // ar[c + col*r]
//     return tot;
// }

// /* 
//     In higher dimensions, 
//     You may omit the value in the left-most breacket

//     int my_function(int ar[][3][5][8], int rows);
//     int my_function(int (*ar)[][3][5][8], int rows);
//     // 고차원 배열의 경우 다음과 같이 넣어준다. 가장 높은 차원은 주로 비워둔다.
// */

//// 10-17

// int main()
// {
//     int n;

//     printf("Input array length:");
//     scanf("%d", &n);

//     float my_arr[n]; // note: cannot change length after declaration

//     for (int i = 0; i<n;++i)
//         my_arr[i] = (float)i;

//     for (int i= 0; i<n; ++i)
//         printf("%f\n", my_arr[i]);

// }

//// 10-18. 복합 리터럴과 배열 (Compound Literals)

