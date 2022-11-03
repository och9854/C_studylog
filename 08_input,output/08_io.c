// 8.1. 입출력 버퍼

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h> //windows,  __getch(), get

//// 8.2 End Of file

// int main()
// {
//     int c;

//     while((c = getchar()) != EOF) //End Of File
//         putchar(c);
    
// }


////8-3. 입출력 방향 redirection

// #include <stdio.h>

// int main()
// {
//     //printf("I love apple\n");

//     char str[100];
//     scanf("%s", str);
//     printf("I love %s \n", str);
// }

////8-4 interface
/* 
int main()
{
    int count = 0;

    while(1)
    {
        printf("Current count is %d Continue? (Y/n)", count);

        int c = getchar();

        if (c== 'n')
            break;
        else if (c=='y')
            count++;
        else
            printf("Please input y or n! \n");

        while (getchar() != '\n')
            continue;
    }

    return 0;
}
 */

//// 8.5 숫자 문자 섞어서 입력받기

// void display(char cr, int lines, int width);

// int main()
// {
//     char c;
//     int rows, cols;

//     // while (1)
//     // {
//     //     scanf("%c %d %d", &c , &rows, &cols);
//     //     while (getchar() != '\n') continue;
//     //     display(c, rows, cols);
//     //     if (c=='\n')
//     //         break; //doesn't work well
//     // }

//     printf("INPUT one character and two integers: \n");
//     while ((c = getchar()) != '\n')
//     {
//         scanf("%d %d", &rows, &cols);

//         while (getchar() != '\n') continue; // buffer에 남은 값들을 제게해줘야 한다!

//         display(c, rows, cols);
//         printf("INPUT another character and two integers: \n");
//         printf("PRESS enter to quit \n");


//     }
//     return 0;
// }

// void display(char cr, int lines, int width)
// {
//     int row, col;
    
//     for (row=1; row<=lines; row++)
//     {
//         for (col = 1; col <= width; col++)
//             putchar(cr);
//         putchar('\n');
//     }
// }

//// # 8-6. 입력 확인하기


/* long get_long(void);

int main()
{
    long number;

    while(1)
    {
        printf("Please input a integer between 1 and 100 \n");
        number = get_long();

        if (number > 1 && number < 100)
        {

            printf("OK. Thank you \n");
            break;
        }

        else
            printf("Wrong input. please try again\n");
    }

    printf("Your input %d is between 1 and 100\n", number);
    return 0;
}

long get_long(void)
{
    printf("please input an integer and press enter \n");

        long input;
        char c;

        while (scanf("%ld", &input) != 1)
        {
            printf("Your input - ");

            while ((c=getchar()) != '\n')
                putchar(c); //input left in buffer

            printf(" - is not an integer. Please try again\n");

        }

        printf("Your input %ld is an integer. Thank you \n", input);

        return input;
}
 */


//// 8-7. 입력 스트림과 숫자

//// 8-8.  메뉴 만들기 예제

/* #include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);


int main()
{
    int user_choice;

    while( (user_choice = get_choice()) != 'q')
    {

        switch (user_choice)
        {
        case 'a':
            printf("Avengers Assembe! \n");
            break;
        
        case 'b':
            putchar('\a');
            break;
        
        case 'c':
            count();
            break;
        default:
            printf("Error with %d. \n", user_choice);
            exit(1);
            break;

        }
    }

    return 0;
}

char get_choice(void)
{
    char user_input;
    printf("Enter the letter of your choice: \n");
    printf("a. avengers    b. beep \n");
    printf("c. count       q. quit \n");

    user_input = get_first_char();

    while(1)
    {
        if ( (user_input == 'a') || (user_input == 'b')|| (user_input == 'c') || (user_input == 'q'))
            break;
        else
            printf("Error put option again. \n");
            printf("Enter the letter of your choice: \n");
            user_input = get_first_char();
    }
    return user_input;

}

void count(void)
{
    int n, i;

    printf("Enter an integer: \n");
    n = get_integer();
    for (i=1; i<=n; ++i)
        printf("%d\n", i);
    while ( getchar() != '\n')
    {
        continue;
    }
    
}

char get_first_char(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    
    return ch;
}

int get_integer(void)
{
    int input;
    char c;

    while (scanf("%d", &input) != 1)
    {
        while ( (c=getchar()) != '\n')
            putchar(c);
        printf(" is not an integer. \n Please try again.");

    }
    
    return input;
} */


//// 08-09. text file

#include <stdlib.h>


int main()
{
    int c;
    FILE *file = NULL;
    char file_name[] = "my_file.txt"; //TODO: use scanf

    file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Failed to open file. \n");
        exit(1);
    }

    while( (c = getc(file)) != EOF ) //getc(): get character. 문자를 읽어온다.
        putchar(c);
    fclose(file);

    printf("\n");

    return 0;
}

