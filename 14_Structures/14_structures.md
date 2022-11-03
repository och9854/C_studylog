# 14-01. 구조체가 필요한 이유
---

구체적인 문법을 공부하기에 앞서서, 구조체가 왜 필요한지 그 이유부터 간단히 살펴보고 시작하자.

우리가 환자의 데이터를 관리하는 업무를 한다고 가정하자. 많은 수의 환자 데이터를 처리하고 싶을 것이다. 

이 많은 데이터들을 배열을 통해 처리한다. 배열은 기본적으로 자료형이 같은 데이터 옵젝트들이 나열된 형태이다. 하지만 자료형이 **서로 다르지만 함께 사용하면 편리한 데이터 오브젝트들끼리 모아둘 순 없을까**?

이때 우리가 사용할 수 있는 문법이 구조체이다. 

<img width="942" alt="image" src="https://user-images.githubusercontent.com/78291267/167113538-4a867d1d-fd90-434f-9f08-e433b590b328.png">

구조체 내에는 여러 변수들이 구조체의 "멤버"로써 들어가 있다. 이들은 자료형이 다르더라도 묶어서 "하나의 새로운 자료형인 것처럼" 프로그래밍하게 해주는 것이 구조체이다. 

# 14-02. 구조체의 기본적인 사용법

문법적인 측면에서 구조체를 살펴보자. 구조체를 선언하게 되면, 메모리를 가질 것이라고 생각하지만 그렇지 않다. 구조체 변수가 선언될 때 메모리를 갖게 된다!

```c

#define MAX 41

struct person /* person is a tag of structure */
{
    char name[MAX];     // member
    int age;    // member
    float height;   // member
};

int main()
{
    int flag; //receives return value of scanf()

    /* structure variable */

    struct person genie;

    /* dot(.) is structure membership operator(member access oprator, member operator) */

    strcpy(genie.name, "Will Smith");
    //strncpy(genie.name, "Will Smith")

    genie.age = 1000;

    // dot(.) has higher precedence than &
    flag = scanf("%f", &genie.height); //&(genie.height)
    printf("%f\n", genie.height);
    
    /* Initialization */

    struct person princess = { "Naomi Scott", 18, 160.0f};
    struct person princess2 = {

        "Naomi Scott",
        18,
        160.0f
    };
    
    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0f;
    
    /* designated initializers */
    // designated initializers는 이렇게 순서와 싱관없이 지정이 가능하게 해 준다.
    struct person beauty = {
        .age = 19,
        .name = "Bell",
        .height = 150.0f
    };

    /* pointer to a structure variable */
    struct person* someone;

    someone = &genie;
    // someone = (struct Person*)malloc(sizeof(struct person)); // and free later

    /* Indirect member(ship) operator (or structure pointer operator) */

    someone -> age = 1001; // arrow operator
    // 포인터일 경우에는 다음과 같이 화살표를 사용한다.  

    printf("%s %d \n", someone -> name, (*someone).age);
    // "(*someone).age"와 같이 indirection을 하고 접근을 할 수도 있다.
    
    
}   
```


# 14-03. 구조체의 메모리 할당(Memory Allocation)
---

구조체가 메모리를 어떻게 사용하는지 살펴보자. 배열에서는 자료형이 같은 원소를 사용했기에 간단히 이해할 수 있지만, 구조체의 경우 자료형이 서로 다른 멤버들을 사용하기 때문에 효율성을 높이기 위해 메모리 패딩이라는 것을 사용한다.

## alignment

우리가 메모리와 컴퓨터가 소통하는 방식을 짐작하면, 1바이트(혹은 1비트)씩 연산한다고 생각할 수도 있다. 하지만, 연산 속도가 느리기 때문에 그렇게 하지 않는다. 따라서, 데이터를 묶어서 보내는 것이 효율성이 높기 떄문에 데이터를 묶어서 보낸다.(word 단위. 용량에 따라 다르다.)

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170230103-f19b74ef-f484-4b0c-abab-fe924e4c8e15.png">

a1, a2를 출력하면 다음과 같이 나온다.

```c

int main()
{
    /*1
        Well aligned structure
    */

   struct Aligned
   {
       int a;
       float b;
       double c;
   };
   

   /* 
   |int a | float b | double c|
    4 + 4 + 8 = 16
    */

   struct Aligned a1, a2;

   /*
    padding (struct member alignment)
    - 1 word: 4 bytes in x86, 8 bytes in x64
    */

   struct Padded1
   {
       char a;
       float b;
       double c;
   };

   /* without padding: 빈 공간이 생기며, 효율성이 높지 않다.
   | char a | float b | double c | ? ? ?
   1 + 4 + 8 = 13
    */

   /* with padding: 기본 아이디어 -> 어차피 빈 공간이 생길 거라면, 줄을 맞춰서 연산 효율을 높이자.
   | char a | float b | double c        |
   4(char?) + 4 + 8 = 16
   */


    struct Padded2
    {
        float a;
        double b;
        char c;
    };

    /* size
    | float a | double b | char c |
    8(float?) + 8 + 8(char?) = 24
    */

    // padded1, padded2의 사이즈를 출력하면 각각 16, 24가 나온다.
    // 자료형이 선언되는 순서만 달라져도 이렇게 비효율적이게 바뀔 수 있다.
    // 이유: 컴파일러가 double b가 짤리지 않기 위해 양옆에 패딩을 넣어주기 때문

    struct Padded3
    {
        char a;
        double b;
        double c;
    };

    /* size
    | char a | double b | double c |
    8(char?) + 8 + 8(char?) = 24
    */

   /* 구조체의 배열로 사용할 때 */

   struct Person
   { 
        char name[41];
        int age;
        float height;    
   };

   struct Person mommy;

   struct Person f[4];

   printf("Sizeof a structure array %zd\n", sizeof(f)); 

   /* 
   | f[0].name              | f[0].age | ... |f[3].name | f[3].age |   f[3].height|
   */

  return 0;

}
```


# 14-04. 구조체의 배열 연습문제
---

연습문제를 풀어보자.

최대 세 권의 책 제목, 저자, 가격을 받아오고 이를 출력하는 프로그램을 만든다.


```c


#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3 /* maximum number of books */

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin); // vs. scanf(): 빈칸을 받지 못함

    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL
            * find = '\0';       // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
                
    }

    return ret_val;
}

struct book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main()
{   
    struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, }; // array of book structures */
    int count = 0;
    

    while (1)
    {
        printf("Input a book title or press [Enter] to stop/\n>>");
        //TODO: input title
        //TODO: break if the first character of the input title is '\0'
        if( s_gets(library[count].title, MAX_TITLE) == NULL) break;
        if ( library[count].title[0] == '\0') break;


        printf("Input the author. \n>>");
        //TODO: input author
        s_gets(library[count].author, MAX_AUTHOR);        

    
        printf("Input the price. \n>>");
        // TODO: input price
        // TODO: clear buffer
        int flag = scanf("%f", &library[count].price);
        while (getchar() != '\n')
            continue; /* clear input line */

        count++;

        if (count == MAX_BOOKS)
        {
            printf("No more books.\n");
            break;
        }

        if (count > 0)
        {
            printf("\n The list of books:\n");
            for (int index = 0; index < count; index++)
                printf("\"%s\" written by %s: $%.1f\n",
                library[index].title, library[index].author, library[index].price );
            
        }
        else
            printf("No books to show. \n");


    }
    return 0;
}

```


# 14-05. 구조체를 다른 구조체의 멤버로 사용하기(Nested Structures)
---

```c


#define LEN 20

struct names {
    char given[LEN]; //first name
    char family[LEN]; //last name
};

struct reservation // Another structure
{
    struct names guest; // a nested structure
    struct names host; // one more nested structure

    char food[LEN];
    char place[LEN];

    // time
    int year;
    int month;
    int day;
    int hours;
    int minutes;
};


int main(void)
{
    struct reservation res = {
        .guest = {"Nick", "Carraway"},
        .host = {"Jay", "Gatsby"},
        .place = {"the Gatsby mansion"},
        .food = {"Escargot"},
        .year = 1925,
        .month = 4,
        .day =10,
        .hours = 18,
        .minutes = 30
    };


/* 
TODO

Dear Nick Carraway
I would like to serve you Escargot.
Please visit the Gastby mansion on 10/4/1925 at 18:30.
Sincerly,
Jay Gatsby
*/

    printf("Dear %s %s\n", res.guest.given, res.guest.family);
    printf("I would like to serve you %s.\n", res.food);
    printf("Please visit %s on %d/%d/%d at %d:%d.\n", res.place, res.day, res.month, res.year, res.host, res.minutes );
    printf("Sincerly,\n %s %s", res.host.given, res.host.family);

    return 0;

}
```


# 14-06. 구조체와 포인터
----

이번 강의에서는 주의해야할 점 위주로 살펴보자.

## 첫 번째 예제

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170302060-ad982509-abf8-4769-8ddb-b14b52a5a173.png">


<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170301942-a6fa21ad-7a32-44f8-8de4-d6dba6a07ea4.png">

여기서 girl_friend++; 연산은 포인터의 덧셈이기 때문에, 다음 번의 연산인 Taylor의 첫 부분을 가리키게 된다.

## 두 번째 예제

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170302746-ba360628-2da5-4757-9d2c-49df021019a2.png">

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170303019-6f818c63-aaf4-4e15-970e-6ba09c07954f.png">


구조체를 대입하면, 복사를 해준다!!

출력결과는 다음과 같다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170303227-3d931eda-5661-4057-9f4f-015314a33545.png">

값들은 동일하고, 주소값은 다름을 확인할 수 있다.

## 세 번째 예제: 동적할당 arr

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/170303741-58c6938f-d292-4bcd-ac4d-1d53f9fb0039.png">

이들은 복사를 하더라도 주소가 같은 것을 확인할 수 있다.  이는 동적할당을 받은 메모리의 "주소값"을 복사하기 때문이다!! 

이들은 같은 메모리 공간에 대한 주소를 가리키고 있다. 

이를 주의깊게 살펴보고 기억해두길 바란다.

# 14-07. 구조체를 함수로 전달하는 방법

---


# 14-08. 구조체와 함수 연습문제
---

```c

LEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    receive_input(&user_name);
    count_characters(&user_name);
    show_result(&user_name);

    return 0;    
}

char* s_gets(char* st, int n)
{
    return "none";
}

void receive_input(struct name_count* ptr_nc)
{
    int flag;
    printf("input your first name: \n >>");

    //s_gets(ptr_nc->first, NLEN);
    flag = scanf("%[^\n]%*c", ptr_nc->first);
    // % 기호 뒤 대괄호 안에 ^\n의 의미는: "\n(줄바꿈)"이 나타날 때까지 입력을 받아라. // ^: cap operator
    // *c의 의미는: c를 하나 무시해라.(줄바꿈 기호를 먹어버린다.)
    // 결과적으로 사용자가 입력한 문자열에서 줄바꿈을 빼고 입력을 받아주게 된다.

    if (flag != 1)
        printf("wrong input");

    printf("input your last name: \n >> ");

    flag = scanf("%[^\n]%*c", ptr_nc->last);

        printf("wrong input");

}



void count_characters(struct name_count* ptr_nc)
{
    ptr_nc->num = strlen(ptr_nc -> first) + strlen(ptr_nc -> last);
}



void show_result(const struct name_count* ptr_nc)
{
    printf("hi, %s %s. Your name has %d characters.\n",
     ptr_nc->first, ptr_nc->last, ptr_nc->num);
}

```


# 14-09. 구조체와 할당 메모리
----

이번에는 구조체의 멤버로써 할당 메모리를 사용할 수 있도록 할당 메모리를 가리키는 포인터를 구조체의 멤버로 사용하는 경우에 대해서 살펴보도록 하자.

```c


#define SLEN 81

struct namect {
    char* fname; // use malloc()
    char* lname; // use malloc()
    int letters;
};

void getinfo(struct namect*); // allocate memory
void makeinfo(struct namect*); 
void showinfo(const struct namect*); 
void cleanup(struct namect*);  // free memory when done
char* s_gets(char* st, int n);

int main()
{
    struct namect p = { "jake" , "oh"};
    /* recommended usage */

    char buffer[SLEN] = {0, };
    int f2 = scanf("%[^\n]%*c", buffer);
    p.fname = (char*)malloc(strlen(buffer) + 1); // null 값도 받아오기 위해서 +1을 해준다.
    if (p.fname != NULL)
        strcpy(p.fname, buffer);
    printf("%s %s \n", p.fname, p.lname);


    /* problem */
    
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);


    return 0;
}


char* s_gets(char* st, int n)
{
    return "none";
}

void cleanup(struct namect* pst)
{
    free(pst -> fname);
    free(pst -> lname);
}

void makeinfo(struct namect* pst)
{
    pst -> letters = strlen(pst -> fname) + strlen(pst -> lname);
}

void showinfo(const struct namect* pst)
{
    printf("%s %s your name contains %d letters. \n",
        pst-> fname, pst->lname, pst->letters);
}


```


#  14-10. 복합 리터럴(compound Literals)
----

구조체의 값을 임시로 잠깐 사용할 때 편하게 사용할 수 있는 복합 리터럴에 대해 살펴보자.

```c

#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL];
    char author[MAXTITL];
    // char* title, char* author은 추천하지 않음(자세한 내용은 14-09강 참고)
    float price;
}

struct rectangle
{
    double width;
    double height;
};


double rect_area(struct rectangle r)
{
    return r.width * r.height;
}

double rect_area_ptr(struct rectangle *r)
{
    return r->width * r->height;
}

int main()
{
    struct book book_to_read = {"crime and punishment", "fyodor dostoyevsky", 11.25f};
    // 이렇게 초기화가 끝난 후에는, 추가로 값을 바꾸려고 대입을 하면 에러가 난다.
    
    // 1. 그래서 아래와 같이 멤버별로 값을 대입해 줘야한다.
    strcpy(book_to_read.title, "alice in wonderland");
    strcpy(book_to_read.author, "lewis carroll");
    book_to_read.price = 20.3;

    // 2. 이렇게 하면 번거로울 테니, 새로운 struct에 초기화를 하여 생성하여 기존의 lvalue에 대입해주는 방법이 있다.
    struct book book2 = {"alice in wonderland", "lewis carroll", 20.3f};
    book_to_read = book2;

    // 3. 하지만, 값을 변경하기 위해 새로운 변수를 선언하는 것은 낭비일 수 있으며, 번거롭기도 하다.
    // 따라서 아래와 같이 "복합 리터럴"을 사용할 수 있다!!!!
    book_to_read  = (struct book){"alice in wonderland", "lewis carroll", 20.3f};
    // 괄호가 있고, 뒤에 마치 구조체를 초기화하는 것처럼 물결괄호 안에 값들을 넣어주면 된다.
    //// 중요: 우측에 있는 복합 리터럴은 rvalue가 아닌 lvalue라는 점!

    printf("%s %s \n", book_to_read.title, book_to_read.author);

    // 4. 응용: 만약, 변수가 어떤 추가적인 용도 하나 없고, 사각형의 영역을 계산하기 위해 선언된다면, 변수를 할당하는 게 별로일 수도 있다.
    // 따라서 아래와 같이 복합 리터럴을 사용하여 값을 구할 수 있다.
    // lvalue이기 때문에, 주소를 가져올 수 있다!!
    struct rectangle rec1 = {1.0, 2.0};
    double area = rect_area(rec1);
    area = rect_area( (struct rectangle) {1.0, 2.0});
    // 위와 같이, 복합 리터럴의 주소를 가져와서 rect_area_ptr() 함수에게 전달해주고 있다!

    area = rect_area_ptr( &(struct rectangle) { .height = 3.0, .width = 2.0}); //Designated initializer도 사용 가능하다.

    
}


```


# 14-11. 신축성 있는 배열 멤버(Flexible Array Members)

----

Array가 Flexible하다는 것은 길이가 변할 수 있는 배열을 의미한다. 


```c

int main()
{
    /* Flexible array memeber */

    struct flex
    {
        size_t count;
        double average;
        double values[]; // flexible array member (last member!)
        // 반드시 마지막에 선언해야 한다!          
    };

    const size_t n = 3;

    struct flex* pf1 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
    // 원래 구조체 크기만큼 동적 할당을 받는 것이 아니고, 그것에 추가로 배열로 사용하고 싶은 길이만큼 동적할당을 받는 것이다.
    // 기존 메모리 사이즈에서 double 3개가 나란히 있는 것이 추가로 배정될 것이다. 그것이 values[]의 배열처럼 사용할 수 있는 것이다.

    /* 
        주의사항 1
    */
    // 다음은 마지막 멤버를 포인터로 해두고 malloc으로 동적할당을 하는 경우이다. 위와 어떤 차이가 있는지 알아보자.
    struct nonflex
    {
        size_t count;
        double average;
        double *values; // use malloc()
    };

    struct nonflex nf;
    nf.values = (double*)malloc(sizeof(double) * n);
    // 차이점 1. 힙 메모리에 어디 있는지 알 수 없는 곳에 동적할당 메모리를 받고 -> 이를 배열로 사용할 수 있는 "동적할당배열"이 생성된다.
    // 이는 포인터 주소 자체를 조금 더 차지하고 있다. 
        //// 왜냐하면, flexible array member의 경우 앞에 있는 멤버(count, average)뒤에 동적할당을 추가로 받는 것이기 때문에 그걸 배열로 사용할 수 있는 것이고, 그것 자체가 어떤 "사이즈를 차지하진 않는다".
        //// 하지만, *values의 경우 포인터이기 때문에, 포인터 자체의 메모리를 차지하고 있다. 그것이 한 가지 차이이다. 

    // 차이점 2. 위의 동적할당 배열은 메모리의 어디에 위치하는지 알 수가 없다!
        //// 하지만, flexible array member의 경우, 앞의 멤버에 이어서 할당을 받은 것이기 때문에(malloc에 의해 일렬로 나열되기 때문에) 어디 있는지 확실하게 알 수 있다. 

    
    
    /* 
        주의사항 2 
    */
    
   struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
   if (pf2 == NULL) exit(1);

   *pf2 = *pf1; //Dont copy flexible members, use memcpy() instead
    // 이렇게 대입을 시도할 때 16바이트만(앞부분 멤버들만) 복사를 하게 된다! 그러면 우리가 추가로 요청한 배열은 복사가 되지 않는다!
    // 따라서 우리가 추가로 요청한 24바이트의 메모리는 복사가 되지 않는다! 
    // 컴파일러 입장에서는 거기에 대해 알 수 없다.(이유: 동적할당을 받아왔기 때문에)

}



    
```


<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171201499-99b87760-601f-4987-a740-e06c2acdaa43.png">


다음을 코드와 결과를 살펴보면, pf->value의 "주소"와 "값"이 동일하고, sizeof pf->value가 0이 나오는 등 조금은 낯선 결과가 나온다.

이는 n * sizeof(double)를 통해 추가로 메모리를 받아서 values[]로부터 시작되는 배열로 사용하기 때문이다. (코드 내 주의사항도 참고)


# 14-12. 익명 구조체(Anonymous Structures)

----

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171211076-e3037cb4-5a72-4ab3-8453-f1d83081ad51.png">

line 19를 보면 구조체 안에 이름이 없는 구조체가 있는 걸 볼 수 있다. 이를 anonymous structure라고 한다.

용법도 살펴보자.


<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171211454-ebd1dadb-38f1-41c7-8e36-452c11775699.png">

line 33을 보면, member access를 할 때 단계가 하나 줄어든 것을 볼 수 있을 것이다. 

- 요약: anonymous structure는 태그가 없는 형태로 선언하여 직접적으로 멤버를 접근하여 사용할 수 있다.

# 14-13. 구조체의 배열을 사용하는 함수
---

# 14-14. 구조체 파일 입출력 연습 문제
----

# 14-15. 공용체의 원리(Union)
----

공용체의 원리를 이해하기 위해 메모리 구조를 먼저 살펴보자.

```c

int main()
{
    /*
        Union
        - Store different data types in the same memory space
        - structure vs Union
        - 구조체와의 차이
            - 구조체와 달리, data type이 다르더라도 메모리를 하나로 모아주어 같이 사용한다!
    */

    union my_union
    {
        /* data */
        int i;
        double d;
        char c;
    };
    

    union my_union uni;

    printf("%zd\n", sizeof(union my_union)); // 8: 가장 큰 데이터 타입을 따르게 된다!
    printf("%lld\n",(long long)&uni);
    printf("%lld %lld %lld \n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);
    // 세 주소 모두 동일한 값이 나온다! 메모리를 공유하기 떄문

    

}

```


<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171345414-e7b849d0-65e5-44be-9668-40d1a0e4f6c5.png">


# 14-16. 공용체와 구조체를 함께 사용하기
---

자동차 정보를 구조체로 만들어보자. 

```c


/*
    unions and structures
*/

struct personal_owner
{
    /* data */
    char rrn1[7]; // Resident Registration Number
    char rrn2[8]; // ex: 981119-1230988
};

struct company_owner
{
    /* data */
    char crn1[4]; // company registration number
    char crn2[3]; // ex: 111-22-33333
    char crn3[6];
};



union data
{
    /* data */
    struct personal_owner   po;
    struct company_owner    co;
    // personal owner와 company owner 모두인 경우는 없다!!
};

struct car_data
{
    /* data */
    char model[15];
    int status; /* 0 = personal, 1 = company */
    union data ownerinfo;
};

void print_car(struct car_data car)
{
    printf("------------------------- \n");
    printf("Car model : %s \n", car.model);

    if ( car.status == 0)
        printf("Personal owner : %s - %s \n",
            car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
    else
        printf("company owner : %s - %s - %s \n",
        car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);

    printf("------------------------- \n");

    
}


```

# 14-17. 익명 공용체(anonymous unions)
---

익명 공용체의 문법은 익명 구조체의 문법과 비슷한 면이 많다.

익명 공용체로 만들어주는 방법은, 아래와 같이 union을 넣고 공용체 이름을 삭제해주면 된다.

```c
struct car_data
{
    /* data */ 
    char model[15];
    int status; /* 0 = personal, 1 = company */
    union {
    /* data */
    struct personal_owner   po;
    struct company_owner    co;
    // personal owner와 company owner 모두인 경우는 없다!!
    };
};
```

이렇게 되면 앞의 코드들보다 더욱 간결하게 이들을 호출할 수 있다.

```c
void print_car(struct car_data car)
{
    printf("------------------------- \n");
    printf("Car model : %s \n", car.model);

    if ( car.status == 0)
        printf("Personal owner : %s - %s \n",
            car.po.rrn1, car.po.rrn2);
    else
        printf("company owner : %s - %s - %s \n",
        car.co.crn1, car.co.crn2, car.co.crn3);

    printf("------------------------- \n");

    
}
```

# 14-18. 열거형(enumerated Types)
---

정수형 상수가 마치 이름이 있는 것처럼 사용할 수 있게 해주는 열거형 문법에 대해 알아보자.
```
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

int main()
{
    /*
        Enumerated type
        - Symbolic names to represent integer constants
        - Improve readability and make it easy to maintain
        - enim-specifier (struct-specifier, union-specifier)

        Enumerators
        - The symbolic constants
    */

    enum spectrum {red, orange, yellow, green, blue, violet}; // 이들은 내부적으로는 정수이다.

    enum spectrum color;
    color = blue;

    if (color  == yellow)
        printf("yellow"); // note: enumerates are not strings

    for (color = red; color <= violet; color++) // NOTE: ++ operator doesnt allowed in C+++, use type int.
        printf("%d\n", color);


    printf("red = %d, orange = %d\n", red, orange);

    enum kids {jackjack, dash, snoopy, nano, pitz};
    // nina has a value of 3
    enum kids my_kid = nano;
    printf("nano %d %d \n", my_kid, nano);

    enum levels { low = 100, medium = 500, high = 2000};

    enum pet { cat, dog = 10, lion, tiger};
    // puma has a value of 11
    printf("cat %d \n", cat);
    printf("lion %d\n", lion);

    return 0;


}
```

# 14-19. 열거형 연습문제
---

# 14-20. 이름공간 공유하기(Namespace)
---

```c

int iamfunction{
    return 0;
}

int main()
{
    /* 
        Namespace
        - Identify parts of a program in which a name is recognized
        - You can use the same name for one variable and on tag.
        - C++: use 'namespace' to use the smae identifiers in the duplicated scopes.
    */

   {
       int myname = 345;
       // double myname = 3.14; //ERROR
   }

    struct rect { double x; double y;};

    // int rect =123; // OK in C(but not ok in C++)
    struct rect rect = {1.1, 2.2}; // struct rect and rect are in different categories

    /*
        typedef struct rect rect;
        rect rect = {1.1, 2.2}; // NOT ok
    */

   // int iamfunction = iamfunction(); // error

   /*
        Namespace pollution(KNK p.465)
        - Names in different files accidentally conflicting with each other
        - 외울 필요는 없지만, 프로그램을 작성하다보면 한 번씩 겪게 될 일이다.
    */

   // printf("%d \n", a); // other.c

   return 0;
}


```

# 14-21. 함수 포인터의 원리(Function Pointers)
----

함수 포인터의 기본적인 선언 방법과 작동 원리를 메모리 레이아웃과 연관지어 살펴보자. 

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171536229-321e21ed-436d-4187-b61b-62a9dae400d9.png">

함수를 가리키는 포인터 변수를 출력할 때에는 입력과 반환값이 무엇인지 함께 지정해 주어야 한다. 무엇이 반환되는지 알고 있어야 실제로 함수를 호출할 때 실행시킬 수 있기 때문이다. 

문법상 함수의 주소를 가져올 때 &를 붙일수도, 그러지 않을 수도 있다. 하지만, 함수의 이름 자체가 내부적으로는 포인터이므로(함수가 실행될 때는 '그 주소'에 있는 코드가 실행되는 것) "이름 자체가 주소"이다.

# 14-22. 함수 포인터의 사용 방법
---

함수 포인터가 얼마나 프로그램을 만들어주는지, 사용방법을 알아보자.

이번 강의에서는 toupper, tolower 함수를 먼저 사용해보자.

```c

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void UpdateString(char* str, int (*pf)(int)) // 함수와 여기에 사용될 함수 자체를 파라미터로 받는다. 
// 함수 포인터를 통해 기능을 구현할 함수 포인터를 매개변수로 받는다. 그 포인터를 통해 뭔가를 실행시킨다.
{
    while (*str)
    {
        *str = (*pf)(*str); // 이 줄만 다른 함수와 다르다!!
        str++;
    }
}

int main()
{
    char str[]  = "Hello, world!";

    void (*pf)(char*);

    pf = ToUpper; // Name of a function is a pointer
    // pf = &ToUpper; // Acceptable
    // pf = ToUpper(str); // Not acceptable in C

    printf("string literal %lld\n", (long long)("hello world"));
    printf("Function pointer %lld\n", (long long)ToUpper);
    printf("Variable %lld\n", (long long)str);

    (*pf)(str);
    //pf(str);// K&R X, ANSI OK

    printf("ToUpper %s \n", str);

    pf = ToLower;

    pf(str);

    printf("ToLower %s\n", str);

    /* 
        Passing function pointers to funtions
    */

   UpdateString(str, toupper);

   printf("ToUpper %s \n", str);

   UpdateString(str, tolower);

   printf("ToLower %s\n", str);

   // NOTE: __cdecl is function calling convention
   // 함수 포인터를 선언할 때 // 함수 호출 규약에 대해 추후 공부하게 될 것(windows API 할때 알 것)

   return 0;
    

}

```


<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171589837-41a0f57d-b8b2-4f31-b029-b6aeffeae660.png">

string literal, function pointer는 Text segment에 위치하기 때문에 이 둘은 비슷한 자리에 위치하고, str은 variable으로 스택에 저장된다.

# 14-23. 자료형에게 별명을 붙여주는 Typedef
----

여러가지 typedef 용법에 대해 살펴보자.

```c

// 조금 더 복합하게 typedef를 사용할 때는 어떻게 하는지 살펴보자.

/* 
    One good way to synthesize declarations is 
    in small steps with typedef, ...
    - K&R book chapter 5.12
*/

/* Complicated Function Declarations *//

char char3[3] = { 'A', 'B', 'C'};

char(*complicated_function1())[3] // function returns pointer To Char[3]
{
    return &char3; // Returns a pointer to char[3] array
}

// case1: typedef를 사용하지 않은 경우
char(*(*fptr1)())[3] = complicated_function1;
//// 복잡함을 알 수 있다.

// case2: typedef를 사용한 경우
typedef char(*FRPTC())[3]; // Function Returns Pointer to char[3]
typedef char(*(*PFRPTC())[3]; 

FRPTC3 *fptr2 = complicated_function1;
PFRPTC3 fptr3 = complicated_function1;

//// 다음과 같이 아주 간결하게 사용할 수 있다.


//// 여기서 더욱 간단하게 이용할 수도 있는데, 다음과 같이 이용하면 된다.
/* Use typedef to make declarations simpler */

typedef char c3[3]; // 이렇게 typedef [3] 으로 선언해준다.

c3* complicated_function2() // 그러면 다음과 같이, 아주 간단하게 선언할 수 있다.
{
    return &char3; // Returns a pointer to char[3]
}



int main()
{
    /* 
        typedef specifier
        - Give symbolic names (or aliases) to types
            - 어떠한 자료형을 새로운 이름으로 다시 정의해준다.
        - Doesn't create new types.
            - 주의: 이름만 바꿔주는 것이지, 새로운 자료형을 만드는 것은 아니다!
        - 
    */

   typedef unsigned char BYTE; // note the scope of BYTE
    // 다음과 같이 긴 길이의 타입을 계속 사용할 때 편리하다.

   BYTE x, y[10] = {0, }, * z = &x;

   {
       typedef unsigned char byte; // You can use lowercases as well.

        /* Portable data types */
        
        size_t s = sizeof(byte); // unsigned int (x86), unsigend long long (x64)
        // unsigned int s = sizeof(byte); // x86
        // unsigned long long s = sizeof(byte) // x64

   }

   // byte b; // typedef definition has a scope 

   /*
        This function returns the time since 00:00:00 UTC, January 1, 1970 (unit timestamp)
        in seconds.
    */

   time_t t = time(NULL);

   printf("%lld \n", t);

   /*
        typedef vs #define
    */

   typedef char* STRING;

   STRING name = "John wick", sign = "world";

   /*
        - typedef interpretation is performed by the complier, not the preprocessor
            - define은 전처리에 의해 처리됨(복사 붙여넣기로 처리됨) 
            - typedef는 컴파일러에 의해 전처리됨
        - More flexible than #define

        #define STRING char*

        SRTING name, sign;
        char * name, sign; // Note the type of sign
        //// 문제점: 이렇게 되면 문법 상 sign은 포인터가 아니게 된다!

    */

    typedef struct complex {
        float real;
        float imag;
    } COMPLEX; // typedef struct complex COMPLEX

}
```


# 14-24. 복잡한 선언을 해석하는 요령
---


실무에서는 아래와 같이 복잡한 선언 때문에 머리를 싸맬 일은 없을 것이다. typedef를 통해 이해하기 쉬운 형태로 정리하는 것이 좋은 방법이라는 것을 인지하자. 다만, 원리를 아는 것은 도움이 될 것이다.

```c
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
```

# 14-25. qsort() 함수 포인터 연습문제
----

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/171656516-fd5ccaed-c81f-4a65-a31d-9ad7ada03e4e.png">

