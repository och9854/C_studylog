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
    struct movie* next;
};

typedef struct movie* p_movie;

void read_file(struct movie** p_head) // movie의 포인터.의 포인터를 사용하는 구조 == struct movie**
{
    char filename[TSIZE] = {0,};
    
    // filenae_input
    printf("Please input filename to read and press Enter.\n");
    printf(">> ");
    
    if (scanf("%[^\n]%*c", filename) != 1) {
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
    if (fscanf(file, "%d%*c", &num) != 1) // file 데이터 수를 셈
    {
        printf("ERROR: Wrong file format.");
        exit(1);
    }

    p_movie prev = *p_head;

    // counting
    for (int n = 0; n< num; ++n)
    {
        // if (fscanf(file, "%[^\n]%*c", movie_list[*ptr_n_items].title) != 1 ||
        //     fscanf(file, "%f%*c", &movie_list[*ptr_n_items].rating) != 1)
        // {
        //     printf("ERROR: Wrong file format.\n");
        //     exit(1);
        // }

        // *ptr_n_items += 1;

        p_movie new_movie = (p_movie)malloc(sizeof(struct movie));
        if (new_movie == NULL)
        {
           printf("ERROR: Malloc failed .\n");
           exit(1);
        }

        new_movie -> next = NULL;

        if (fscanf(file, "%[^\n]%*c", new_movie -> title) != 1 ||
            fscanf(file, "%f%*c", &new_movie -> rating) != 1)
        {
            printf("ERROR: Wrong file format.\n");
            exit(1);
        }

        // coding할 때 아래 부분을 넣지 않아서 에러가 한참 동안 났었다. 
        // 에러 = segmentation fault = 허용되지 않은 memory를 변경할 때 나타남
        // 해결된 이유: struct movie prev 가 NULL인데, NULL -> next를 선언하려해서 메모리 할당 에러가 난듯함
        if (prev == NULL) 
        {
            /* code */
            *p_head = new_movie;
            prev = new_movie;
        }
        else
        {
            //Insert front 
            //p_movie temp = (*head)-> next;
            //(*head)-> next= new_movie;
            //new_movie -> next = temp;
        
            // add at the end
            prev -> next = new_movie;
            prev = new_movie; 
        }


    }

    // double check
    // assert(*ptr_n_items == num);

    fclose(file);

    printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const p_movie head)
{
    unsigned int count = 0;
    p_movie pnode = head; /* set to start of list */

    while (pnode != NULL)
    {
        /* code */
        count += 1;
        pnode = pnode -> next;
    }

    return count;
}



void write_file(p_movie head)
{
    char filename[TSIZE] = {0, };

    // filename_input
    printf("Please inpput filename to read and press Enter.\n");
    printf(">> ");

    if (scanf("%[^\n]%*c", filename) != 1){
        printf("Wrong input. Terminating.\n");
        exit(1);
    }


    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: cannot open file.\n");
        exit(1);
    }

    int count = 0;
    fprintf(file, "%d\n", (int)count_items(head));

    p_movie pnode = head;

    // for (int n= 0; n<n_items;++n)
    // {
    //     fprintf(file, "%s\n", movie_list[n].title);
    //     fprintf(file, "%f\n", movie_list[n].rating);
    // }

    while (pnode != NULL)
    {
        /* code */
        fprintf(file, "%s\n", pnode -> title);
        fprintf(file, "%.1f", pnode -> rating);

        pnode= pnode -> next;

        count++;
    }
    
    fclose(file);
    assert(count == (int)count_items(head)); // 위 while문이 잘못될 경우를 대비한 assert


    printf("%d items have been saved to the file.\n", count);
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


void print_all(p_movie head)
{
    p_movie pnode = head; /* set to start of list */

    int count = 0;

    while (pnode != NULL)
    {
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);
        pnode = pnode -> next;
        count ++;
    }
    
    // for (int n = 0; n < n_items; ++n)
    //     printf("%d : \"%s\", %.1f\n", n, movie_list[n].title, movie_list[n].rating);
}

void print_an_item(p_movie head)
{
    printf("Input the index of item to print.\n");
    int index = input_int();
    
    p_movie pnode = head; /* set to start of list */

    int count = 0;

    while (pnode != NULL)
    {
        /* code */
        if (count == index) break;

        pnode = pnode -> next;
        count ++;
    }
    
    if (pnode != NULL)
    {
        printf("%d : \"%s\", %.1f\n", count, pnode -> title, pnode -> rating);
    }
    else   
        printf("Invalid item.\n");
    
    // if (index < n_items)
    //     printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
    // else
    //     printf("Invalid item.\n");
}

void edit_an_item(p_movie head)
{
    printf("input the index of item to edit.\n");
    int index = input_int();


    p_movie pnode = head; /* set to start of list */

    int count = 0;

    while (pnode != NULL)
    {
        /* code */
        if (count == index) break;
            /* code */

        pnode = pnode ->next;
        count ++;
    }

    if (pnode != NULL)
    {
        /* code */
        printf("%d : \"%s\", %.1f\n", index, pnode -> title, pnode -> rating);

        printf("input new title and press enter.\n");
        printf(">> ");
        int f = scanf("%[^\n]%*c",pnode -> title);

        printf("Input new rating and press enter.\n");
        printf(">> ");
        f = scanf("%f%*c", &pnode -> rating);

        printf("%d : \"%s\", %.1f\n", index, pnode -> title, pnode -> rating);
    }
    else
        printf("Invalid item.\n");
    

    // if (index < n_items)
    // {
    //     printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

    //     printf("input new title and press enter.\n");
    //     printf(">> ");
    //     int f = scanf("%[^\n]%*c", movie_list[index].title);

    //     printf("Input new rating and press enter.\n");
    //     printf(">> ");
    //     f = scanf("%f%*c", &movie_list[index].rating);

    //     printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
    // }

    // else
    //     printf("Invalid item.\n");
}

void add_an_item(p_movie* p_head) 
{
    // if (*ptr_n_items == LMAX)
    // {
    //     printf("No more space.\n"); // 링크드 리스트는 이런 문제가 발생하지 않기 떄문에, 다르게 사용한다!
    //     return; 
    // }

    // const int index = *ptr_n_items;

    printf("input new title and press enter.\n");
    printf(">> ");

    p_movie new_movie = (p_movie)malloc(sizeof(struct movie)); // 새로운 movie 객체 생성
    if (new_movie == NULL)
    {
        /* code */
        printf("ERROR: malloc() failed");
        exit(1);
    }
    
    new_movie -> next = NULL;

    int f = scanf("%[^\n]%*c", new_movie -> title);
    printf("input rating and press enter.\n");
    printf(">> ");
    f = scanf("%f%*c", &new_movie -> rating);

    //TODO: count
    //TODO: implement find list
    //TODO: find index
    //TODO: implement do all ... (using function pointer)

    int count = 0;
    p_movie pnode = *p_head; /* set to start of list */

    if (pnode == NULL) // 첫 노드일 경우
    {
        /* code */
        *p_head = new_movie;
    }
    else
    {
        while (pnode -> next != NULL)
        {
            pnode = pnode -> next;
            count++;
        }
        pnode -> next = new_movie;
        count++;
    }
    
    printf("%d : \"%s\", %.1f \n", count, new_movie -> title, new_movie -> rating);
}

void insert_an_item(p_movie* p_head)
{
    // if (*ptr_n_items == LMAX)
    // {
    //     printf("No more space.\n");
    //     return;
    // }

    printf("input the index of item to insert.\n");
    int index = input_int();

    // case1. memmove로 한칸씩 옮기기
    // memmove(&moive_list[index + 1], &movie_list[index], sizeof(struct movie)* (*ptr_n_items - index));

    // case2. For loop implemenatation
    // for (int i = *ptr_n_items - 1; i>=index; i--)
    // {
    //     strcpy(movie_list[i+1].title, movie_list[i].title);
    //     movie_list[i+1].rating = movie_list[i].rating;
    // }

    // printf("input new title and press enter.\n");
    // printf(">> ");
    // int f = scanf("%[^\n]%*c", movie_list[index].title);

    // printf("Input new rating and press enter.\n");
    // printf(">> ");
    // f = scanf("%f%*c", &movie_list[index].rating);

    // printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

    // *ptr_n_items += 1;

    p_movie pnode = *p_head;
    p_movie prev = NULL;

    int count = 0;
    while (pnode != NULL)
    {
        /* code */
        if (count == index) break;
        
        prev = pnode;
        pnode = pnode -> next;
        count++;
    }

    if (pnode == NULL)
    {
        printf("Wrong Index\n");
        return;
    }

    p_movie new_movie = (p_movie)malloc(sizeof(struct movie));
    if (new_movie == NULL)
    {
        /* code */
        printf("ERROR: malloc() failed");
        exit(1);
    }
    new_movie -> next = NULL;

    printf("input new title and press enter.\n");
    printf(">> ");
    int f = scanf("%[^\n]%*c", new_movie -> title);

    printf("Input new rating and press enter.\n");
    printf(">> ");
    f = scanf("%f%*c", &new_movie -> rating);

    printf("%d : \"%s\", %.1f\n", index, new_movie -> title, new_movie -> rating);

    // p_movie temp = pnode-> next;
    if (prev == NULL)
        *p_head = new_movie;
    else
        prev -> next = new_movie;
    
    new_movie -> next = pnode;

}

void delete_an_item(p_movie* p_head)
{
    printf("input the index of item to delete.\n");
    int index = input_int();

    //memmove(&movie_list[index], &movie_list[index+1],
    //sizeof(struct movie) * (*ptr_n_items - index);

    /* For loop implementation */
    // for (int i = index; i < *ptr_n_items; i++)
    // {
    //     strcpy(movie_list[i].title, movie_list[i+1].title);
    //     movie_list[i].rating = movie_list[i+1].rating;
    // }

    // *ptr_n_items -= 1;

    p_movie pnode = *p_head;
    p_movie prev = NULL;

    int count = 0;
    while (pnode != NULL)
    {
        /* code */
        if (count == index) break;

        prev = pnode;
        pnode = pnode -> next;;
        count++;
    }

    if (pnode == NULL)
    {
        printf("Wrong index\n");
        return;
    }
    if (prev == NULL)
    {
        /* code */
        *p_head = pnode -> next;
    }
    else
        prev -> next = pnode -> next;
    free(pnode);  // free 선언을 잊지 말자!
}

void delete_all_items(p_movie* p_head)
{
    // TODO: count and assert

    int count = 0;
    p_movie search = *p_head;

    if (search == NULL)
    {
        /* code */
        printf("Nothing to delete\n");
        return;
    }

    p_movie temp = NULL;

    while (*p_head != NULL)
    {
        /* code */
        temp = (*p_head) -> next;
        free(*p_head);
        *p_head = temp;
        count++;

        // NOTE: use debug mode or print all items when they are deleted to make it sure
    }
    
    printf("%d items deleted.\n", count);
    
}


void search_by_name(p_movie head)
{
    printf("input new title and press enter.\n");
    printf(">> ");

    char title[TSIZE] = {0,};
    if (scanf("%[^\n]%*c", title) != 1)
    {
        printf("wrong input.\n");
        return;
    }

    p_movie pnode = head;

    int count = 0;
    while (pnode != NULL)
    {
        if (strcmp(pnode -> title, title) == 0) break;
        pnode = pnode -> next;
        count++;
    }

    if (pnode == NULL)
    {
        printf("No movie found: %s \n", title);
        return;
    }
    
    printf("%d : \"%s\", %.1f\n", count , pnode-> title, pnode -> rating);

    // int index = 0;
    // for (; index < n_items; ++index)
    // {
    //     if (strcmp(movie_list[index].title, title) == 0)
    //         break;
    // }

    // if (index == n_items)
    //     printf("No movie found: %s\n", title);
    // else 
    //     printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
}




int main()
{
    /* struct movie movie_list[LMAX];
    size_t n_items = 0; */

    p_movie head = NULL;

    printf("\n");
    read_file(&head);    
    printf("\n");

    
    while (1)
    {
        printf("\n");

        int s = input_menu();

        switch (s)
        {
        case 1:
            print_all(head);
            break;
        case 2:
            print_an_item(head);
            break;
        case 3:
            edit_an_item(head);
            break;
        case 4:
            add_an_item(&head);
        case 5:
            insert_an_item(&head);
            break;
        case 6:
            delete_an_item(&head);
            break;
        case 7:
            // n_items = 0;
            // TODO: delete all
            delete_all_items(&head);
            break;

        case 8:
            write_file(head);
            break;
        case 9:
            search_by_name(head);
            break;
        case 10:
            printf("Good bye\n");
            delete_all_items(&head);
            exit(0);
        default:
            printf("%d is not implemented.\n",s);

        }

        return 0;

    }
    
 


}
