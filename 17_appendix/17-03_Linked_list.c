#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TSIZE 45

struct movie
{
    /* data */
    char title[TSIZE];
    float rating;
    struct movie* next;
    // 다음 주소를 가리키는 포인터 지정
};


typedef struct movie* p_moive;
// 개인의 취향임. 하지 않아도 됨

void print_all(struct movie *head)
{
    printf("----------------------------------------\n");
    printf("Head address = %zd\n", (size_t)head);
    struct movie* search = head;
    while (search != NULL)
    {
        /* code */
        printf("%zd \"%s\" %f %zd \n", (size_t)search, search -> title,
        search -> rating, (size_t)search -> next); 
        search = search -> next;
    }
    
}

int main()
{
    p_moive head = NULL; 
    // head가 있어야 시작점을 안다.

    /* first node */
    p_moive new_node = malloc(sizeof(struct movie));
    if (new_node == NULL)
    {
        printf("ERROR: malloc failed");
        exit(1);
    }
    //// string copy
    //// 초기화
    strcpy(new_node -> title, "Avatar");
    new_node -> rating = 9.5f;
    new_node -> next = NULL;

    if (head == NULL)
    {
        /* code */
        head = new_node; // first node
        
    }

    /* second node */
    p_moive sec_node = malloc(sizeof(struct movie));
    if (sec_node == NULL)
    {
        printf("ERROR: malloc failed");
        exit(1);
    }
    //// string copy
    //// 초기화
    strcpy(sec_node -> title, "Aladdin");
    sec_node -> rating = 8.0f;
    sec_node -> next = NULL;

    /* Add front */
    p_moive temp = head;        // 빈 공간 생성
    head = sec_node;            // 두 번쨰 노드를 head로 지정
    sec_node -> next = temp;    // 두 번째 노드의 next를 첫째 노드로

    print_all(head);

    /* Third node */
    p_moive third_node = malloc(sizeof(struct movie));
    if (third_node == NULL)
    {
        printf("ERROR: malloc failed");
        exit(1);
    }
    //// string copy
    //// 초기화
    strcpy(third_node -> title, "Wonder Woman");
    third_node -> rating = 8.5f;
    third_node -> next = NULL;

    /* Add back */
    // 1st. find last node
    p_moive search = head;
    while (search -> next != NULL)
    {
        /* code */
        search = search -> next;
    }
    // 2nd. link
    search -> next = third_node;

    print_all(head);

    /* Find and Delete an item */
    search = head;
    p_moive prev = NULL;

    int count = 0;
    while (search != NULL)
    {
        /* code */
        if (strcmp(search -> title, "Aladdin") == 0) break; // Aladdin node를 찾으면 멈춤
    
        prev = search;
        search = search -> next;
        count++;
        
    }
    if (search == NULL)
    {
        /* code */
        printf("wrong index\n");
        return 0;
    }

    if (prev == NULL)
    {
        /* code */
        head = search -> next;
    }
    else
        prev -> next = search -> next;
    free(search);

        
        

    printf("---------------------------------- \n \
        After Deleting Aladdin Node\n");
    print_all(head);
    
    return 0;
    
}

