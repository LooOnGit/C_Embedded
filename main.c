#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int x = 77;
    int *pt = &x;
    printf("Gia tri cua x = %d \n", *pt);
    printf("Dia chi cua x la %x hoac %x \n", &x, pt); 
    printf("Dia chi cua con tro pt la %x \n", &pt);
    return 0;
}