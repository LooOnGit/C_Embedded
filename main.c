#include <stdio.h>
#include <stdlib.h>

int global_var = 100;           // Data segment
static int static_var = 200;    // Data segment
int bss_var;                    // BSS segment

int main() {
    int local_var = 10;         // Stack
    int *heap_var = malloc(4);  // Heap

    printf("Code (text): %p\n", main);
    printf("Data: %p\n", &global_var);
    printf("BSS: %p\n", &bss_var);
    printf("Heap: %p\n", heap_var);
    printf("Stack: %p\n", &local_var);

    free(heap_var);
    return 0;
}
