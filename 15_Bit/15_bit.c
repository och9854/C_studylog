#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>  //CHAR_BIT



//// 15-2

// unsigned char to_decimal(const char bi[]);
// void print_binary(const unsigned char num);


// int main()
// {
//     unsigned char i = to_decimal("01000110");
//     unsigned char mask = to_decimal("00000101");

//     print_binary(i);
//     print_binary(mask);
//     print_binary(i & mask);



//     return 0;
// }


// unsigned char to_decimal(const char bi[]){
//     const size_t bits = strlen(bi);
//     unsigned char sum = 0;

//     for (size_t i = 0; i < bits; i++)
//     {
//         if(bi[i] == '1')
//             sum += (int)pow(2, bits - 1 -i);
//         else if (bi[i] != '0'){
//             printf("wrong character: %c", bi[i]);
//             exit(1);
//         }
//     }

//     return sum;
// }

// void print_binary(const unsigned char num)
// {
//     printf("decimal %3d  \t == Binary ", num);

//     const size_t bits = sizeof(num) * 8;

//     for ( size_t i = 0; i < bits ; ++i)
//     {
//         const unsigned char mask = 
//             (unsigned char) pow( (double)2, (double)(bits - 1-i));
//         // unsigned char mask = pow(2, (bits -1-i));

//         if ((num & mask) == mask)
//             printf("%d", 1);
//         else
//             printf("%d", 0);
        
//     }
//     printf("\n");

// }


//// 5

// int main()
// {
//     /*

//     Signed Integers

//     - sign-magnitude representation
//     00000001 is 1 and 10000001 is -1
//     00000000 is +0, 10000000 is -0
//     Two zeros +0, -0, from -127 to +127

//     - One's complement method
//     To reverse the sign, invert each bit.
//     00000001 is 1 and 11111110 is -1
//     -127 ~ +127

//     - Two's complement method(commonly used in most systems)
//     To reverse the sign, invert each bit and 1.
//     from -128 to +127

//     */




//    return 0;
// }

//// 6

// void int_binary(const int num);


// int main()
// {
//     /* 
//         Bitwise shift operators

//         - Left shift
//         number << n : multiply number by 2^n

//         - Right shift
//         number >> n : divide by 2^n (for non-negative numbers)

//         - 적당한 숫자 내에서 작동하며, 주의가 필요하다!
//     */

//     // 8 bit integer cases
//                                     // 76543210        76543210         76543210
//     printf("%d\n", 1 << 3);    // 00000001 ->  00000001??? ->      00001000
//     printf("%d\n", 8 >> 1);    // 00001000 ->     ?0001000 ->      00000100
    
//     printf("%d\n",-119 >> 3);  // 10001001 ->     ???10001001 ->   11110001(-15) 
//     // 음수의 경우 잘 맞지 않다!!
//     printf("%d\n", 137 >> 3);  // 10001001 ->     ???10001001 ->   00010001(17)
//     // 큰 수의 경우도 잘 맞지 않다!
    
//     //printf("%d\n", -119 << 4);  // 10001001 ->    10001001???? ->   10010000(-112) 
//     printf("%d\n",137 << 4);   // 10001001 ->    10001001???? ->   10010000(144) 

//     // NOTE: the signed result is machine dependent


//     int a = 1;
//     a <<= 3;
//     a >>= 2;

//     printf("\nunsigned int %u \n", 0xffffffff);
//     printf("signed int %d \n", 0xffffffff);
//     int_binary(0xffffffff);

//     printf("right shift by 3\n");
//     int_binary( (signed)0xffffffff >> 3);
//     int_binary( (unsigned)0xffffffff >> 3);

//     printf("\nUnsigned int %u \n", 0x00ffffff);
//     printf("Signed int %u \n", 0x00ffffff);
//     int_binary(0x00ffffff);
//     printf("right shift by 3\n");

//     int_binary( (signed)0x00ffffff >> 3);
//     int_binary( (unsigned)0x00ffffff >> 3);


// }


// void int_binary(const int num)
// {
//     printf("decimal %12d == Binary ", num);

//     const size_t bits = sizeof(num) * __CHAR_BIT__;
//     for( size_t i = 0; i < bits; ++i)
//     {
//         const int mask = 1 << (bits - 1 -i);
//         // pow를 사용하지 않고 다음과 같이 깔끔하게 표현할 수 있다.
//         if ((num & mask) == mask)
//             printf("%d", 1);
//         else
//             printf("%d", 0);

//     }

//     printf("\n");
// }

//// 7

// //                      shift       Decimal  binary         Hex     octet
// #define MASK_SWORD       (1<<0)       // 2^0  0000000001    0x01     01
// #define MASK_SHIELD      (1<<1)       //      0000000010    0x02     02
// #define MASK_POTION      (1<<2)       //                    0X04     04
// #define MASK_GUNTLET     (1<<3)       //                    0X08     010
// #define MASK_HAMMER      (1<<4)       //                    0x10     020
// #define MASK_KEY         (1<<5)       //                    0x20     040
// #define MASK_RING        (1<<6)       //                    0x40     0100
// #define MASK_AMULET      (1<<7)       // 2^7 10000000       0x80     0200

// void char_binary(const char num);
// void int_binary(const int num);

// /*

//     flag            01011010
//     mask            00000011
//     mask&flag       00000010
// */

// int main()
// {
//     /*
//         bool has_sword= false;
//         bool has_shield= false;
//         bool has_potion = false;
//         bool has_guntlet = false;
//         bool has_hammer = false;
//         bool has_key = false;
//         bool has_ring = false;
//         bool has_amulet = false;
//     */
   
   
//    // 1. 게임 속에서 빈털터리로 시작함
//    // MASK flags 
   
//    char flags = 0; 
//    char_binary(flags);



//     // 2. 어쩌다 약간의 장비를 얻음
//     printf("\n Turning Bits On (Setting Bits)\n");

//     flags = flags | MASK_SWORD; // flag |= MASK_SWORD;
//     char_binary(flags);
//     flags |= MASK_AMULET;
//     char_binary(flags);


//     // 3. potion을 얻었다가 다시 잃음
//     printf("\n Turning Bits Off (clearning Bits)\n");

//     flags = flags | MASK_POTION; // flag |= MASK_SWORD;
//     char_binary(flags);
//     flags = flags & ~MASK_POTION; // flags &= ~MAKS_POTION;
//     char_binary(flags);



//     // 4. 장비를 장착했다가 풀었다가 함(toggling)
//     // XOR 사용함
//     printf("\n Toggling Bits \n");

//     flags = flags ^ MASK_HAMMER;
//     char_binary(flags);

//     flags = flags ^ MASK_HAMMER;
//     char_binary(flags);

//     flags = flags ^ MASK_HAMMER;
//     char_binary(flags);


//     // 5. game key check
//     printf("\n Checking the value of a bit \n");

//     if ((flags & MASK_KEY) == MASK_KEY)
//         printf(">> You can enter.\n");
//     else
//         printf(">> You cannot enter.\n");

//     printf("\n Trimming\n");


//     // 6. 일부의 키만 자르고 싶을 때
//     int int_flag = 0xffffffff;
//     // 1111111111111111111111111

//     int_binary(int_flag);
//     int_flag &= 0xff;
//     // Trim by 11111111
//     int_binary(int_flag);

//     return 0;
    
// }



// void char_binary(const char num)
// {
//     printf("decimal %3d \t == Binary", num);
        
//     const size_t bits = sizeof(num) * 8;
//     for (size_t i =0; i < bits; ++i)
//     {
//         const char mask = 1 << (bits - 1 -i);

//         if ((num & mask) == mask)
//             printf("%d", 1);
//         else 
//             printf("%d", 0);
//     }
//     printf("\n");
// }

// void int_binary(const int num)
// {
//     printf("decimal %12d == Binary ", num);

//     const size_t bits = sizeof(num) * __CHAR_BIT__;
//     for( size_t i = 0; i < bits; ++i)
//     {
//         const int mask = 1 << (bits - 1 -i);
//         // pow를 사용하지 않고 다음과 같이 깔끔하게 표현할 수 있다.
//         if ((num & mask) == mask)
//             printf("%d", 1);
//         else
//             printf("%d", 0);

//     }

//     printf("\n");
// }



//// 8

// #define BYTE_MASK 0xff

// int main()
// {
//     unsigned int rgba_color =  0x66CDAAFF; // 두 자리씩 대응된다.
//     // 4 bytes, medium aqua marine ( 102, 205, 170, 255)

//     unsigned char red, green, blue, alpha;

//     // Right Shift >> operator
//     alpha = rgba_color >> 0 & BYTE_MASK;    // 16진수는 2진수 4자리를 차지한다.
//     blue = (rgba_color >> 8 & BYTE_MASK); // 4자리 * 2칸 // right shift 이후 비트마스크로 출력
//     green = (rgba_color >> 16 & BYTE_MASK); // 4자리 * 4칸
//     red = (rgba_color >> 24&BYTE_MASK); // 4자리 * 6칸

//     printf("16진수 (R/G/B/A) = (%x %x %x %x) \n",
//         red, green, blue, alpha);


//     printf("10진수 (R/G/B/A) = (%hhu %hhu %hhu %hhu) \n",
//         red, green, blue, alpha);

//     return 0;

// }


//// 10 11 

// void char_to_binary(unsigned char uc)
// {
//     const int bits = CHAR_BIT * sizeof(unsigned char);

//     for (int i= bits - 1; i >= 0 ; i--)      
//         printf("%d", (uc >> i) & 1);
// }


// void print_binary(char* data, int bytes) // NOTE: extended for any sizes
// {
//     for (int i = 0; i < bytes; ++i)
//         char_to_binary(data[bytes -1 -i]);
//     printf("\n");
// }

// int main()
// {
//     struct items
//     {
//         /* data */
//         bool has_sword           : 1;
//         bool has_shield           : 1;
//         bool has_potion           : 1;
//         bool has_guntlet           : 1;
//         bool has_hammer           : 1;
//         bool has_key           : 1;
//         bool has_ring           : 1;
//         bool has_amulet           : 1;
//     } items_flag;
    

//     items_flag.has_sword    = 1; // flags = flags | MASK_SWORD;
//     items_flag.has_shield   = true; // 1 대신 true도 가능하다.
//     items_flag.has_potion   = 0;
//     items_flag.has_guntlet  = 1;
//     items_flag.has_hammer   = 0;
//     items_flag.has_key      = 0;
//     items_flag.has_ring     = 0;
//     items_flag.has_amulet   = 0;

//     printf("Size = %zd byte \n", sizeof(items_flag));

//     print_binary( (char*)&items_flag, sizeof(items_flag));

//     // 앞 강의 코드와 비교해보자. 훨씬 간단하다.
//     if (items_flag.has_key == 1)
//         printf(">> You can enter \n");

//     // union 사용
//     // 같은 메모리 공간을 비트필드를 이용해 값을 바꿀 수 있고, bitwise 연산자를 이용해 연산할 수도 있다!
//     union 
//     {
//         /* data */
//         struct items bf;
//         unsigned char uc;
//     } uni_flag ;

//     uni_flag.uc = 0;
//     uni_flag.bf.has_amulet = true;
//     uni_flag.uc |= (1<<5);

//     print_binary( (char*) & uni_flag, sizeof(uni_flag));
    
//     uni_flag.bf.has_key = false;
//     print_binary( (char*) & uni_flag, sizeof(uni_flag));
//     /*
//         KNK (MS)DOS example
//     */

//    struct file_time
//    {
//        /* data */
//        unsigned int seconds : 5; // 2^5 = 32, 0~30*2 seconds
//        unsigned int minutes : 6; // 2^6 = 64, 0~60 minutes
//        unsigned int hours: 5;    // 2^5 = 32, 0~23 hours
//    };

//     struct file_date
//     {
//         /* data */
//         unsigned int day : 5;   // 32. 0~31
//         unsigned int month : 4; // 16. 1~12
//         unsigned int year : 7;  // 128. 1980~
//     } fd;
//     /* 1988 12 28 */
//     fd.day = 28; // try overflow, try 'signed int'
//     fd.month = 12;
//     fd.year = 8;
    
//    printf("Day %u, Month %u, Year %u \n", fd.day, fd.month, fd.year);
   
   
// //    scanf("%d", &fd.day); // ERROR ! 비트필더이기 떄문에 에러가 남
//    //// 이유: 비트필드는 비트 단위로 메모리를 사용하기 때문에 scanf와 같이 다른 곳에 주소를 넘겨줄 때 
//    //// 주소의 최소 단위인 1바이트 단위로 넘겨주기가 곤란하다. 따라서 컴파일이 막힌다!


//     return 0;

// }


//// 11


// void char_to_binary(unsigned char uc)
// {
//     const int bits = CHAR_BIT * sizeof(unsigned char);

//     for (int i= bits - 1; i >= 0 ; i--)      
//         printf("%d", (uc >> i) & 1);
// }


// void print_binary(char* data, int bytes) // NOTE: extended for any sizes
// {
//     for (int i = 0; i < bytes; ++i)
//         char_to_binary(data[bytes -1 -i]);
//     printf("\n");
// }


// int main()
// {
//     struct 
//     {
//         /* data */
//         bool option1 : 1;
//         // bool     : 0;
//         bool option2 : 1;
//         unsigned long long option3 : 1;
//     } bbf;

//     printf("%zu bytes \n", sizeof(bbf)); // 

//     struct 
//     {
//         /* data */
//         unsigned short option1 : 8;
//         unsigned short option2 : 7;
//         // unsigned short : 0;
//         unsigned short option3 : 1;
//     } usbf;

//     printf("%zu bytes \n", sizeof(usbf)); // 2bytes 나옴

//     struct 
//     {
//         /* data */
//         unsigned int option1 : 1;
//         // unsigned int 1:0;
//         unsigned int option2 : 1;
//         // bool option3: 1;
//     } uibf;
    
//     printf("%zu bytes \n", sizeof(uibf)); // 2bit 밖에 없는데, 4바이트가 나온다!!

//     memset( (char*)& bbf, 0x00, sizeof(bbf)); // memset으로 1로 초기화
//     // memset: 어떤 메모리 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용함
//     // void * memset ( void * ptr, int value, size_t num );
//     // https://twpower.github.io/79-usage-of-memset-function
//     print_binary( (char*)& bbf, sizeof(bbf));
//     bbf.option1 = 1;
//     bbf.option2 = 1;
//     bbf.option3 = 1;
//     print_binary( (char*)& bbf, sizeof(bbf));

//     printf("%zu bytes\n", sizeof(bbf));



// }



//// 12

