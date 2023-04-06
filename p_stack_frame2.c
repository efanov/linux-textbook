#include <stdio.h>
#include <stdlib.h>

void f2(int b)
{
    int age=8;

    printf("f2(): b = %d, age = %d\n", b, age);
    getchar();
}

void f1(int a)
{
    int j=0xabcd;

    printf("f1(): a = %d, j = %d\n", a, j);

    f2(j);
}

int main(int argc, char *argv[])
{
    int year=2022;

    printf("main(): argv = %s, i = %d\n", argv[1], year);

    f1(year);

    exit(EXIT_SUCCESS);
}
