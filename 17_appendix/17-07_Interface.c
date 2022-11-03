#define _CRT_SECURE_NO_WARNINGS

#include "SimpleList.h"

#include <stdio.h>
// #include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void read_file(List* plist) 
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
    int num;
    if (fscanf(file, "%d%*c", &num) != 1) // file 데이터 수를 셈
    {
        printf("ERROR: Wrong file format.");
        exit(1);
    }

    // counting
    for (int n = 0; n< num; ++n)
    {
        Item new_item;

        if (fscanf(file, "%[^\n]%*c",new_item.title) != 1 ||
            fscanf(file, "%f%*c", &new_item.rating) != 1)
        {
            printf("ERROR: Wrong file format.\n");
            exit(1);
        }

        AddItem(new_item, plist);

    }

    // double check
    // assert(*ptr_n_items == num);

    fclose(file);

    printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const List* const plist)
{
    return CountItems(plist);
}

void write_an_item(FILE* const file, const Item item)
{
    fprintf(file, "%s\n", item.title);
    fprintf(file, "%.1f\n", item.rating);
}

void write_file(const List* const plist)
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

    unsigned int num = CountItems(plist);
    
    fprintf(file, "%d\n", num);

    unsigned int count = WriteAllItems(plist, file, &write_an_item);
    // write를 할 게 어떤 게 들어올지 일반화할 수 없기 때문에, main.c에서 구현한다.
    // &: function pointer
    assert(count == num);

    fclose(file);

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

void print_an_item(Item item)
{
    printf("\"%s\", %.1f\n", item.title, item.rating);
}

void print_all(const List* plist)
{
    PrintAllItems(plist, print_an_item);
}   

// NOTE: renamed from print_an_item(.)
void find_and_print_an_item(const List* const plist)
{
    printf("Input the index of item to print.\n");
    int index = input_int();

    Item *pitem;
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == true)
    {
        /* code */
        printf("%d :", index);
        print_an_item(*pitem);
    }
    else
        printf("Invalid Item.\n");
    
}

void edit_an_item(List* plist)
{
    printf("input the index of item to edit.\n");
    int index = input_int();

    Item* pitem;
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == true)
    {
        /* code */
        printf("%d :", index);
        print_an_item(*pitem);

        Item new_item;
        printf("input new title and press enter.\n");
        printf(">> ");
        int f = scanf("%[^\n]%*c", new_item.title);

        printf("Input new rating and press enter.\n");
        printf(">> ");
        f = scanf("%f%*c", &new_item.rating);

        *pitem = new_item;
        printf("%d : ", index);
        print_an_item(*pitem);
    }
    else
        printf("Invalid Item.\n");
}

void add_an_item(List* plist)
{

    printf("input new title and press enter.\n");
    printf(">> ");
    
    Item new_item;

    int f = scanf("%[^\n]%*c", new_item.title);
    printf("Input rating and press enter.\n");
    printf(">> ");

    f = scanf("%f%*c", &new_item.rating);

    AddItem(new_item, plist);
    
    printf("%d : \"%s\", %.1f \n", CountItems(plist) - 1, new_item.title, new_item.rating);
}

void insert_an_item(List* plist)
{
    printf("input the index of item to insert.\n");
    int index = input_int();

    Item* pitem; // Not actually used
    const bool flag = FindItemByIndex(plist, index, &pitem);

    if (flag == false)
    {
        /* code */
        printf("wrong index.\n");
        return;
    }

    Item new_item;

    printf("input new title and press enter.\n");
    printf(">> ");
    int f = scanf("%[^\n]%*c", new_item.title);

    printf("Input new rating and press enter.\n");
    printf(">> ");
    f = scanf("%f%*c", &new_item.rating);

    printf("%d : \"%s\", %.1f\n", index, new_item.title, new_item.rating);

    InsertbyIndex(new_item, plist, index);
}

void delete_an_item(List* plist)
{
    printf("input the index of item to delete.\n");
    int index = input_int();
    
    Item* pitem; // Not actually used
    const bool flag = FindItemByIndex(plist, index, &pitem);
    
    if (flag == false)
    {
        /* code */
        printf("wrong index.\n");
        return;
    }

    RemoveByIndex(plist, index);
}

void delete_all_items(List* plist)
{
    ClearList(plist);    
}

bool compare_items(Item a, Item b)
{
    if (strcmp(a.title, b.title) == 0)
        return true;
    else    
        return false;
}


void search_by_name(const List* plist)
{
    printf("input new title and press enter.\n");
    printf(">> ");

    Item item_to_find;

    char title[TSIZE] = {0,};
    if (scanf("%[^\n]%*c", item_to_find.title) != 1)
    {
        printf("wrong input.\n");
        return;
    }

    Item item_found;

    int index;

    if (Find(plist, item_to_find, &index, &item_found, compare_items) == 0) // 0맞는ㄴ치 체크
    {
        printf("No movie found: %s\n", item_to_find.title);
        return;
    }
    else
        printf("%d : \"%s\", %.1f\n", index , item_found.title, item_found.rating);

}



int main()
{
    /* struct movie movie_list[LMAX];
    size_t n_items = 0; */

    List movie_list;

    InitializeList(&movie_list);

    read_file(&movie_list);    

    
    while (1)
    {
        printf("\n");

        int s = input_menu();

        switch (s)
        {
        case 1:
            print_all(&movie_list);
            break;
        case 2:
            find_and_print_an_item(&movie_list);
            break;
        case 3:
            edit_an_item(&movie_list);
            break;
        case 4:
            add_an_item(&movie_list);
        case 5:
            insert_an_item(&movie_list);
            break;
        case 6:
            delete_an_item(&movie_list);
            break;
        case 7:
            // n_items = 0;
            // TODO: delete all
            delete_all_items(&movie_list);
            break;

        case 8:
            write_file(&movie_list);
            break;
        case 9:
            search_by_name(&movie_list);
            break;
        case 10:
            printf("Good bye\n");
            delete_all_items(&movie_list);
            exit(0);
        default:
            printf("%d is not implemented.\n",s);

        }

        return 0;

    }
    
 

}
