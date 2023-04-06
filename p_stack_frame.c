#include <stdio.h>
#include <stdlib.h>

void f2(int b)
{
    int n=222;

    printf("f2(): b = %d, n = %d\n", b, n);
}

void f1(int a)
{
    int j=111;

    printf("f1(): a = %d, j = %d\n", a, j);

    f2(j);
}

int main(int argc, char *argv[])
{
    int i=2022;

    printf("main(): argv = %s, i = %d\n", argv[1], i);

    f1(i);

    exit(EXIT_SUCCESS);
}
