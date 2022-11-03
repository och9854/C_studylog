# 17-01. 영화 평점관리 연습문제
---

이번 부록에서는 data structure에 대해서 주로 다룰 것이다. 이 강의 뒷부분을 이해하기 위해서, 해당 문제를 스스로 풀어보기를 강력히 권장한다.

17장은 예제가 길어지므로, (코드를 따라서 치는 것보다) 이번 예제를 직접 작성해보고, 이후 이어지는 내용을 배우고 추후 작성했던 프로그램을  업그레이드 하는 방식으로 구현하면 재밌게 공부할 수 있을 것이다.

```c

#include <stdio.h>
// #include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//// 01

#define TSIZE 45
#define LMAX 10


struct movie
{
    /* data */
    char title[TSIZE];
    float rating;
};

void read_file(struct movie movie_list[], size_t* ptr_n_items)
{
    char filename[TSIZE] = {0,};
    
    // filenae_input
    printf("Please input filename to read and press Enter.\n");
    printf(">> ");
    
    if (scanf("%[^\n]%*c", filename) != 1){
        printf("wrong input. Terminating.\n");
        exit(1);
    }

    FILE* file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: cannot open file.\n");
        exit(1);
    }
    
    // counting
    int num =0;
    if (fscanf(file, "%d%*c", &num) != 1)
    {
        printf("ERROR: Wrong file format.");
        exit(1);
    }


    // counting
    for (int n = 0; n< num; ++n)
    {
        if (fscanf(file, "%[^\n]%*c", movie_list[*ptr_n_items].title) != 1 ||
            fscanf(file, "%f%*c", &movie_list[*ptr_n_items].rating) != 1)
        {
            printf("ERROR: Wrong file format.\n");
            exit(1);
        }

        *ptr_n_items += 1;
    }

    // double check
    assert(*ptr_n_items == num);

    fclose(file);

    printf("%zu items have been read from the file.\n", *ptr_n_items);
}

void write_file(struct movie movie_list[], int n_items)
{
    char filename[TSIZE] = {0, };

    // filename_input
    printf("Please inpput filename to read and press Enter.\n");
    printf(">> ");

    if (scanf("%[^\n]%*c", filename) != 1){
        printf("wrong input. Terminating.\n");
        exit(1);
    }


    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("error: cannot open file.\n");
        exit(1);
    }

    fprintf(file, "%d\n", n_items);
    for (int n= 0; n<n_items;++n)
    {
        fprintf(file, "%s\n", movie_list[n].title);
        fprintf(file, "%f\n", movie_list[n].rating);
    }

    fclose(file);

    printf("%d items have been saved to the file.\n", n_items);
}

int input_int()
{
    int input;


    // 사용자가 정수를 입력할 때까지 반복
    while (1)
    {
        printf(">> ");
        if (scanf("%d%*c", &input) == 1) return input;
        else {
            printf("please input an integer and press enter. Try again.\n");
            while (getchar() != '\n') continue;
        }
    }
}

int input_menu()
{   
    while (1)
    {
        
    // option input
    printf("Please select an option and press enter.\n");   
    printf("1. Print all items \t 2.Print an item \n3. Edit an item \t 4. Add an item. \n\
    5. Insert an item \t 6. Delete an item \n7. Delete all items \t 8. Save file\n\
    9. Search by name \t 10. Quit\n");

    int input = input_int();

    if (input >= 1 && input <= 10) return input;
    else 
        printf("%d is invalid. Please try again.\n", input);
    }
        
}

void print_all(struct movie movie_list[], int n_items){
    for (int n = 0; n < n_items; ++n)
        printf("%d : \"%s\", %.1f\n", n, movie_list[n].title, movie_list[n].rating);
}

void print_an_item(struct movie movie_list[], int n_items)
{
    printf("Input the index of item to print.\n");
    int index = input_int();
    if (index < n_items)
        printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
    else
        printf("Invalid item.\n");
}

void edit_an_item(struct movie movie_list[], int n_items)
{
    printf("input the index of item to edit.\n");
    int index = input_int();
    if (index < n_items)
    {
        printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

        printf("input new title and press enter.\n");
        printf(">> ");
        int f = scanf("%[^\n]%*c", movie_list[index].title);

        printf("Input new rating and press enter.\n");
        printf(">> ");
        f = scanf("%f%*c", &movie_list[index].rating);

        printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
    }

    else
        printf("Invalid item.\n");
}

void add_an_item(struct movie movie_list[], size_t* ptr_n_items) // n_items is a pointer
{
    if (*ptr_n_items == LMAX)
    {
        printf("No more space.\n");
        return;
    }

    const int index = *ptr_n_items;

    printf("input new title and press enter.\n");
    printf(">> ");
    int f = scanf("%[^\n]%*c", movie_list[index].title);

    printf("Input new rating and press enter.\n");
    printf(">> ");
    f = scanf("%f%*c", &movie_list[index].rating);

    printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

    *ptr_n_items += 1;
}

void insert_an_item(struct movie movie_list[], size_t* ptr_n_items)
{
    if (*ptr_n_items == LMAX)
    {
        printf("No more space.\n");
        return;
    }

    printf("input the index of item to insert.\n");
    int index = input_int();

    // case1. memmove로 한칸씩 옮기기
    // memmove(&moive_list[index + 1], &movie_list[index], sizeof(struct movie)* (*ptr_n_items - index));

    // case2. For loop implemenatation
    for (int i = *ptr_n_items - 1; i>=index; i--)
    {
        strcpy(movie_list[i+1].title, movie_list[i].title);
        movie_list[i+1].rating = movie_list[i].rating;
    }

    printf("input new title and press enter.\n");
    printf(">> ");
    int f = scanf("%[^\n]%*c", movie_list[index].title);

    printf("Input new rating and press enter.\n");
    printf(">> ");
    f = scanf("%f%*c", &movie_list[index].rating);

    printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

    *ptr_n_items += 1;

}

void delete_an_item(struct movie movie_list[], size_t* ptr_n_items)
{
    printf("input the index of item to delete.\n");
    int index = input_int();

    //memmove(&movie_list[index], &movie_list[index+1],
    //sizeof(struct movie) * (*ptr_n_items - index);

    /* For loop implementation */
    for (int i = index; i < *ptr_n_items; i++)
    {
        strcpy(movie_list[i].title, movie_list[i+1].title);
        movie_list[i].rating = movie_list[i+1].rating;
    }

    *ptr_n_items -= 1;
}

void search_by_name(struct movie movie_list[], int n_items)// 여기서부터 시작
{
    printf("input new title and press enter.\n");
    printf(">> ");

    char title[TSIZE] = {0,};
    if (scanf("%[^\n]%*c", title) != 1)
    {
        printf("wrong input.\n");
        return;
    }

    int index = 0;
    for (; index < n_items; ++index)
    {
        if (strcmp(movie_list[index].title, title) == 0)
            break;
    }

    if (index == n_items)
        printf("No movie found: %s\n", title);
    else 
        printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
}




int main()
{
    struct movie movie_list[LMAX];
    size_t n_items = 0;

    read_file(movie_list, &n_items);
    
    while (1)
    {
        printf("\n");

        int s = input_menu();

        switch (s)
        {
        case 1:
            print_all(movie_list, n_items);
            break;
        case 2:
            print_an_item(movie_list, n_items);
            break;
        case 3:
            edit_an_item(movie_list, n_items);
            break;
        case 4:
            add_an_item(movie_list, &n_items);
        case 5:
            insert_an_item(movie_list, &n_items);
            break;
        case 6:
            delete_an_item(movie_list, &n_items);
            break;
        case 7:
            n_items = 0;
            break;
        case 8:
            write_file(movie_list, n_items);
            break;
        case 9:
            search_by_name(movie_list, n_items);
            break;
        case 10:
            printf("Good bye\n");
            exit(0);
        default:
            printf("%d is not implemented.\n",s);

        }

        return 0;

    }
    
 


}

```

