#include "lib.h"

static void so(int *num)
{
    *num = *num + 1;
}

void in_so()
{
    int num = 0;
    so(&num);
    printf("so la: %d\n", num);
}