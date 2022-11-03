#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// //// 13-01

// int main(int argc, char* argv[])
// {
//     int ch;
//     FILE* fr; //TODO: file pointer to write
//     // 이들은 파일에 대한 포인터라고 생각할 수 있는데,
//     // 엄밀히 말하면 "파일을 처리할 때 필요한 데이터의 묶음"에 대한 "포인터"이다.

//     FILE* fw;

//     /*
//     typedef struct_iobuf
//     {
//         char* _ptr;
//         int _cnt;
//         char* _base;
//         int _flag;
//         int _file;
//         int _charbuf;
//         int _bufsiz;
//         char* _tmpfname;
//     } FILE;
//     */

//    const char* out_filename = "copy.txt"; //TODO: use this

//     unsigned long count =  0;

//     if (argc != 2)
//     {
//         printf("Usage: %s filename \n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     if ((fr=fopen(argv[1], "r")) == NULL) // open a text file for reading
//     {
//         printf("can't open %s \n", argv[1]);
//         exit(EXIT_FAILURE);
//     }

//     /*
//         fopen mode strings for text files
//         - r: reading
//         - w: creating and writing or overwritting
//         - a: appending or creating-and-writing
//         - r+: both reading and writing
//         - w+: reading and writing, over-writing or creating
//         - a+: reading and writing, appending or creating
//     */

//    //TODO: open file to write with 'w' mode string
//     if ((fw = fopen(out_filename, "w")) == NULL)
//     {
//         printf("can't write %s \n", argv[1]);
//         exit(EXIT_FAILURE);
//     }

//    while ((ch=fgetc(fr)) != EOF) //getc(fr)
//    {
//        fputc(ch, stdout);

//        //TODO: use fputs() to write a file stream!
//         fputc(ch, fw);

//        count++;
//    }

//     fclose(fr);
//     // TODO:
//     fclose(fw);

//     printf("file %s has %lu characters \n", argv[1], count);
//     printf("copied to %s", out_filename);

//     return 0;
// }

//// 13-04
// #define MAX 31

// int main(void)
// {
//     FILE* fp; //TODO: file pointer to write
//     // 이들은 파일에 대한 포인터라고 생각할 수 있는데,
//     // 엄밀히 말하면 "파일을 처리할 때 필요한 데이터의 묶음"에 대한 "포인터"이다.

//     char words[MAX] = {'\0', };

//     const char* filename = "record.txt";

//     /*
//     typedef struct_iobuf
//     {
//         char* _ptr;
//         int _cnt;
//         char* _base;
//         int _flag;
//         int _file;
//         int _charbuf;
//         int _bufsiz;
//         char* _tmpfname;
//     } FILE;
//     */

//     /*
//         fopen mode strings for text files
//         - r: reading
//         - w: creating and writing or overwritting
//         - a: appending or creating-and-writing
//         - r+: both reading and writing
//         - w+: reading and writing, over-writing or creating
//         - a+: reading and writing, appending or creating
//     */

//    //TODO: open file to write with 'w' mode string
//     if ((fp = fopen(filename, "w+")) == NULL)
//     {
//         printf(stderr, "can't open \"%s\" file.\n",filename);
//         exit(EXIT_FAILURE);
//     }

//     // case1
//    while ( (fscanf(stdin,"%30s", words) == 1) && (words[0] != '.') )
//        fprintf(fp, "%s\n", words);

//     // case2: 동일한 코드지만, fscanf / fgets 의 차이를 안다면 쉽게 이해할 것이다.
//     // while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.') // fgets는 입력을 받은 후 해당 객체의 "주소"를 반환한다!! -> 따라서 입력이 없다면 null이 반환됨
//     //     fputs(words, fp);

//     /*
//         gets, scanf 차이점
//         - scanf 특성상, 한 줄에 여러 개의 단어를 입력해도 결국 여러 단어의 입력들로 받아들인다.
//         - fgets를 이용하면, 줄 단위로 이들을 받아들이게 해준다.
//     */

//     rewind(fp); // go back to the beginning of file

//     // case1
//     while ( fscanf(fp, "%s", words) == 1)
//         fprintf(stdout, "%s\n", words);

//     // case2
//     // while (fgets(words, MAX, fp) != NULL) // EOF check
//     //     fputs(words, stdout);

//     if (fclose(fp) != 0)
//         fprintf(stderr, "Error closing file \n");

//     return 0;
// }

//// 13-5 바이너리 파일

// int main()
// {
//     /*
//     fopen() mode string for binary IO
//     - rb, wb, ab
//     # plus 다음 혹은 앞에 b를 붙일 수 있다.
//     - ab+, a+b
//     - wb+, w+b
//     - ab+, a+b

//     C11 'x' mode fails if the file exists, instead of overwritting it.
//     - "wx", "wbx", "w+x", "wb+x", "w+bx"
//     */

//     // writing example

//     {
//         FILE *fp = fopen("binary_file.txt", "wb");

//         double d = 1.0 / 3.0;
//         int n = 123;
//         int *parr = (int *)malloc(sizeof(int) * n);
//         if (!parr)
//             exit(1);

//         for (int n = 0; n < 123; ++n)
//             *(parr + n) = n * 2;

//         fwrite(&d, sizeof(d), 1, fp);
//         fwrite(&n, sizeof(n), 1, fp);
//         fwrite(parr, sizeof(int), n, fp);

//         fclose(fp);
//         free(parr);

//         // total size is 8*1 + 4*1 + 123*4 = 504bytes
//     }

//     // reading example, feof(), ferror()

//     {
//         FILE *fp = fopen("binary_file.txt", "rb");
//         double d;
//         int n = 0;

//         fread(&d, sizeof(d), 1, fp);
//         fread(&n, sizeof(n), 1, fp);
//         // fread(): 입력 stream에서 size 길이의 count 항목까지 읽고, 지정된 버퍼(d,n)에 저장한다!!
//         // 파일의 위치는 읽은 바이트의 수만큼 증가한다!!
//         // 출처: ibm: https://www.ibm.com/docs/ko/i/7.3?topic=functions-fread-read-items

//         int *parr = (int *)malloc(sizeof(int) * n);
//         if (!parr)
//             exit(1);

//         fread(parr, sizeof(int), n, fp);

//         printf("feof = %d \n", feof(fp));
//         // feof() : 주어진 stream에 대해 파일의 끝 플래그가 설정되는지 여부를 표시함
//         // return: EOF flag가 설정된 경우에만 0이 아닌 값을 리턴, 나머지는 0을 리턴

//         printf("%f\n", d);
//         printf("%d\n", n);

//         for (int i = 0; i < n; ++i)
//             printf("%d ", *(parr + i));
//         printf("\n");

//         printf("feof = %d \n", feof(fp));

//         fread(&n, sizeof(n), 1, fp); // read one more toward EOF

//         printf("feof = %d\n", feof(fp)); // returns non-zero(ex. 1) at EOF
//         printf("ferror = %d\n", ferror(fp)); // return 0: ok

//         fwrite(&n, sizeof(n), 1, fp); // try writing to make an error

//         printf("ferror = %d\nn", ferror(fp)); // 0 is ok, non-zero otherwise.

//         fclose(fp);
//         free(parr);
//     }

//      return 0;
// }

//// 13-6 random access

// /*
//     ABCDEF ...
//     Current position 0 and read -> A
//     Current position 1 and read -> B
// */

// int main()
// {
//     int ch;
//     long cur;

//     FILE *fp = fopen("test.txt", "r");

//     cur = ftell(fp); // returns current location // 0
//     printf("ftell() = %ld\n", cur);

//     fseek(fp, 2L, SEEK_SET); // 이동시켜줌 // 시작점으로부터 2byte(2L) 떨어진 곳으로 이동하여 읽을 준비를 한다.
//     cur = ftell(fp);         // return 2, 3번째 글자를 읽을 준비를 함.
//     printf("ftell() = %ld\n", cur);

//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);

//     cur = ftell(fp); // return 3
//     printf("ftell() = %ld\n", cur);

//     // SEEK_CUR
//     fseek(fp, -2L, SEEK_CUR); // NOTE: SEEK_CUR을 넣어주면 "현재 위치"에서 지정한 만큼 이동해준다.
//     cur = ftell(fp);
//     printf("ftell() = %ld\n", cur);

//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch);

//     // SEEK_END
//     fseek(fp, 0L, SEEK_END);
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch); // EOF

//     fseek(fp, -1L, SEEK_END);
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch); // 80, P

//     fseek(fp, -2L, SEEK_END);
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch); // 79, O

//     /* fsetpos(), fgetpos() */

//     fpos_t pt; // file이 어마어마하게 큰 경우 FILE 대신에 사용한다.
//     // long long 으로 type define이 되어 있음
//     pt = 10;
//     fsetpos(fp, &pt); //fseek과 비슷함 //returns 0 ok
//     ch = fgetc(fp);
//     printf("%d %c\n", ch, ch); // 75, K (10번째임!)
//     fgetpos(fp, &pt); // ftell과 비슷함 //returns 0 ok
//     printf("%lld\n", pt); // long long이라서 lld // fpos_t의 format speicifier는 따로 없다.

//     return 0;
// }

//// 13-7

// int main()
// {
//     FILE* fp;
//     int ch;

//     /* ungetc() */
//     // 한 글자를 읽은 후 이를 다시 buffer에 집어넣는 함수
//     fp = fopen("input.txt", "r");

//     ch = fgetc(fp);
//     fputc(ch, stdout); // return: "

//     ungetc(ch, fp); // try another characters

//     ch = fgetc(fp); // 다시 버퍼에 넣었기 때문에, 동일한 글자가 출력됨
//     fputc(ch, stdout); // return: "

//     ch = fgetc(fp); 
//     fputc(ch, stdout); // return: I

//     fclose(fp);

//     /* setvbuf() */
//     // buffer의 설정을 바꿔줄 수 있다.

//     fp = fopen("input.txt", "r");

//     char buffer[32] = { '\0',};

//     setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // _IOLBF, IOFPF(Full), _IONBF(NO)

//     // dump buffer
//     // 출력을 하면 32글자가 출력될 것이다.
//     // file에서 buffer로 한 글자마다 옮기는 것은 느리기 때문에, 미리 buffer에 옮겨둔 후 fgetc 호출에 따라 한 글자씩 출력시킨다.

//     for (int i = 0; i < sizeof(buffer); ++i)
//             printf("%hhd", buffer[i]); 
//         printf("\n");
    
//     ch = fgetc(fp); // Read just only a single character! // 여기서 한글자를 읽게 했지만, 버퍼엔 이미 채워진다!!

//     // dump buffer
//     // 출력을 하면 32글자가 출력될 것이다.
//     // file에서 buffer로 한 글자마다 옮기는 것은 느리기 때문에, 미리 buffer에 옮겨둔 후 fgetc 호출에 따라 한 글자씩 출력시킨다.

//     for (int i = 0; i < sizeof(buffer); ++i)
//             printf("%c", buffer[i]);
//         printf("\n");
    
//     fclose(fp);


// }
