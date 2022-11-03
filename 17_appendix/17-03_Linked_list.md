# 17-03. Linked List
---

## Linked List란?
---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/173506698-5e9c198d-1345-42cc-9d3f-5f45c8b500d3.png">

Linked list와 array의 차이를 알아보자.

배열은 메모리를 통짜로 받아들이고, linked list는 데이터 아이템의 메모리를 하나하나 받아온다.(malloc 함수를 이용하여 그떄그때 받아온다.)

- 단점
    - 다음 데이터가 어디에 있는지 찾기 힘들다.
    - 무조건 순차 접근(sequential access)


## 배열, 연결 리스트의 장단점
---

<img width="842" alt="image" src="https://user-images.githubusercontent.com/78291267/173507305-350fb3cb-aec8-4a04-8afd-52cd32bab932.png">

배열에서는 element라는 용어를 사용한 기억이 있을 것이다. 배열의 관점에서 '몇 번째 데이터' 등을 의미할 때는 요소를 이용하여 부르고, 데이터 자체를 의미할 때는 Item이라는 용어를 많이 사용한다. 

linked list를 통해 영화와 평점을 노드 요소로 가지는 자료구조를 완성해보자.

```c

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

```