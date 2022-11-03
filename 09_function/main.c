#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h> header file에서 이미 include했기 때문에 필요없다.
#include "my_print_functions.h"

int main()
{
	{
    print_hello();
    print_hi();

    print_hello();
    print_hi();

    print_str("No one lives forever.");
    print_str("Valar morghulis");

    return 0;
	}
}
