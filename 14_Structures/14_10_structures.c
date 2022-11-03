#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// #define MAXTITL 41
// #define MAXAUTL 31

// struct book
// {
//     char title[MAXTITL];
//     char author[MAXTITL];
//     // char* title, char* author은 추천하지 않음(자세한 내용은 14-09강 참고)
//     float price;
// }

// struct rectangle
// {
//     double width;
//     double height;
// };


// double rect_area(struct rectangle r)
// {
//     return r.width * r.height;
// }

// double rect_area_ptr(struct rectangle *r)
// {
//     return r->width * r->height;
// }

// int main()
// {
//     struct book book_to_read = {"crime and punishment", "fyodor dostoyevsky", 11.25f};
//     // 이렇게 초기화가 끝난 후에는, 추가로 값을 바꾸려고 대입을 하면 에러가 난다.
    
//     // 1. 그래서 아래와 같이 멤버별로 값을 대입해 줘야한다.
//     strcpy(book_to_read.title, "alice in wonderland");
//     strcpy(book_to_read.author, "lewis carroll");
//     book_to_read.price = 20.3;

//     // 2. 이렇게 하면 번거로울 테니, 새로운 struct에 초기화를 하여 생성하여 기존의 lvalue에 대입해주는 방법이 있다.
//     struct book book2 = {"alice in wonderland", "lewis carroll", 20.3f};
//     book_to_read = book2;

//     // 3. 하지만, 값을 변경하기 위해 새로운 변수를 선언하는 것은 낭비일 수 있으며, 번거롭기도 하다.
//     // 따라서 아래와 같이 "복합 리터럴"을 사용할 수 있다!!!!
//     book_to_read  = (struct book){"alice in wonderland", "lewis carroll", 20.3f};
//     // 괄호가 있고, 뒤에 마치 구조체를 초기화하는 것처럼 물결괄호 안에 값들을 넣어주면 된다.
//     //// 중요: 우측에 있는 복합 리터럴은 rvalue가 아닌 lvalue라는 점!

//     printf("%s %s \n", book_to_read.title, book_to_read.author);

//     // 4. 응용: 만약, 변수가 어떤 추가적인 용도 하나 없고, 사각형의 영역을 계산하기 위해 선언된다면, 변수를 할당하는 게 별로일 수도 있다.
//     // 따라서 아래와 같이 복합 리터럴을 사용하여 값을 구할 수 있다.
//     // lvalue이기 때문에, 주소를 가져올 수 있다!!
//     struct rectangle rec1 = {1.0, 2.0};
//     double area = rect_area(rec1);
//     area = rect_area( (struct rectangle) {1.0, 2.0});
//     // 위와 같이, 복합 리터럴의 주소를 가져와서 rect_area_ptr() 함수에게 전달해주고 있다!

//     area = rect_area_ptr( &(struct rectangle) { .height = 3.0, .width = 2.0}); //Designated initializer도 사용 가능하다.

    
// }

//// 11

// int main()
// {
//     /* Flexible array memeber */

//     struct flex
//     {
//         size_t count;
//         double average;
//         double values[]; // flexible array member (last member!)
//         // 반드시 마지막에 선언해야 한다!          
//     };


//     const size_t n = 3;

//     struct flex* pf1 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
//     // 원래 구조체 크기만큼 동적 할당을 받는 것이 아니고, 그것에 추가로 배열로 사용하고 싶은 길이만큼 동적할당을 받는 것이다.
//     // 기존 메모리 사이즈에서 double 3개가 나란히 있는 것이 추가로 배정될 것이다. 그것이 values[]의 배열처럼 사용할 수 있는 것이다.

//     /* 
//         주의사항 1
//     */
//     // 다음은 마지막 멤버를 포인터로 해두고 malloc으로 동적할당을 하는 경우이다. 위와 어떤 차이가 있는지 알아보자.
//     struct nonflex
//     {
//         size_t count;
//         double average;
//         double *values; // use malloc()
//     };

//     struct nonflex nf;
//     nf.values = (double*)malloc(sizeof(double) * n);
//     // 차이점 1. 힙 메모리에 어디 있는지 알 수 없는 곳에 동적할당 메모리를 받고 -> 이를 배열로 사용할 수 있는 "동적할당배열"이 생성된다.
//     // 이는 포인터 주소 자체를 조금 더 차지하고 있다. 
//         //// 왜냐하면, flexible array member의 경우 앞에 있는 멤버(count, average)뒤에 동적할당을 추가로 받는 것이기 때문에 그걸 배열로 사용할 수 있는 것이고, 그것 자체가 어떤 "사이즈를 차지하진 않는다".
//         //// 하지만, *values의 경우 포인터이기 때문에, 포인터 자체의 메모리를 차지하고 있다. 그것이 한 가지 차이이다. 

//     // 차이점 2. 위의 동적할당 배열은 메모리의 어디에 위치하는지 알 수가 없다!
//         //// 하지만, flexible array member의 경우, 앞의 멤버에 이어서 할당을 받은 것이기 때문에(malloc에 의해 일렬로 나열되기 때문에) 어디 있는지 확실하게 알 수 있다. 

    
    
//     /* 
//         주의사항 2 
//     */
    
//    struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
//    if (pf2 == NULL) exit(1);

//    *pf2 = *pf1; //Dont copy flexible members, use memcpy() instead
//     // 이렇게 대입을 시도할 때 16바이트만(앞부분 멤버들만) 복사를 하게 된다! 그러면 우리가 추가로 요청한 배열은 복사가 되지 않는다!
//     // 따라서 우리가 추가로 요청한 24바이트의 메모리는 복사가 되지 않는다! 
//     // 컴파일러 입장에서는 거기에 대해 알 수 없다.(이유: 동적할당을 받아왔기 때문에)

// }




//// 13

