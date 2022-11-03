# 09-01. 함수가 필요할 때
---

왜 함수가 필요한지, 어떤 경우에 함수가 필요한지부터 알아보자.

함수를 사용하지 않던 코드들을 함수를 사용하여 동작하도록 하는 것을 re-factoring이라고 한다.


```c

#define _CRT_NOSECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH 40
#define NAME "ChangHyun Oh"
#define ADDRESS "CA, USA"

void print_chars(char c, int n_stars, bool endl)
{
    for (int i =0; i < n_stars; ++i)
        printf("%c",c);
    if (endl == true)
        printf("\n");

}

void print_centered_str(char str[])
{

    int n_blanks = 0;

    n_blanks = (WIDTH - strlen(str)) / 2; // 좌우에 들어갈 수 계산
    print_chars(' ', n_blanks, false); //빈칸 넣어주기

    printf("%s\n", str);
}

int main()
{
    print_chars('*', WIDTH, 1);


    print_centered_str(NAME);
    print_centered_str(ADDRESS);

    print_chars('*', WIDTH, 0);

    return 0;
}

```

# 09-02. 함수의 프로토타입
---

9-1 에서의 코드를 이용해 강의를 진행한다. 

앞으로 여러분들은 현대적 프로그래밍을 진행하기 때문에, 모든 함수가 내부적으로 작동하는지 외울 필요는 없다. 아주 복잡한 모듈들을 조합하면서 작업을 하게 될 것이다.

그렇다면, 어디까지는 최소한으로 알아야 할까? 바로 **무엇이 들어가고 무엇이 나오는지**까지는 알아야 한다! 그래서 그 부품들을 조립해서 재빠르게 작동하는 프로그램을 만드는 것이다!!

이를 위해 숙지하고 있어야 할 개념은 **블랙박스 함수**이다. 입력/출력이 무엇인지 알지만, 내부에서 어떻게 작동하는지는 알 수 없다는 것을 의미한다. 코딩을 할 때 이를 먼저 디자인 한 이후에, 그 내부를 채워가는 식으로 코딩을 해나가는 것이 최근에 많이 사용되는 방법이다.

function의 definition, body를 정의하고 이를 main 함수에서 사용한다. 하지만 컴퓨터 빌드는 이와 다르게 진행된다. 컴퓨터가 컴파일을 할 때는, 블랙박스로써 무엇인지만 알면 된다. 즉, main() 함수 위에서는 입력/출력이 무엇인지만 알면 컴파일을 할 수 있다.(= 함수의 프로토타입만 있어도 빌드를 할 수 있다!)

프로토타입만 있어도, 빌드는 정상적으로 진행된다!! 이것이 우리의 직관과는 다른 C/C++ 의 특징 중 하나이다. 그 이후에는 파일을 분리하여서 프로토타입만 main() 함수에 넣어줄 수 있다!!

~~프로토타입의 argument 내에는 빈칸으로 두어도 된다. 이후에 실제로 함수를 짤 때 argument를 지정해줘도 된다. (예전에는 그렇게 코딩함) (단, void를 넣으면 안됨)~~

# 09-03. 함수의 자료형과 반환값

---

```c

int int_min(int, int);

int main()
{
    int i1, i2;

    while(1)
    {
        printf("Input two integers: ");

        if(scanf("%d %d", &i1, &i2) != 2) break;

        int lesser = int_min(i1, i2);
        // int lesser = min;
        printf("The lesser of %d and %d is %d \n", i1, i2, lesser);

        //printf("The lesser of %d and %d is %d \n", i1, i2, int_min(i1, i2));
    }
}

int int_min( int i, int j)
{
    return (i < j) ? i:j; // ternary operation
}

```

다음과 같이 자료형을 반환하고, int_min function에서는 return에서 삼항연산자를 이용하여 return한다!

# 09-04. 변수의 영역과 지역 변수(scope, local variable)
---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160733343-009f236e-0270-4780-bf71-2c332eb535f4.png">

# 09-05. 지역 변수와 스택(Stack)
----

지역변수와 스택이 어떻게 작용하는지를 알아보자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160734034-833de415-2078-4442-b21e-2a4e34c83f80.png">

# 09-06. Recursion
---
```c

void my_func(int);

int main()
{
    my_func(1);
    return 0;
}

void my_func(int n)
{
    printf("level %d, address of variable n = %p \n", n, &n);

    my_func(n+1);

    //Stop condition

    //Tail recursion


}

```


# 09-07. Recursion and Stack
---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160851862-87915935-e6ed-4805-992c-1ecec165e545.png">

# 09-08 팩토리얼 예제
---

```c

long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
    int num = 3;

    printf("%ld \n", loop_factorial(num));
    printf("%ld \n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n)
{
    long ans;

    for (ans = 1; n > 1; n--)
        ans *= n;

    return ans; 
}

long recursive_factorial(int n)
{

    if (n > 0)
    {
        return n * recursive_factorial(n-1); // tail(end) recursion
    }
    else
        return 1;
}

```

# 09-09. 이진수 변환 예제
---

이번 강의에서는 재귀호출을 이용하여 10진수를 2진수로 변환하여 보자.

```c

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
    unsigned long num =10;

    print_binary_loop(num);
    print_binary(num);

    printf("\n");

    return 0;
}

// note: printing order is reversed!

void print_binary_loop(unsigned long num)
{
    while(1)
    {
        int quotient = num/2;
        int remainder = num %2;

        printf("%d", remainder); //remainder is 0 or 1

        num = quotient;
        if (num ==0) break;
    }
    printf("\n");
}

void print_binary(unsigned long num)
{

    int remainder = num % 2;

    if (num >=2)
        print_binary(num/2);
    printf("%d", remainder);
    return;

}


```

# 09-10. 피보나치 예제와 재귀 호출의 장단점
---
```c

int fibonacci(int number);

int main()
{
    for (int count = 1; count < 13; ++count)
        printf("%d ", fibonacci(count));
    return 0;
}

int fibonacci(int number)
{
    if (number > 2)
        return fibonacci(number -1) + fibonacci(number -2);
    else
        return 1;
}
```

재귀호출을 2개를 return한다! double recursion이라고 부른다.

하지만 이들은 메모리를 많이 사용하기 때문에 비효율적이다. 스택에는 변수 뿐만 아니라 함수 또한 같이 쌓이기 때문에, 메모리를 많이 사용한다.

# 09-11. 헤더파일 만드는 방법
---

`my_print_function.h`와 같이, 원하는 함수들을 저장해둔 헤더파일을 만들 수 있다. 헤더파일의 제목은 파일이 가지는 함수들을 잘 나타내는 것으로 설정한다.

`#pragma once`라는 것은 header guard로, 이는 추후에 다룰 예정이다.

main.c에서 만들어둔 함수들을 헤더파일로 옮겨보자. 다음은 header file이다.

```h
#pragma once 
#include <stdio.h>

void print_hello()
{
    printf("hello \n");
    //many more lines
}

void print_hi()
{
    printf("Hi \n");

}

void print_str(char* str)
{
    printf("%s\n", str);
}

```

이제 main함수에서 `#include "my_print_functions.h"` 다음과 같이 헤더파일을 include해주면 외부 파일에서 함수들을 호출하여 run할 수 있다.

다음은 main.c 코드이다.

```c

#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> header file에서 이미 include했기 때문에 필요없다.
#include "my_print_functions.h"

int main()
{
    print_hello();
    print_hi();

    print_hello();
    print_hi();

    print_str("No one lives forever.");
    print_str("Valar morghulis");

    return 0;
}

```

헤더파일과 동일한 제목의 c file을 하나 생성하여 이를 저장한다.

다음은 my_print_functions.c 파일의 코드이다.

```c
#include "my_print_functions.h"

void print_hello()
{
    printf("hello \n");
    //many more lines
}

void print_hi()
{
    printf("Hi \n");

}

void print_str(char* str)
{
    printf("%s\n", str);
}
```

> 여기서 헤더파일은 프로토타입 선언만 하듯이 수정해준다. 헤더파일은 일종의 목차, 차례 역할을 한다!!

```h
#pragma once 
#include <stdio.h>

void print_hello();

void print_hi();

void print_str(char* str);

//assume that we have many more longer functions

```

# 09-12. 포인터의 작동 원리

---

앞 강의 컴퓨터의 작동 원리를 보았다면, 포인터도 잘 이해할 것이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160951523-50592290-5999-4836-8429-f2ccc78426f7.png">

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160954848-280c9bce-1ecd-420d-bf66-6ff02f1478d9.png">

&를 통해 우리가 알고 싶어하는 주소값을 알 수 있다. 단항연산자로 작동하게 된다.

주소값을 저장하는 변수를 선언할 때는 변수의 이름 앞에 *을 붙여주면 된다! 앞에 int가 붙어있는 경우, int형 변수의 주소를 저장할 수 있다. a_ptr도 변수라는 점이 중요하다! **이들도 어떤 값을 저장하는 변수이기 때문에, 메모리에 공간을 가지고 있다.** 그리고 그 메모리에 주소값을 저장하는 것이다. 

포인터 변수는 주소의 '값'을 저장한다. 이는 다른 메모리 공간이나 그 공간에 저장된 데이터(or object)를 간접적으로 **가리키는** 역할을 한다. 여기서 pointer라는 개념의 어원이 나온다.



# 09-13. 포인터의 기본적인 사용방법

---

```c

int main()
{
    int a, b;

    a=123;

    int *a_ptr; // * : asterisk

    a_ptr = &a; // & : address of operator

    printf("%d %d %p \n", a, *a_ptr, a_ptr);

    *a_ptr = 456; // *: re-direction or de-referencing

    printf("%d %d %p \n", a, *a_ptr, a_ptr);

    b = *a_ptr; // int b 변수에 a_ptr 대입하기

    printf("%d \n", b);

    *a_ptr = 789;

    printf("%d \n",b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b); // a,b 주소가 다름을 확인할 수 있다.

}


```

# 09-14. 포인터와 코딩 스타일
---

포인터는 문법과 연관하여 주의할 점이 있다. 코딩 스타일은 협업하는 사람과 정하거나 회사에서 정해진 규칙대로 하면 된다.

## // int *a_ptr vs int* a_ptr

# 09-15. NULL pointer와 런타임 에러
---

포인터 변수를 초기에 초기화를 해 주지 않으면 쓰레기 값이 들어가 있을 것이다. 그 쓰레기 값도 메모리 주소로 여겨져서 사용될 것이다. 이 쓰레기 주소를 따라서 간들, 잘못된 주소를 출력하여 문제가 생길 것이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/160964346-dd6d134a-d729-443c-ba02-48189bb8db76.png">

이를 방지하기 위해서는 NULL pointer를 사용하여 해결한다.

```c

int main()
{

    int a =1234;
    printf("%p \n", &a);
    printf("%d \n", a);

    // int *ptr;

    // printf("%p \n", ptr);
    // printf("%p \n", *ptr);

    int *safer_ptr = NULL;

    int b;

    scanf("%d", &b);

    if (b%2==0)
        safer_ptr = &a;

    if (safer_ptr != NULL)
        printf("%p \n", safer_ptr);

    if (safer_ptr != NULL)
        printf("%d \n", *safer_ptr);

    return 0;
}

```

b에서 1을 읿력받는다고 하더라도 safer_ptr이라는 변수는 NULL값을 갖고 있을 것이다. 그렇기 때문에, 아래와 같이 NULL 값이면 사용하지 않게 할 수 있다.

# 09-16. 디버거로 메모리 들여다보기
---
```c

#include <stdio.h>

int main()
{
    int a=3, b=5, c=7, d=9;
    int *a_ptr = &a, *b_ptr = &b, *c_ptr = &c, *d_ptr = &d;
    
    printf("%p %p %p %p", &a, &b, &c, &d );
    
    return 0;
}

```

# 09-17. 포인터 변수의 크기
---

```c

void main()
{
    char a;
    float b;
    double c;

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    printf("%zd %zd %zd \n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd \n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));
    printf("%zd %zd %zd \n", sizeof(&a), sizeof(&b), sizeof(&c));
    printf("%zd %zd %zd \n", sizeof(char*), sizeof(float*), sizeof(double*));
}

```
<img width="50%" alt="image" src="https://user-images.githubusercontent.com/78291267/160972215-6ed5a2a4-79e6-4f1a-9223-6e417c796fd6.png">

다음과 같이 결과가 나온다. x86, x64에 따라 결과가 다르게 나온다!

이번 강의에서는 다양한 자료형에 대한 포인터 변수들이 모두 **size가 같다** 라는 것을 확인해보았다. 메모리 주소의 값을 저장하는 것이 포인터 변수이기 때문에, 이러한 성질이 나타난다.

# 09-18. 포인터형 매개변수

---


```c

int main()
{
    int a= 123;
    int b=456;
    //swap code
    int temp = a;
    a = b;
    b = temp;

    printf("%d %d\n", a, b);
    
    return 0;
}
```

다음과 같이 두 변수를 swap하는 기능은 매우 자주 사용한다. 따라서, 이를 함수로 만들어두면 좋을 것이다.

```c

void swap(int* a, int* b)
{   
    printf("%p %p \n", a, b);

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a= 123;
    int b= 456;
    //swap code
    int* a_ptr = &a;
    int* b_ptr = &b;

    printf("%p %p\n", &a, &b);
    
    swap(a_ptr, b_ptr);
    
    printf("%d %d\n", a, b);
    return 0;
}

```

다음과 같이 포인터를 이용하여 주소값을 바꿔준다.

포인터의 중요한 용법으로써, 함수의 매개변수로써의 포인터를 사용하는 방법에 대해 알아보았다.

파이썬, 자바 등에서는 이렇게 코딩하지 않는다. 다만, `모든 일에는 대가를 치뤄야 한다`. 속도가 느려진다. 결국, 효율이 높은 프로그램을 작성하기 위해서는 포인터 혹은 그에 상응하는 무언가를 사용해야 할 일이 많이 있다.

따라서, 초보인 때일수록 포인터 개념을 명확히 이해하고 계속 공부해나가면 여러가지로 도움이 될 것이다.
