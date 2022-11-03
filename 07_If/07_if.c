// 7-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

/* int main()
{
    int number;

    printf("input a positive integer : ");
    scanf("%d", &number);

    // Todo: print even or odd

    if (number % 2 ==0)
        printf("Even");

    else if (number % 2 != 0)
        printf("ODD");

    return 0;
} */


// 7-2˜
    /* 
    
    1. Introduc getchar(), putchar()
    2. Use while loop to process char sequences
    3. Filter a specific character
    4. Convert number to asterisks
    5. Lower characters to Upper Char
    
     */

/* int main()
{


    char ch;

    while ((ch = getchar()) != '\n') // use '\n' to find the end of a sentence
    {

        if (ch >= '0' && ch <= '9')
            ch = '*';

        putchar(ch);
    }


    putchar(ch);
    return 0;
} */

/* int main()
{


    char ch;

    while ((ch = getchar()) != '\n') // use '\n' to find the end of a sentence
    {

        if (ch >= 'a' && ch <= 'z') //'A' = 65 'a' = 97
            ch -= 'a' - 'A';

        else if(ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';

        putchar(ch);
    }


    putchar(ch);
    return 0;

} */

// 7-3. ctype.h

//#include <ctype.h>
/* int main()
{
    char ch;

    while ((ch = getchar()) != '\n') // use '\n' to find the end of a sentence
    {

        if (islower(ch)) //'A' = 65 'a' = 97
            ch = toupper(ch);

        else if (isupper(ch))
            ch = tolower(ch);

        putchar(ch);
    }


    putchar(ch);
    return 0;

}

 */

// 7-4, 7-5. else와 if

/* int main()
{
    int number;
    scanf("%d", &number);

    if (number > 5) 
    {
            if (number < 10)
            printf("Larger than 5 smaller than 10\n");
    }    
    else
        printf("Less than or equal to 5");
   
    // compilers ignore indenting

    return 0;
}
 */


// 7-6.
// #include <stdbool.h>

// int main()
// {
//     unsigned num;
//     bool isPrime; //flag, try bool type

//     scanf("%u", &num);

//     /* 
//     TODO: Check if num is a prime number
//     ex) num is 4, try num % 2, num % 3
//      */

//     isPrime = true;

//     for (unsigned i =2; (i*i) <= num; i++)
//     {
//         if (num % i == 0)
//         {
//             isPrime = false;

//             printf("%u is divisible by %u and %u. \n", num, i, num/i);
//         }


//     }
//     if (isPrime)
//         printf("%u is a prime number. \n", num);

//     else
//         printf("%u is not a prime number\n", num);


// }

// 7-7. logical operators

#include <ctype.h> //islower()
#include <stdbool.h>
#include <iso646.h> //and, or, not

#define PERIOD '.'

// int main()
// {
//     /* 
//     Logical operators
    
//     && : and
//     || : or
//     !  : not
//     */

//    bool test1 = 3>2 || 5>6; //true
//    bool test2 = 3>2 && 5>6; //false
//    bool test3 = !(5>6);     //true, equivalent to 5 <= 6
   
//    printf("%d %d %d \n", test1, test2, test3);


//     /* Character Counting example */

//     char ch;
//     int count = 0;

//     while ((ch = getchar()) != PERIOD)
//     {
//         //TODO: make exceptions

//         if (ch != '\n' && ch != ' ')
//             count ++; 

//     }
//     printf("%d", count);

//     /* short circuit evaluation 

//     - Logical expressions are evaluated from left to right
//     - && and || are sequence points

//     */

//    int temp = (1+2) * (3+4);

//    printf("before: %d \n", temp);
//    if (temp == 0 && (++temp == 1024)) //중요한 것은 (++temp) 부분이 실행이 되는지, 되지 않는지이다!! 
//    {

//    };

// //    printf("after: %d \n", temp);

//     /* Ranges */

//     for (int i = 0 ; i< 100; ++i)
//         if (i>10 && i<= 20)
//             printf("%d ", i);

//     printf("\n");
// } 


//// 7-8. 단어 세기

// #include <stdbool.h>
// #define STOP '.'

// int main()
// {
//     char c;
//     int n_chars = 0;
//     int n_lines = 0;
//     int n_words = 0;
//     bool word_flag = false;
//     bool line_flag = false;

//     printf("Enter Text: \n");

//     while( (c=getchar()) != STOP)
//     {
//         if (!isspace(c))
//             n_chars++;
        
//         if (!isspace(c) && !line_flag)
//         {
//             n_lines++;
//             line_flag = true;
//         }
        
//         if (c == '\n')
//             line_flag = false;

//         if (!isspace(c) && !word_flag)
//         {
//             n_words++;
//             word_flag = true;

//         }

//         if (isspace(c))
//             word_flag = false;

//     }
    
//     printf("Characters = %d , Words = %d, Lines = %d ", n_chars, n_words, n_lines);

// }

//// 7-9. 조건 연산자

// #include <stdbool.h>

// int main()
// {
//     int temp;
//     temp = true ? 1024 : 7 ; //ternary oprator: 삼항연산자
//     printf("%d \n", temp);
    
//     temp = false ? 1024 : 7 ; //ternary oprator: 삼항연산자
//     printf("%d \n", temp);
// }


// 7-10. continue, break

// int main()
// {
//     /* continue */

//     // int count = 0;
//     // while (count < 5)
//     // {
//     //     int c= getchar();
//     //     if (c == 'a')
//     //         continue;

//     //     putchar(c);
//     //     count++;

//     // }


//     /* continue as a placeholder */

//     while (getchar() != '\n')
//         continue;
    
    
// }

//// 7-11. min, max

// #include <float.h>
// #include <stdio.h>

// int main()
// {
//     float max = -FLT_MAX;
//     float min = FLT_MAX;
//     float sum = 0.0f;
//     float input;
//     int n=0;

//     while (scanf("%f", &input) == 1)
//     {
//         max= (input > max) ? input: max;
//         min = (input < min) ? input: min;
//         sum += input;

//         n++;
//     }
//         if (n>0)
//             printf("min = %f, max = %f, ave = %f\n", min, max, sum/n );
//         else
//             printf("no input\n");

//         return 0;
    
// }

//// 7-12. switch , case

// int main()
// {
//     char c;
//     while( (c = getchar()) != '.')
//     {
//         printf("You love ");

//         switch (c)
//         {
//         case 'a':
//             printf("apple");
//             break;
        
//         case 'b':
//             printf("baseball");
//             break;
        
//         default:
//             printf("nothing");
//         }


//         printf(". \n");

//         while (getchar() != '\n')
//             continue;
    
    
//     }



// }

//// 07-13. goto를 피하는 방법 
