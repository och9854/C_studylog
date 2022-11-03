#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* int main()
{
    for (int n=1, nsqr = n*n; n<10; n++, nsqr = n*n) // 하나의 expression 내에 두 가지 기능을 수행할 수 있다!!
    printf("%d %d \n", n, nsqr);
} */

/* int main()
{
    int i, j;
    i = 1;
    i++, j = i; // comma is a sequence point -> i++ is operated before comma
    printf("%d %d \n", i, j);

}
 */

// int main()
// {
//     /*  Simulatino of Moving object */

//     const double speed = 1.0;
//     const unsigned repeat_max = 7; // 최대 반복 횟수는 보통 양의 정수이기때문에 함(걍 int써도 됨)
    
//     double dt = 1.0;
//     double time = 0.0; // Elapsed time
//     double dist = 0.0; // Distance

//     for (unsigned i =0 ; i < repeat_max; ++i){

//         dist += speed * dt ;
//         time += dt;

//         printf("Elapsed time = %.10fs, Distance = %.10fm \n", time, dist);

//         // Half time step
//         // dt = dt / 2.0 ; // 제일 먼저 떠오르는 것일 것
//         dt *= 0.5; //But multiplication is faster than deviding

//     }

//     return 0;

// }


// main()
// {
//     int pw = 1234;
//     int input = 0;
//     printf("input your password: ");
//     scanf("%d", &input);

//     while (pw != input)
//     {
//         printf("password wrong! please type it again \n");
//         printf("input your password: ");


//         scanf("%d", &input);

//     }
    
//     printf("Login Successed");
//     return 0;

// }


// int main()
// {
//     const int secret_code = 1234;
//     int input =0;

//     do
//     {
//         printf("Enter your secret_code  \n");
//         scanf("%d", &input);
//     }
//     while (secret_code !=  input);

//     printf("GOOD JOB!");


// }

/* #define NUM_ROWS 5
#define FRIST_CHAR 'A'
#define LAST_CHAR 'K'
    
int main()
{
    int r; // row loop
    int c; // character loop

    for (r=0; r < NUM_ROWS; r++) // outer loop
    {
        for (c = FRIST_CHAR; c <= LAST_CHAR; c++)
            printf("%c ", c);
        printf("\n");


    }
}
 */



/* #define NUM_ROWS '10'
#define FRIST_CHAR 'A'
    
int main()
{
    int r; // row loop
    int c; // character loop

    for (r=0; r < NUM_ROWS; ++r) // outer loop
    {
        for (c = FRIST_CHAR; c <= FRIST_CHAR + r ; ++c)
            printf("%c ", c);
        printf("\n");

    }

    return 0;
} */


/* #define NUM_DAYS 365
int main()
{
    char my_chars[] = "Hello, world!";

    int daily_temprature[NUM_DAYS];
    double stock_prices_history[NUM_DAYS];

    printf("%zd \n", sizeof(stock_prices_history));
    printf("%zd \n", sizeof(double) * NUM_DAYS);
    printf("%zd \n", sizeof(stock_prices_history[0]));

} 

 */

//// 6-17

/* #define SIZE 5
int main()
{
    int my_arr[SIZE];


    //prepare for array data
    for (int i =0; i < SIZE; ++i)
        my_arr[i] = i * i;
        1+2; // dummy for debugger: easy to follow changes

    //print array dta
    for (int i= 0; i< SIZE; ++i)
        printf("%d ", my_arr[i]);

    //TODO: try debugger




    return 0;
} */



//// 6-18

// int main()
// {

//     int base, exp, i, result;
//     scanf("%d %d", &base, &exp);

//     result = 1;
//     for (i =0; i< exp; ++i)
//     {
//         result *= base;
//     }

//     printf("Result = %d \n", result);

//     return 0;

// }


//// To function

int compute_pow(int base, int exp); //prototype 

int main()
{
    int base, exp, result;

    printf("test \n");
    
    while (scanf("%d %d", &base, &exp) == 2)
    {

        result = compute_pow(base, exp);

        printf("result = %d \n", result);
    }

    return 0;
}

int compute_pow(int base, int exp) //prototype 
{   
    int i, result;

    result = 1;

    for (i =0; i < exp; ++i)
        result *= base;

    return result;
}