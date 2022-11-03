# 12-01. 메모리 레이아웃 뤁어보기

---

이번 강의에서는 그림을 익히는 정도만 하고, 추후에 하나하나 상세하게 설명할 예정이다.

## 프로그램이 시작될 때

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162195132-7250e71d-365a-49e9-94dc-08931a5f8d06.png">

<br>

## 프로그램 전체에서 계속 사용되는 변수들

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162195504-73151a0f-53f7-4e03-9e96-e621e11f291c.png">
<br>

어디서나 접근해서 값을 저장하고 가져올 수 있다. 프로그램이 종료될떄까지 메모리에 남아있다.

## 프로그램의 일부에서 큰 메모리가 필요한 경우

운영체제나 컴파일러는 효율을 매우 중시하도록 만들어졌다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162195776-95e0845c-bf4f-4e0a-a7a1-6743213aa43c.png">
<br>

메모리를 항상 갖고 있는 것은 부담스럽다. 운영체제, 컴파일러 입장에서도 권장하고 싶지 않다. 따라서, 지역적으로 사용될 수 있는 변수를 선언할 수 있고, 이들을 local variable이라고 부른다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162196155-2a4cbbef-4ab8-45a3-bf93-bcace5403b6a.png">
<br>

이 지역변수들은 `스택`이라는 메모리에 저장된다. 이들은 실행이 될때, 블록에 속하는 코드가 실행이 될 때만 메모리에 들어간다. 따라서, 그 외의 경우에는 메모리를 차지하지 않는다.(정확히는, 해당 메모리가 다른 곳에 사용될 수 있도록 운영체제에게 관리 권한을 다시 넘겨준다.) 이와 같이 스택은 보다 효율적으로 메모리를 관리할 수 있다는 장점이 있다.

이를 더 효율적으로 사용하기 위해서는 다음과 같이 함수를 선언하여 함수가 호출될 때에만 메모리를 사용하도록 할 수 있다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162197185-46f2eb51-b2ac-45dd-844c-befdb863cec9.png">
<br>

## 필요한 메모리의 크기를 미리 알 수 없을 경우

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162199054-e4616251-296a-4557-ae3d-bc101d78552d.png">
<br>

힙에 올라오는 동적할당 메모리 같은 경우, 메모리를 받아서 아에 사용하지 않을수도 있고, 다 사용했더라도 반납을 하지 않을수도 있다. 따라서, 해당 문제를 해결하기 위해 프로그래머가 직접 메모리를 반납해야 한다. 이것이 처음 C를 배울 때 가장 많이 하는 실수 중 하나이다. 추후 자료구조를 공부할 때 만날 런타임 에러의 원인이기도 하다.

# 12-02. 객체와 식별자, lvalue와 rvalue

---

```c

//// 12.2
int main()
{

    /*
        Object
        - An Object is simply a block of memory that can store a value.
        - Object has more developed meaning in C++ and OOP

        Identifiers
        - Names for variables, functions, macros, and other entitles.

    */

   int var_name = 3; // creates an object called 'var_name'

   int* pt = &var_name; // pt is an identifier.
   *pt = 1;         // *pt is not an identifier/ *pt designates an object.

    int arr[100]; // arr is an identifier. Is arr an object?
    // No! arr is just an address of the first value

    arr[0] = 7; // arr[0] is an object. // identifier는 아니지만, expresssion을 통해 메모리 공간에 접근할 수 있다.


    /*
        lvalue is an expression 'referring' to an object.

        L-value: left side of an asssignment
        R-value: right side, variable, constant, expressions

    */

   var_name = 3; // modifiable lvalue

   pt = &var_name;
   int* ptr = arr;
   *pt = 7; // *pt is not an iddentifier but an modifiable lvalue expression.

   int *ptr2 = arr + 2 * var_name; //addres rvalue(그냥 주소"값"이다)
    *(arr + 2 * var_name) = 456; // lvalue expression //하지만 indirection을 붙여주면 접근 가능

    const char* str= "constant sstring"; // str is a modifiable lvalue
    str = "second string"; // so it cannot be used as a Lvalue (ex. constant string = second string)
    //str[0] = 'A'; // Error

    char str2[] = "string in an array";
    str2[0] = 'A'; // OK
    //puts(str2);

    /*

        Identifiers have scope.
        Objects have storage duration.
        Variables and functions have one of the following linkages"
            external linkage, internal linkage, or no linkage.s

    */

   return 0;


}
```

- Object는 메모리 공간에서 얼마나 위치할지에 대한 "기간" 개념이 있다.
- Identifier는 Object에 대한 이름 역할을 해준다.
  - 이름이 바뀔수도 있고, 없을수도 있다!

# 12-03. 변수의 scope(영역)와 linkage(연결 상태), 그리고 객체의 duration(지속 기간)

---

file 영역이란 모든 함수의 밖에 선언된 스코프이다. 이를 전역 변수(global variable)이라고 부르기도 하는데, linkage 개념이 조금 연결되어 있으므로 추후에 더 자세히 알아보자.

file scope에 대해 둘러보자.

```c

/*
    Variable scopes(visibility)
    - block, function, function prototype, file.
*/

int g_i = 123; //glb variable
int g_j;

void func1()
{
    g_i++; //uses g_i
}

void func2()
{
    g_i += 2;
    //local = 456; error
}


int main()
{
    int local = 1234;

    func1();
    func2();

    printf("%d\n", g_i);    // uses g_i
    printf("%d\n", local);
    printf("%d\n", g_j);    //0 // not initialized?
    // 초기화되지 않은 전역 변수(혹은 정적 변수)들은 bss라는 메모리 공간에 저장되고, 해당 공간내의 변수들은
    // 프로그램이 시작될 때 전부 0으로 초기화를 해준다.

    return 0;

}
```

이번엔 block, function, function prototype scope에 대해 살펴보자.

```c

void f1(int, double); // to the end of the prototype declaration

double func_block(double d)
{
    double p = 0.0;

    for (int i = 0; i<10; i++)
    {
        double q = d* i;
        p *= q;

        if (i==5)
            goto hello; // rarely used
    }

hello:
    printf("Hello, World");

    return p;

}
```

파일 스코프에 있는 변수는 마치 프로그램 전체(다른 c 파일)에서 사용될 수 있기 때문에 전역 변수(global variable)이라고 한다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165046001-b27cde74-1d6f-4f7f-b392-973ef976c0c4.png">

el의 값이 잘 변경되었다.

따라서, 어느 translation unit에서든 사용할 수 있기 때문에, global variable이라고 부른다.

static을 앞에 붙여두면 다른 파일에서 사용할 수 없다. (사용하려 하면 LNK 에러가 날 것이다)

따라서, 다른 폴더에서도 접근가능한 변수를 external linkage라고 하며, 그렇지 않은 변수를 iternal linkage라고 한다.

이번엔 duration 예제를 살펴보자.

static storage는 프로그램이 실행된 이후 종료되기 전까지 재정의되지 않는다!! 아래 코드를 보며 이해해보자.

자세한 설명은 추후 예정이다.

```c


/*
    Storage duration에는 4가지 duration이 있다.
    - static storage duration: 프로그램의 시작부터 끝까지 'static'하게 머문다.
    (NOTE: 'static' keyword indicates the linkage type, not the storage duration)
    - automatic storage duration:
    - allocated storage duration: 동적할당과 관련이 있음
    - thread storage duration: 멀티스레딩 개념
*/

void count()
{
    int ct = 0;
    printf("count %d\n", ct);
    ct++;
}

void static_count()
{
    static int ct =0; // 끝날때까지 재선언되지 않는다.
    printf("static count = %d \n", ct);
    ct++;
}


```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165048043-34be9d79-a190-4ab5-a9f2-547b55019cd7.png">

# 12-04. 저장 공간의 다섯 가지 분류(Five Storage Classes)

---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165048486-ca5cee9c-fc25-4ec1-a2b7-19064a469cda.png">

어떤 언어이든지 간에 내부적으로 이렇게 사용된다는 점을 알아두면 언어를 배우는 데 아주 큰 도움이 될 것이다.

'분류가 이렇게 되는구나' 정도로만 알고 있으면 된다. 추후 강의에서 코드 실습을 하며 체득할 예정이다.

# 12-05. 자동 변수(automatic stroage)

---

자동이라는 말을 들으면,"무엇이 자동인가"라는 궁금증이 생길 것이다.

automatic scope는 기간을 자동으로 지정해준다. 그래서 프로그램 전체의 메모리 사용량을 자동으로 최적화해준다.

이들은 꼭 초기화를 해줘야 한다. 전역 변수의 경우 프로그램이 실행되는 동안 단 한번만 선언되면 되기 때문에, 컴파일러가 0으로 초기화를 해준다. 하지만 automatic variable에는 초기화를 해주지 않는다. 모든 지역변수들을 초기화해주면 메모리 상으로도 오버로드가 발생할 가능성이 높기 때문이다.

```c

/*
    automatic storage class
    - Automatic storage duration, block scope, no linkage
    - Any variable declared in a block or function header
*/

void func(int k);

int main() // NOTE; main() is a function
{
    auto int a; // keyword auto: a storage-classs specifier
    // auto를 붙이지 않아도 지역변수가 선언된다. (동일)
    a = 1024;
    auto int b = a * 3; // what happends if uninitialized?

    int i = 1;
    int j = 2;

    printf("i %lld \n", (long long)&i);

    {
        int i = 3;// name hiding
        printf("i %lld \n", (long long)&i);

        // j is visible here: 더 큰 영역에서 이미 지정이 되었기 때문에 가능함
        printf("j = %d \n", j);

    }

    // ii iss not visible here

    printf("i %lld \n", (long long)&i); // 위쪽 i

    for (int m = 1; m<2; m++)
        printf("m %lld \n", (long long)&m); //no block?

    func(5);  // cannot see any of the variabled defined so far.

    for (int m = 3; m< 4; m++)
    {
        printf("m %lld \n", (long long)&m);
    }


}

void func(int k)
{
    int i = k * 2;
    // do something with i and k
    printf("i %lld \n", (long long)&i);
}

```

# 12-06 레지스터 변수

---

레지스터 변수는 레지스터 스토리지 클래스에 포함된다. 크게 보면 자동 변수와 묶여서 설명 될 때가 많다. **메모리에서의 위치가 레지스터(또는 스택)**라는 점이 자동 변수와 다른 점이다.

변수를 선언할 때 "register"를 붙여서 레지스터에 변수가 저장되도록 "요청"할 수 있다. 모든 요청을 받아주진 않고, 컴파일러가 이를 결정한다.

또한, 레지스터 변수로부터는 주소를 가져올 수 없다!!

# 12-07. 블록 영역의 정적 변수

---

## Static with no linkage

현재 여러가지 저장공간을 배우고 있는데, 고정적이면서 블록 스코프(블록 내에서만!)를 갖는 변수를 우리가 사용할 수 있다. 또한, linkage가 없다. 하지만 포인터 등을 통해 간접적으로 접근할 수 있다. **다만, 블록 안에서 사용하는 이 변수를 굳이 블록 밖에서 사용하고 싶다면, static with no linkage를 사용할 필요가 없을 것이다.**

- 고정적: 프로그램의 시작부터 끝까지 계속 메모리를 차지하고 있다.

```c

void count()
{
    int ct =0;
    printf("count = %d %lld \n", ct, (long long)&ct);
    ct++;

    // TODO return &ct;
}

void static_count()
{
    static int ct =0;
    printf("count = %d %lld \n", ct, (long long)&ct);
    ct++;

    // TODO return &ct;
}

void counter_caller()
{
    count();
}


void static_counter_caller()
{
    static_count();
}



int main()
{
    count();
    count();
    counter_caller();

    count();
    count();
    static_counter_caller();

    return 0;
}
```

```s
>> count = 0 6132953916
>> count = 0 6132953916
>> count = 0 6132953900
>> static count = 0 4333961216
>> static count = 1 4333961216
>> static count = 2 4333961216
```

결과는 다음과 같이 나오며, count()의 경우 지역변수이기 때문에 counter caller()를 사용하면 다른 메모리로 초기화된 것을 확인할 수 있다. 반면 static의 경우 동일한 메모리를 참조하며, 값 또한 재정의되지 않음을 확인할 수 있다.

# 12-08. 정적 변수의 외부 연결 external linkage

---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165693355-6368c0c4-c0b2-4268-85d7-3c989cc77e30.png">

```c

/*
    static variable with external linkage
    - File scope, external linkage, static sotrage duration
    - External storage class
    - External variables
*/

int g_int = 0;
double g_arr[1000] = { 0.0, };

/* initializing External variables */

int x = 5;          //ok, constant expression
int y = 1+ 2;       // ok, constant expression
size_t z = sizeof(int); //ok, sizeof is a constant expressoin
//int x2 = 2 * x;         // not ok! x is a variable. variable cannot be used when initializing

void fun()
{
    printf("g_int in fun() %d %p \n", g_int, &g_int);
    g_int +=10;
}

int main()
{
    /*
        defining declaration vs referencing declaration
    */

   extern int g_int; // optional
   // extern int g_int = 1024; // error in block scope

    //int g_int = 123;

   extern double g_arr[]; // optional, size is not necessary

   printf("g_int in main() %d %p \n", g_int, &g_int);
   g_int += 1;

   fun();

   return 0;

}

```

위 코드에서 살펴보면, extern을 해주지 않고 main()과 fun() 함수에서 동일한 g_int를 설정하게 되면, name hiding이 발생한다.

따라서, extern을 통해 해당 블록의 밖에서 file scope 외부 식별자를 명확하게 선언할 수 있다.

> plus: g\_는 'global'의 의미를 가지고 있다.

# 12-09. 정적 변수의 내부 연결(internal linkage)

---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165698253-d1805181-c90e-48a7-ae52-2cd76baa8ee0.png">

# 12-10. 변수의 저장 공간 분류 요약 정리

---

크게 두 가지 분류(자동, 레지스터)(static)으로 나눌 수 있다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165702061-9493a55b-65f2-4e5a-bd23-3f8531f68f0e.png">

# 12-11. "함수"의 저장 공간 분류

---

지금까지는 변수의 저장 공간에 대해 분류해보았다. 이번엔 함수의 저장공간 분류를 알아보자.

```c

/*
    storage classes and functions
    - Functions external or static
    - A function delaration is assumed to be extern
*/
```

# 12-12. 난수 생성기 모듈 만들기 예제

---

난수 생성기를 만들어보자.

컴퓨터는 기계이기 때문에 완전한 난수를 생성하는 것은 아니다. 사람이 보기에 "난수 같이" 출력된다고 느껴질 것이다.

```c

#include <stdlib.h> // srand()
#include <time.h> // time()

int main()
{
    /*
        rand()
        - 0 to RAND_MAX (typically INT_MAX)
        - defined in stdlib.h.
    */

   srand(1); // random seed
   srand((unsigned int) time(0));

   for (int i = 0; i<3; i++)
   {
       printf("%d \n", rand());
       //printf("%d \n", rand() % 6 + 1);s
   }

    unsigned int next = 1;

    for (int i = 0; i< 3; ++i)
    {
        next = next * 1103515245 + 1234;
        next = (unsigned int) (next / 65536) % 32768;
        printf("%d \n", (int) next);
    }

    return 0;

}
```

# 12-13. 메모리 동적 할당(Dynamic Storage Allocation)

---

"동적"이라는 단어의 의미는 컴파일 타임이 아닌 런타임에 의해 결정이 된다는 것을 의미한다. 지금까지 배워온 storage classes와 가장 큰 차이가 될 것이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165749339-8c6de740-3baa-443a-a127-8bba6458c40a.png">

제일 아래쪽의 동적 할당 메모리가 보인다. 동적할당 메모리는 포인터만 가져오고 인식자가 없다!! 즉, 변수의 이름이 없다는 것이다.

**가장 중요한 차이는 동적할당 메모리는 힙에 들어간다는 것**이다! 필요할 때마다 메모리를 요청하고, 사용 후 반납을 하는 일련의 과정들을 수동으로 관리해주어야 한다. 한 번 메모리 할당을 받으면 힙에 존재한다.

- 예를 들어, automatic의 경우는 블록 안에서 선언되어 프로그램 실행 과정에 따라 자동으로 스택에 넣었다 빼줬다 한다.

- 하지만, 힙에 동적 할당 메모리가 자리를 잡으면 두 가지 경우가 있다.
  - 프로그래머가 종료하는 경우
  - 프로그램이 끝나고 나서 운영체제가 강제로 회수하는 것

**필요한 메모리의 크기를 미리 알 수 없을 경우, 런타임이 되어 봐야 알 수 있는 경우** 동적할당 메모리를 사용하는 것이 일반적이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165750091-1b991826-204e-4639-aba7-4e70c1472663.png">

사진 속 코드에서 확인할 수 있듯이, 메모리를 모두 사용한 후에는 `free()` 선언을 하여 메모리를 반납하게 코드를 짜야 한다.

```c

int main()
{
    float x;
    char str[] = "Dancing iwth a Star";
    int arr[100];

    /*
        malloc(): returns a void type pointer.
        void* : generic pointer라고 불리기도 한다.(이유: 순수한 주소이기 때문)
            - void* pointer는 자료형 연산을 사용할 수 없다. 왜냐하면 자료형이 정해지지 않았기 때문이다.

        free() deallocates the memory
    */

   double* ptr = NULL;

   ptr = (double*)malloc(30* sizeof(double));
    // malloc() 내에는 사이즈를 지정해주면 된다.
    // 추후에는 훨씬 더 큰 메모리를 넣어줘야 할 것이다.
    // 위과 같이 형변환(타입캐스팅)을 하여 특정한 자료형인 것처럼 사용할 수 있다.
    // 배열처럼 사용하게 되는 것이 대부분이다.

    if (ptr == NULL) // memory를 너무 큰 공간을 할당하여 에러가 할당을 못할때(null)도 있다.
    {
        puts("memory allocation failed");

        /*
            exit(EXIT_FAILURE) is similar to return 1 IN main().
            exit(EXIT_SUCCESS) is similar to return 0 IN main().
        */

       // memory 가 null인 경우 더이상 프로그램이 진행되지 않을 정도로 심각한 문제이기 때문에, 이를 종료시킨다.
       // debug 할 때도 자주 사용한다.
       exit(EXIT_FAILURE);
    }

    printf("Before free %p \n", ptr);

    free(ptr); // no action occurs when ptr is NULL

    printf("After free %p \n", ptr); // before free address와 동일하다.
    // 이유: 해당 포인터에 값은 없어지지만, 포인터 "주소"는 남아있을 것

    ptr = NULL; // optional

    /* Dynamically Allocated Array */

    int n = 5;
    ptr = (double *)malloc(n*sizeof(double)); // variable도 할당 가능

    if (ptr != NULL) //if(!ptr)
    {
        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);

        printf("\n");
        printf("\n");

        for (int i = 0; i<n; ++i)
            * (ptr + i) = (double)i;
        printf("\n");
        printf("\n");

        for (int i = 0; i < n; ++i)
            printf("%f ", ptr[i]);

        printf("\n");
        printf("\n");
    }

    free(ptr);
    ptr = NULL;

    /*
        comparision to VLA (Variance Length Arrays)

        VLA
        - not supported by compilers.
        - automatic duration, cannot be resized
        - limited by stack size (when complier plcaes VLA in stack segment)
    */

   return 0;

}
```

메모리를 이렇게 할당받고 반납하는 것이 번거로울 수 있다. 처음에만 이렇게 배우고, 추후에 파이썬이나 C++ 등 다른 언어를 사용할 때는 이 과정을 자동으로 처리해준다.

하지만, 처음에 공부할 때 이렇게 배우는 것은 아주 큰 도움이 될 것이다.

# 12-14. 메모리 누수와 free의 중요성

## (+ 비쥬얼 스튜디오 진단 도구 사용법)

```c

int main()
{
    printf("Dummy output \n");

    { // ptr이라는 식별자(idenfier)는 이 블럭 내에서만 살아있다.
        int n = 1000000; // x86, x64 차이가 있다. 실무에서는 64를 많이 쓸 것
        int* ptr = (int*)malloc(n*sizeof(int));

        if (!ptr)
            printf("Malloc failed \n");
            exit(EXIT_FAILURE);

        for (int i =0; i<n; ++i)
            ptr[i] = i + 1;

        free(ptr);
        // ptr = NULL; // 사용하지 않아도 되지만, 명확하게 하려면 사용하는 것을 추천(교수님은 사용)
    }

    // what happens?

    printf("Dummy output \n");

    return 0;
}
```

# 12-15. 동적 할당 메모리를 배열처럼 사용하기

---

```c

int main()
{

   /*
        1D array
    */

   int n =3;
   int * ptr= (int*)malloc(sizeof(int) * n);
   if (!ptr) exit(1);

   ptr[0] = 123;
   *(ptr + 1) = 456;
   *(ptr + 2) = 789;

    free(ptr);
    ptr = NULL;

    /*
        2D array
    */

   int row = 3, col =2 ;
   int (*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row* col);
   //int (*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col)); // VLA

    if (!ptr2d) exit(1);

    for (int r = 0; r < row; r++)
        for (int c = 0; c< col; c++)
            ptr2d[r][c] = c + col * r;

    for (int r = 0; r< row; r++)
    {
        for (int c = 0; c < col; c++)
            printf("%d ", ptr2d[r][c]);
        printf("\n");
    }

```

1차원 배열을 2, 3, .. 차원 배열처럼 사용을 할 수도 있다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165764471-64abb203-0601-42aa-a801-1f16d0e34fbd.png">

```c


    /*
        2D array like 1D
    */

   int row = 3, col = 2;
   int* ptr = (int*)malloc(row*col*sizeof(int));
   if (!ptr) exit(1);

   for (int r = 0; r < row; r++)
        for(int c = 0 ; c< col; c++)
            ptr[c + col*r] = c + col *r;

    for (int r = 0; r< row; r++)
    {
        for (int c = 0; c < col; c++)
            printf("%d ", *(ptr + c + col *r));
        printf("\n");
    }
}
```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165766305-c100a546-7de2-4c9b-a6ae-9889c53ef505.png">

3차원 형태도 다음과 같이 표현할 수 있다.

# 12-16. calloc(), realloc()

---

malloc() 보다 기능이 많은 두 함수를 사용해보자.

malloc() 함수는 메모리를 할당만 하고 초기화해주지 않는다. 하지만 calloc()은 0으로 초기화해준다.

```c


int main()
{
    int n = 10;

    int* ptr = NULL;

    //ptr = (int*)malloc*(sizeof(int) * n)
    ptr = (int*)calloc(n, sizeof(int)); // contiguous allocation
    if (!ptr)
        exit(1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ptr[i]);
    printf("\n");

    /*
        realloc() ( = re allocation)
        - doesn't initialize the bytes added
        - returns NULL if can't enlarge the memory block
        - If first argumment is NULL, it behaves like malloc()
        - if second argument is 0, it fress the memory block.
    */

    for (int i = 0; i<n; ++i)
        ptr[i] = i + 1;

    n = 20;

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int));
    // ptr = (int*)realloc(ptr, n * sizeof(int));

    printf("%p %p \n", ptr, ptr2);
    printf("%d \n", ptr[0]);

    if (!ptr2)
        exit(1);
    else
        ptr = NULL;

    for (int i =0; i<n; ++i)
        printf("%d ", ptr2[i]); //copies data

    free(ptr2);

}
```

# 12-17. 동적 할당 메모리와 저장 공간 분류

---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165770454-611d7035-17b7-4fb9-8da7-d53d122c2a25.png">

local pointer, function pointer의 경우 주솟값이 높은 것을 확인할 수 있다.

# 12-18. 자로형 한정자들(type qualifiers)

## (const, volatile, restrict)

> 실질적으로는 한정보다는 '권한을 부여한다'의 의미가 크다.

```c

int main()
{
    /*
        Const
    */

   typedef const int zip;
   const zip q = 8; // == const const int zip 과 같을 것이다. 이러면 에러가 나야 하지만, 이를 에러가 나지 않게 자동으로 처리해준다.

   const int j = 123;
   const int arr[] = {1,2,3};

   float f1 = 3.14f, f2 = 1.2f;

   const float* pf1 = &f1;
   // const 변수값은 바뀌지 않지만, pf1이라는 포인터 변수 자체는 다른 값을 가질 수 있다!!
   pf1 = &f2;
   // 하지만 indirection을 한 값을 바꿀수는 없다. // *pf1 = 5.0f -> error

    // 아래와 같이 하면, 반대로 indirection 값을 바꿀수 있고, 포인터 변수를 바꿀 수 없게 된다.
   float* const pf2 = &f1;
   *pf2 = 6.0;
   //pf2 = &f2; // Error!

    // both of them cannot be
   const float* const pf3 = &f1;

   /*
        global constants
    */

   /*
        volatile
        - Do not optimize
        - ex: hardward clock
        - 컴파일러가 알 수 없는 값에 의해 값이 바뀔 수 있다!
        - 결과적으로 컴파일러에게 "너가 최적화하지마라"라는 의미이다.
    */

   volatile int vi = 1; //volatile location
   volatile int* pvi = &vi; // points to a volatile location

   int i1 = vi;

    // 변경 사항...

    int i2 = vi; // 위에서 컴파일러가 모르게 운영체제가 값을 바꿔버리면 i2 값도 바뀔 것이다.
    // 이를 방지하기 위해서 사용한다.

    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    int* par = ar;

    /*
        restrict: pointer가 "동적할당 받아온 메모리"를 다른 포인터나 다른 수단을 이용하여 접근하지 않겠다는 것을 의미한다.
        - sole initial means of accessing a data object
        - compiler can't check this restriction
    */

    int* __restrict restar = (int*)malloc(10*sizeof(int));

    if (!restar)exit(1);

    ar[0] += 3;
    par[0] += 5; // 사실 이 둘은 동일하다.
    // par[0] += 8; // 따라서 8을 한번에 더하는 것과 동일할 것이다. 따라서 컴파일러 입장에서는 이렇게 최적화하고 싶을 것이다.
    // 어찌됐든 컴파일러 입장에서 이들은 다른 이름이기 때문에 최적화를 못 해준다.

    restar[0] += 3;
    restar[0] += 5;
    // restar[0] += 8; // 하지만 restrict 선언을 해주면 compiler가 자동으로 이를 수행해줄 수도 있다.
    // 왜냐하면 "(int*)malloc(10*sizeof(int));"에 접근할 수 있는 게 어차피 restar 밖에 없기 때문에 이들이 동일한 것을 지칭한다는 것을 이해할 수 있게 된다.

    free(restar);

    return 0;
}
```

주의할 점은 컴파일러는 실제로 restriction을 체크할 수 없다는 것이다.

# 12-19. Multi-Threading

---

멀티쓰레딩 공부를 언젠가 해야하며, c++ 마지막 쯤에서 멀티스레딩 공부를 하면 효율적일 것이다. c++에서는 멀티스레딩을 공부할 표준 라이브러리가 있기 때문이다.

이번 강의에서는 "씨언어도 멀티스레딩이 된다"라는 점과 씨언어에서 멀티스레딩을 하기 위한 최소한의 개념만 숙지하고 넘어가자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165776222-d734a133-e708-41a3-9fc2-8b4d3a5a8939.png">

프로그램을 실행하면 프로세스에서 실행이 된다. 프로그램을 실행시켜나가는 흐름을 이야기한다.

프로그램이 진행되다가 main thread가 다른 thread를 실행할 수 있다.

이러한 기술들을 동시성 프로그래밍이라고 한다.

- 하나의 전역변수를 여러 개의 thread가 사용하려고 하면 어떻게 될까??

- 경쟁이 일어나게 된다!!

데이터는 기본적으로 메모리에 저장되어 있는데, 이 값을 cpu로 전송을 하면 cpu 내부의 레지스터에 값을 올려두고 작업을 한다라는 것을 배운 적이 있을 것이다. 이후 작업이 끝나면 해당 값을 메모리로 보내준다. 이 과정 중에 문제가 생길수도 있다.

이를 해결하기 위한 두 가지 방법을 살펴보자.

코드를 먼저 보자. c언어 표준에는 멀티스레딩이 있지 않다. 따라서 대부분의 경우 운영체제에서 제공하는 멀티스레딩을 사용할 것이다.(즉, 어떤 운영체제 위에서 작동하는지에 따라 사용하는 프로그래밍 기술이 달라진다.)

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165781064-e6a123b6-f5c2-4f6e-bfd4-95c7e8490e5f.png">

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/165781124-36d6d523-5fc8-4601-97e4-9e68cca5b483.png">


line 30의 pthread_create를 보면, mythreadfun을 실행시키는 thread를 생성해준다. 포인터로 이를 넣어주고 있다.

myThreadFun 내에 지역변수가 있다. 쓰레드 1,2 모두 각각의 지역변수를 메모리에서 가지고 있기 때문에 문제가 생기지 않는다. 

line 7의 _Atomic이라는 type qualifier를 사용하여 경쟁 문제를 해결할 수 있다. 여러 개의 쓰레드가 동시에 이 변수를 가지고 경쟁을 하는 것을 막아준다. (단점, 아토믹 변수는 연산이 느리다)

line 33을 보면 쓰레드가 끝날 때까지 기다려주는 것도 필요하다. 메인 쓰레드가 다른 쓰레드들이 끝날 때까지 기다려주기 위해서 join을 사용한다.
