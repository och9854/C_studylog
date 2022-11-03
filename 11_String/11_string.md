# 11-01. 문자열을 정의하는 방법
---

```c

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main()
{
    char words[MAXLENGTH] = "A string in an array";
    const char* pt1 = "A pointer to a string.";

    puts("Puts() adds a newline at the end:"); // puts() add \n at the end
    puts(MESSAGE);
    puts(words);
    puts(pt1);
    words[3] = 'p'; //ok
    puts(words);
    //pt1[8] = 'A'; // error // Runtime Error: 읽기 전용 메모리에 저장된 데이터의 값을 바꾸려하면 운영체제가 중단시킨다.
    // 배열은 읽기/쓰기가 모두 가능한 메모리를 사용한다. 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장되어 있다.

    char greeting[50] = "Hello and ""How are you""today?";

    puts(greeting);

    printf("%s %p %c\n", "we", "are", *"excellent programmers");
    // 이렇게 문자 앞에 indirection operator를 붙여주면 -> 첫 글자(e) 출력

    const char m1[15] = "Love you!";

    for (int i=0; i<15; ++i)
        printf("%d ", (int)m1[i]); // Note the null characters
    printf("\n");

    const char m2[15] = {'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0'}; //문자의 배열로써 초기화 // 사실상 m1과 같은 기능을 함, but caution: null을 마지막에 붙여줘야 함

    for (int i=0; i<15; ++i)
        printf("%d ", (int)m2[i]); // Note the null characters
    printf("\n");

    const char m3[] = "Love you, too!";

    for (int i=0; i<15; ++i)
        printf("%d ", (int)m3[i]); // Note the null characters
    printf("\n");


    int n = 8;
    char cookies[1] = {'A',};
    char cakes[2+5] = {'A', };
    char pies[2*sizeof(long double) + 1] = {'A',};
    // char crumbs[n]; // VLA

    char truth[10] = "Truths is ";
    if (truth == &truth[0]) puts("true!");
    if (*truth == 'T') puts("true!");
    if (*(truth+1) == truth[1]) puts("true!");
    if (truth[1] == 'r') puts("true!");


    return 0;
}

```

# 11-02. Memory Layout과 문자열

---

레이아웃은 설계도, 전체 구조 등을 의미한다. 즉, 컴퓨터가 실제로 작동할 때 메모리를 어떻게 나눠서 사용하는지 구조를 보여주는 것이다.

이번 강의의 목표는 아래 두 줄의 차이를 이해하는 것이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161698514-7345f25f-1246-4b89-8817-b4691fe342e6.png">

윗 줄은 배열이고, 아래 줄은 포인터이다. 따라서, 문자를 바꾸려고 하면 error가 발생한다. 왜 이런 이유가 발생하는지를 메모리 레이아웃과 관련해 이해할 수 있도록 하자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161698686-96a03088-002f-450d-a9f6-7ecf509a7c10.png">

본 강의는 일반적인 씨언어 강의에서는 다루지 않지만, 장기적으로 프로그래머로써 살아가기 위해 필요한 개념이다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161703810-cebef2d5-1f95-4e20-bff7-b1dfa48fb5b9.png">

char* str은 포인터로, 읽기 전용이다! 그렇기에 이를 수정하려 하면 에러가 발생하는 것이다.

실제로 그런지 확인해보자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161706906-dbc7a582-cec0-4612-852d-f5e1e9c343f3.png">

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161707134-a4ecc410-2b4e-4358-9145-b593a14ee47e.png">

다음과 같이 스택의 메모리 주소가 더 높은 것을 확인할 수 있다.

여기서 rodata low의 결과를 보면, 3번째 값을 제외한 나머지 모든 값들의 결과값이 동일하다는 것을 알 수 있다. 그 이유는 컴파일러가 코드 내에서 동일한 문자열을 인식할 때 이들을 한 번만 작성하기 때문에 동일한 메모리를 참조하게 하기 때문이다.

<img width="1225" alt="image" src="https://user-images.githubusercontent.com/78291267/161716026-c3ec1b7a-0e9b-4a90-bbd8-a4f011328cc3.png">

str1 포인터 변수 자체는 스택에 있을 것이고, 문자열 데이터는 텍스트 세그먼트에 있을 것이다!!

# 11-03. 문자열의 배열

---

이번 강의에서는 문자열의 배열을 정의하는 방법, 이 배열들이 메모리 내에서 어떻게 배치되어 있는지 디버거를 사용하여 메모리 구조를 살펴보자.

```c

int main()
{
    /* Arrays of Character Strings */

    const char* mythings[5] = {
        "Dancing in the rain",
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the C language"
    };

    char yourthings[5][40] ={
        "Studying the C++ language",
        "Eating",
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam mails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %llu %llu\n", mythings[0], (unsigned long long)mythings[0], (unsigned long long)temp1);
    printf("%s %llu %llu\n", yourthings[0], (unsigned long long)yourthings[0], (unsigned long long)temp2);

    return 0;

}

```

다음 코드가 출력된 결과를 보면, 

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161718932-ce0c7096-dc8b-4fab-becd-15b077f416cc.png">

temp1, temp2가 참조하는 메모리가 각각 (unsigned long long)mythings[0], 
(unsigned long long)yourthings[0]와 같다는 것을 알 수 있다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161719443-51cad339-0776-48ca-8fe1-87752f3b9806.png">

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/161719550-efa44e86-571b-4470-bc51-ba1762e66d78.png">

여기서도 사이즈를 확인해보면, mythings는 포인터 변수 5개 * 4byte = 20을 출력하고, yourthings는 array이기 때문에 5개 * 40btype = 200을 출력한다.

# 11-04. 문자열을 입력받는 다양한 방법들
---

```c
#define STRLEN 81

char* custom_string_input(char* st, int n);

int main()
{
    /* creating space */

    char* name = ""; // Error at RUN-TIME
    char name[128];
    int result = scanf("%s", name); // String 변수에 &가 붙지 않는 이유는 이미 그 자체로써 배열을 대표하는 주소로 들어가기 때문이다.

    /*
        scanf() vs gets()
        scanf() reads one word
        gets() reads one line and removes \n and \0
    */

   char words[STRLEN] = ""; // warning without initialization
    //gets(words); // gets recieves pointer. No idea when string ends. // don't use it rn
    //gets_s(words, sizeof(words)); //C11 지원하는 컴파일러
    int result = scanf("%s", words);

   printf("START\n");
   printf("%s", words); // no \n at the end
   puts(words);         // puts() adds \n at the end
   puts("END.");        // puts() adds \n at the end

    // TODO: try char words[5];

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin); // doesn't remove \n
    //읽을 데이터가 어느 정도의 크기일지 가늠을 하지 않음

    //TODO: replace '\n' with '\0'

    int i = 0;
    while ( words[i] != '\n' && words[i] != '\0')
        i++;
    
    if (words[i] == '\n')
        words[i] = '\0';
    
    fputs(words, stdout); // doesnt add \n
    fputs("END", stdout);



    return 0;

}

```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162114005-5c8782d0-b771-4d9b-a7a9-e95b3a100743.png">

이렇게 fgets를 사용하면, 문자열 크기에 해당하는 만큼(null 포함)만 받고, 출력을 해준다.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162114477-82e7e344-1a8c-42ea-bbf0-15a490fbe418.png">


# 11-05. 문자열을 출력하는 다양한 방법들
---
```c

#define TEST "A string from #define."

/*
    puts() whioch doesn't add a new line at the end
    Use pointer increment operaator and putchar()
*/
void custom_put(const char* str); // only two lines
int custom_put2(const char* str); // Add \n, return # of characters

int main()
{

    /* strings without \0 */

    // char str[]  = {'H', 'I', '!'}; // no \0 at the end
    // puts(str); // VS warns you!

    /* puts() and fputs() */

    // char line[100];
    // while (gets(line)) // while gets(line) != NULL
    //     puts(line);

    // char lines[100];
    // while (fgets(lines, 81, stdin))
    //     fputs(lines, stdout);

    char str[] = "Just do it, do it!";
    // printf 와 puts 동일하게 작동
    printf("%s \n", str); // \n added
    puts(str);

    
    
    /* Just do it 입력을 살펴보기 */
    char input[100] = "";
    int ret = scanf("%10s", input); //input: "just do it, do it!\n" (Note %10s)
    printf("%s \n", input); // Output: "Just" // 이유: scanf는 spacebar가 나올 때까지 읽음!
                            // %10s로 열 글자를 읽도록 해줬다고 한들, 따로 나눠서 분리됨

    ret = scanf("%10s", input);   // Reads remain buffer
    printf("%s \n", input);    // output: "do"

    ret = scanf("%10s", input);   // Reads remain buffer
    printf("%s \n", input);    // output: "it!" 



}

void custom_put(const char* str)
{
    while (*str != '\0') //while(*str)
        putchar(*str ++);
    
}

int custom_put2(const char* str)
{
    int count =0;
    while (*str)
    {
        putchar(*str ++);
        count ++;
    }
    putchar('\n');

    return count;
}
```

# 11-06. 다양한 문자열 함수들
---

```c


#include <stdlib.h>
#include <string.h>

void fit_str(char* str, unsigned int size);
char* my_strcat(char* destination, const char* source);

int main()
{
    /*
        strlen(): returns length of the string
    */

   // TODO: use debugger
    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", (int)strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", (int)strlen(msg));
    
    // TODO: implement fit_str() function

    /*
        strcat() and strncat(): string concatenation
    */

    char str1[100] = "First string";
    char str2[] = "Second string";

    /* strcat(str1, ", ");
    strcat(str1, str2); */

    /* strncat(str1, str2, 2); // append 2 characters to decide how many characters be concated */
    // output: First stringSe
    
    puts(str1); 


    //TODO: inplement my_strcat() function!
    char* str = (char*)calloc(100,1); // 동적으로 메모리 주소를 할당하기 위해 사용함. \0으로 초기화
    
    printf("%s\n", str);
    
    my_strcat(str, "Techie ");
    my_strcat(str, "Delight ");
    my_strcat(str, "– ");
    my_strcat(str, "Ace ");
    my_strcat(str, "the ");
    my_strcat(str, "Technical ");
    my_strcat(str, "Interviews");
 
    puts(str);
 

    /* 
        strcmp() and strncmp(): compare strings (not characters)
    */

    // returns: 0 if same; -1 when fronter > latter at ASCII; 1 when former < latter at ASCII
    printf("%d\n", strcmp("A","A"));                // 0
    printf("%d\n", strcmp("A","B"));                // -1
    printf("%d\n", strcmp("B","A"));                // 1
    printf("%d\n", strcmp("Hello","Hello"));        // 0
    printf("%d\n", strcmp("Banana","Bananas"));     // -1
    printf("%d\n", strcmp("Bananas","Banana"));     // 1
    
    // strncmp: compare strings by the size of int (6).
    printf("%d\n", strncmp("Bananas","Banana", 6)); // 0

    /* 
        strcpy() and strncpy()
    */

    // strcpy(): 내용물을 전부 복사해줌
    // srtncpy(): 글자수를 제한하여 복사함

    char dest[100] = ""; // make sure memory is enough
    char source[] = "Start Programming";
    // dest = source; // Error: 문자열을 배열로 선언한 후, 새 문자열로 변경시 에러 발생
    // dest = "Start something"; //Error

    strcpy(dest, source);       // destination에다가 source를 넣는 것!
    strncpy(dest, source, 5);   // '\0' is NOT added // start까지만 복사가 됨!
    strcpy(dest, source + 6);   
    strcpy(dest, source);
    strcpy(dest+6, "coding!");
    puts(dest);

    /* 
        sprintf()
        : printf()와 거의 비슷하게 사용하며, 첫 파라미터가 문자열을 담을 수 있는 메모리 배열이다. 
        뒤에 작성한 부분들을 문자열로 만들어준다.
        주로 사용하는 경우는: 연속된 파일명을 출력할 때 프로그램에서 자동으로 생성해주어 문자로 만들 때.
    */

   char str[100] = "";
   int i  =123;
   double d = 3.14;
   sprintf(str, "%05d.png %f", i, d);
   puts(str);



    return 0;
}

void fit_str(char* str, unsigned int size)
{
    if (strlen(str) > size)
        str[size] = '\0';
}

// Reference: https://www.techiedelight.com/implement-strcat-function-c/
char* my_strcat(char* destination, const char* source)
{
    //make 'ptr' point to the end of the destination string
    char *ptr = destination + strlen(destination);

    // append characeters of the source to the destination string
    while (*source != '\0')
    {
        *ptr++ = *source++;
    }

    // null terminate destination string
    *ptr = '\0';

    // the destination is returned by standard 'strcat()'
    return destination;
}
```

몇 가지 함수들을 더 살펴보자.

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162134560-69d388e6-b934-419a-a281-8751be9a753b.png">

- strchr(): 특정 글자가 시작되는 위치를 찾아서 포인터를 return한다.

- strpbrk(): 특정 글자들 중 `하나`로 시작되는 부분을 찾는다.

- strrchr(): 특정 글자가 나타나는 **가장 마지막 포인터**를 return한다.

# 11-07. 선택 정렬 문제 풀이
---

오름차순, 내림차순으로 정렬하는 코드를 짜보자.

지금 딱 한 번만 스스로 코드를 짜서 구현할 테고, 추후에는 라이브러리를 사용할 것이다. 그렇기에 지금 실제로 직접 한 번만 코딩을 해보며 머리로 구현과정을 이해하길 바란다.

```c

/*
    Selection Sort Algorithm
    https://www.geeksforgeeks.org/selection-sort/

    Youtube search "selection sort", "CS50"

*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n); // ascending order

    printArray(arr, n);

    return 0;

}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i =0; i< n-1; i++) // Note n-1
    {
        min_idx = i;
        // Find the minimum element in unsorted array
        for (j = i+1; j < n; j++) // Note i+1
        {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        // swap the found minumum element with the first element
        swap(&arr[i], &arr[min_idx]);
    }
}

```

# 11-08. 문자열의 `포인터`를 정렬하기

---

```c

#include <string.h> // strcmp()

void swap(int** xp, int** yp); // double poiter! //Note: optional
void printStringrray(char *arr[], int size); // pointer!
void selectionSort(char *arr[], int n); // pointer!

int main()
{
    char* arr[] = {"Cherry", "AppleBee", "Pineapple", "Apple", "Orange"};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n); // ascending order

    printStringrray(arr, n);

    return 0;

}



void printStringrray(char* arr[], int size) // pointer!
{
    for (int i = 0; i < size; i++)
        puts(arr[i]);
    printf("\n");
}


void swap(int** xp, int** yp) // double poiter! //Note: optional
{
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void selectionSort(char *arr[], int n) // pointer!
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i =0; i< n-1; i++) // Note n-1
    {
        min_idx = i;
        // Find the minimum element in unsorted array
        for (j = i+1; j < n; j++) // Note i+1
        {
            if ( strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        // swap the found minumum element with the first element
        /* 이중포인터 없이 구현
        char* temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp; 
        */ 
        /* 이중 포인터 구현 */
        swap(&arr[i], &arr[min_idx]);
    }
}


```

# 11-09. 문자 함수를 문자열에 사용하기 ctype.h
---

```c


#include <ctype.h> // toupper(), ispunct(), ...
#include <string.h>

#define NUM_LIMIT 1024

void ToUpper(char* str);
int PunctCount(const char* str);

int main()
{
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n'); // find first newline
    if (new_line)
        * new_line   = '\0';
    
    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));
}

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char* str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    return ct;
}

```

# 11-10. 명령줄 인수(Commmand Line Arguments)
---

프로그램이 실행될 때 main()함수 내에 매개변수를 어떻게 넣어줄까?

사용자가 프로그램을 실행시킬 때 argument들을 넣어줄 수 있는데, 실행 파일을 command line에서 직접 실행을 할때 인자를 넣어줄 수 있다.

```c
int main(int argc, char * argv[])
{
    int count;

    printf("The command line has %d arguments: \n", argc);

    for (count = 0; count < argc; count++)
        printf("arg %d : %s \n", count, argv[count]);
    printf("\n");

    return 0;
}
```

<img width="100%" alt="image" src="https://user-images.githubusercontent.com/78291267/162151354-0b8cd576-7414-4e75-a172-8fac3cf6c747.png">

다음과 같이 프롬프트에서 실행할 때 input을 함께주면, 정상적으로 출력되는 것을 볼 수 있다.

# 11-11. 문자열을 숫자로 바꾸는 방법들

---

프롬프트에서 입력을 받은 문자들을 원하는 수만큼 반복하여 출력하게 할 수 있고, 혹은 들어오는 입력들을 숫자로 바꾼 후(atoi()) summation 후 출력을 하게 할 수 있다.

앞으로 자주 사용하게 될 것이다.

```c


#include <stdlib.h>

int main(int argc, char * argv[])
{
    /* 
        string to integer, double, long'
        atoi(), atof(), atol() // 문자열을 정수, 실수, long으로 바꿔줌
     */

    if (argc < 3)
        printf("wrong usage of %s\n", argv[0]);
    else
    {
        /* example 1 */

        int times = atoi(argv[1]);
        // atof(), atol()

        for (int i = 0; i < times; i++)
            puts(argv[2]);
        
        /* ex2 */

        printf("Sum = %d \n", (atoi(argv[1]) +atoi(argv[2]) ));

    }

    /*
        string to long, unsigned long, double
        strtol(), strtoul(), strtod()
        
        strtod() converts base 10 only
    */

    char str1[] = "1024Hello"; // negative is also available
    char *end;
    unsigned long l = strtol(str1, &end, 10); // end 자리엔 이중포인터
    printf("%s %ld %s %d \n", str1, l, end, (int)*end);
    // 1024Hello 1024 Hello 72 
    // end 결과를 보면, Hello 문자열을 출력하고 있다. 이는, 숫자로 변환할 수 없는 문자가 들어오면 해당 포인터를 반환한다.

    // 16진수의 경우, FF도 숫자이기 때문에 이전과 다른 결과가 나온다.
    char str2[] = "10FFHello";
    l = strtol(str2, &end, 16);
    printf("%s %ld %s %d \n", str2, l, end, (int)*end);

    /* 
        numbers to strings
        use sprintf() instead of itoa(), ftoa()
    */

   char temp[100] ;
   puts(_itoa(10, temp, 16));
   
   // But, itoa(), ftoa()는 표준이 아니기 때문에 사용을 권장하지 않으며,
   // 실제로 실무에서도 sprintf()가 주로 사용된다

   sprintf(temp, "%x", 10);
   puts(temp);

   return 0;
      
}