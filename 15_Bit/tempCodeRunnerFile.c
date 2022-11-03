
void char_to_binary(unsigned char uc)
{
    const int bits = CHAR_BIT * sizeof(unsigned char);

    for (int i= bits - 1; i >= 0 ; i--)      
        printf("%d", (uc >> i) & 1);
}


void print_binary(char* data, int bytes) // NOTE: extended for any sizes
{
    for (int i = 0; i < bytes; ++i)
        char_to_binary(data[bytes -1 -i]);
    printf("\n");
}

int main()
{
    struct items
    {
        /* data */
        bool has_sword           : 1;
        bool has_shield           : 1;
        bool has_potion           : 1;
        bool has_guntlet           : 1;
        bool has_hammer           : 1;
        bool has_key           : 1;
        bool has_ring           : 1;
        bool has_amulet           : 1;
    } items_flag;
    

    items_flag.has_sword    = 1; // flags = flags | MASK_SWORD;
    items_flag.has_shield   = true; // 1 대신 true도 가능하다.
    items_flag.has_potion   = 0;
    items_flag.has_guntlet  = 1;
    items_flag.has_hammer   = 0;
    items_flag.has_key      = 0;
    items_flag.has_ring     = 0;
    items_flag.has_amulet   = 0;

    printf("Size = %zd byte \n", sizeof(items_flag));

    print_binary( (char*)&items_flag, sizeof(items_flag));

    // 앞 강의 코드와 비교해보자. 훨씬 간단하다.
    if (items_flag.has_key == 1)
        printf(">> You can enter \n");

    // union 사용
    // 같은 메모리 공간을 비트필드를 이용해 값을 바꿀 수 있고, bitwise 연산자를 이용해 연산할 수도 있다!
    union 
    {
        /* data */
        struct items bf;
        unsigned char uc;
    } uni_flag ;

    uni_flag.uc = 0;
    uni_flag.bf.has_amulet = true;
    uni_flag.uc |= (1<<5);

    print_binary( (char*) & uni_flag, sizeof(uni_flag));
    
    uni_flag.bf.has_key = false;
    print_binary( (char*) & uni_flag, sizeof(uni_flag));
    /*
        KNK (MS)DOS example
    */

   struct file_time
   {
       /* data */
       unsigned int seconds : 5; // 2^5 = 32, 0~30*2 seconds
       unsigned int minutes : 6; // 2^6 = 64, 0~60 minutes
       unsigned int hours: 5;    // 2^5 = 32, 0~23 hours
   };

    struct file_date
    {
        /* data */
        unsigned int day : 5;   // 32. 0~31
        unsigned int month : 4; // 16. 1~12
        unsigned int year : 7;  // 128. 1980~
    };
    /* 1988 12 28 */
    fd.day = 28; // try overflow, try 'signed int'
    fd.month = 12;
    fd.year = 8;
    
   printf("Day %u, Month %u, Year %u \n", fd.day, fd.month, fd.year);
   
   
   scanf("%d", &fd.day); // ERROR ! 비트필더이기 떄문에 에러가 남
   //// 이유: 비트필드는 비트 단위로 메모리를 사용하기 때문에 scanf와 같이 다른 곳에 주소를 넘겨줄 때 
   //// 주소의 최소 단위인 1바이트 단위로 넘겨주기가 곤란하다. 따라서 컴파일이 막힌다!


    return 0;

}