# 06-11. comma operator

```c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    for (int n=1, nsqr = n*n; n<10; n++, nsqr = n*n) // 하나의 expression 내에 두 가지 기능을 수행할 수 있다!!
    printf("%d %d \n", n, nsqr);
}
```

```c
int main()
{
    int i, j;
    i = 1;
    i++, j = i; // comma is a sequence point -> i++ is operated before comma
    printf("%d %d \n", i, j);

}
```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159131255-cc5556d9-3f3b-43ee-af11-43d17bd8fd1a.png">

# 제논의 역설 시뮬레이션 예제
---

절대 따라갈 수 없는 토끼와 거북이 이야기를 들어본 적이 있을 것이다.

```c

int main()
{
    /*  Simulatino of Moving object */

    const double speed = 1.0;
    const unsigned repeat_max = 7; // 최대 반복 횟수는 보통 양의 정수이기때문에 함(걍 int써도 됨)
    
    double dt = 1.0;
    double time = 0.0; // Elapsed time
    double dist = 0.0; // Distance

    for (unsigned i =0 ; i < repeat_max; ++i){

        dist += speed * dt ;
        time += dt;

        printf("Elapsed time = %.10fs, Distance = %.10fm \n", time, dist);

        // Half time step
        // dt = dt / 2.0 ; // 제일 먼저 떠오르는 것일 것
        dt *= 0.5; //But multiplication is faster than deviding

    }

    return 0;

}
```

# 06-13. Do while (Exit-Condition)

---

while문을 이용하여 특정 조건에서 while loop를 탈출하게 해주자.

간단하게 비밀번호를 입력하여 맞추면 종료되는 프로그램을 만들어보자.

- 코드를 짤 때, 반복되는 코드는 함수로 만들어둔다!!

## Do while을 사용하지 않을 때(비추천)

```c
main()
{
    int pw = 1234;
    int input = 0;
    printf("input your password: ");
    scanf("%d", &input);

    while (pw != input)
    {
        printf("password wrong! please type it again \n");
        printf("input your password: ");


        scanf("%d", &input);

    }
    
    printf("Login Successed");
    return 0;

}
```

## Do while문 사용(추천)

```c

int main()
{
    const int secret_code = 1234;
    int input =0;

    do
    {
        printf("Enter your secret_code  \n");
        scanf("%d", &input);
    }
    while (secret_code !=  input);

    printf("GOOD JOB!");


}
```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159155476-e79e9f09-707b-4a19-8067-4e46fa9cf9c7.png">

For문을 많이 사용하고, 다음 while문을 사용한다. 그 다음이 Do while 문이며, do while문은 특정 상황에서 매우 효율적인 때가 있다.

# 06-14. 어떤 루프를 사용할까?

---

어떤 문제를 구현할 때, 가장 먼저 생각해야 하는 것은 진입조건, 탈출조건 중 무엇을 사용할지이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159155562-c97aa71e-6f93-4bca-8d00-38a230024b34.png">

탈출 조건이 덜 쓰인다고 하더라도, 어떻게 사용하는지 숙지하고 있어야 한다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159155642-d803be41-7719-4692-8b88-2466291ea367.png">

for 문 같은 경우는 조건이 더욱 가시적이라서 같은 상황이라면 for 문이 선호되는 경우도 있다. 문제에 따라 맞는 걸 사용하자!

# 06-15. 중첩된 루프틀 (Nested Loops)

----

```c

#define NUM_ROWS 5
#define FRIST_CHAR 'A'
#define LAST_CHAR 'K'
    
int main()
{
    int r; // row loop
    int c; // character loop

    for (r=0; r < NUM_ROWS; r++) // outer loop
    {
        for (c = FRIST_CHAR; c <= LAST_CHAR; c++)
            printf("%c ", c);
        printf("\n");


    }
}

```

```c

#define NUM_ROWS '10'
#define FRIST_CHAR 'A'
    
int main()
{
    int r; // row loop
    int c; // character loop

    for (r=0; r < NUM_ROWS; ++r) // outer loop
    {
        for (c = FRIST_CHAR; c <= FRIST_CHAR + r ; ++c)
            printf("%c ", c);
        printf("\n");

    }

    return 0;
}

```


# 06-16. Array & Runtime error
---

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159192435-a3a0d894-8bd7-4c34-bc4e-1ecd77c4ee87.png">

 
<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/159192631-6bb674d0-ed43-4943-8632-4b6b764b2872.png">


# 06-17. for loop with array
---

```c

#define SIZE 5
int main()
{
    int my_arr[SIZE];


    //prepare for array data
    for (int i =0; i < SIZE; ++i)
        my_arr[i] = i * i;
        1+2; // dummy for debugger: easy to follow changes

    //print array dta
    for (int i= 0; i< SIZE; ++i)
        printf("%d ", my_arr[i]);

    //TODO: try debugger




    return 0;
}

```

# 06-18. 루프 안에서 함수의 반환값 사용하기
---

해당 숫자와 제곱수를 입력받으면 출력을 해주는 함수를 짜보자.

```c

//// 6-18

int main()
{

    int base, exp, i, result;
    scanf("%d %d", &base, &exp);

    result = 1;
    for (i =0; i< exp; ++i)
    {
        result *= base;
    }

    printf("Result = %d \n", result);

    return 0;

}

```

이를 함수로 만들어서 돌아가게 해보자.

```c



//// To function

int compute_pow(int base, int exp)
{   
    int i, result;

    result = 1;

    for (i =0; i < exp; ++i)
        result *= base;

    return result;
}

int main()
{
    int base, exp, result;


    while (scanf("%d %d", &base, &exp) == 2)
    {

        result = compute_pow(base, exp);

        printf("result = %d \n", result);
    }

    return 0;
}
```

일반적으로 함수는 위에 있어야 한다!!

- 그리고 int function()내에서 선언된 변수는 해당 영역 내에서만 사용하기 때문에, 영역별로 지정을 해 주어야 한다.

- Error and Solution: `warning: non-void function does not return a value [-Wreturn-type]`  
  - 원인: 이 에러는 변수를 선언하였지만 해당 영역에에서 변수값을 지정받지 못함
  - 해결: 필요없는 변수면 지워주고, 필요하다면 변수를 할당해준다.


main()을 위주로 보기 때문에, 함수가 위에 있으면 불편하다. 따라서, 프로토타입이란 걸 이용해서 함수 선언만 위에서, 작동시키는 코드는 아래에 둘 수 있다.

```c

//// prototype

int compute_pow(int base, int exp); //prototype 

int main()
{
    int base, exp, result;


    while (scanf("%d %d", &base, &exp) == 2)
    {

        result = compute_pow(base, exp);

        printf("result = %d \n", result);
    }

    return 0;
}

int compute_pow(int base, int exp); //prototype 
{   
    int i, result;

    result = 1;

    for (i =0; i < exp; ++i)
        result *= base;

    return result;
}

```

컴파일러가 linking 과정에서 아래부분의 함수를 찾아낸다. 찾아서 이들을 연결시켜준다. 강의 앞부분(1-9. 컴파일러와 링커:gcc compile)에서 설명하였고, 현재 이해가 되지 않는다면 반드시 이를 다시 찾아보고 올 것을 강력히 추천한다. 
