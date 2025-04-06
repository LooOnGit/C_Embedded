#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Init struct Example 1

// typedef struct {
//     char *ten;
//     int tuoi;
// } sv_info_t;

//Init function example 2
void in(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("arr[%d] = %d\n", i+1, arr[i]);
    }
}

int *them(int *arr, int *n){
    int a;
    printf("Nhap phan tu can them: ");
    scanf("%d", &a);
    int *arr_2 = (int*)calloc(*n+1, sizeof(int));
    memcpy(arr_2, arr, (*n)*sizeof(int));
    arr_2[*n] = a;
    free(arr);
    (*n)++;
    return arr_2;
}

int *xoa(int *arr,int *n,int index){
    for (int i = index; i < *n; i++)
    {
        arr[i] = arr[i+1];
    }
    (*n)--;
    int *arr_2 = calloc(*n, sizeof(int));
    memcpy(arr_2, arr, (*n)*sizeof(int));
    free(arr);
    return arr_2;
}


int main() {

    //programing Example 1

    // sv_info_t sv1;
    // sv1.ten = calloc(30, sizeof(char));  // cấp phát bộ nhớ

    // printf("Nhap ten: ");
    // fgets(sv1.ten, 30, stdin);

    // // Xóa ký tự newline nếu có
    // sv1.ten[strcspn(sv1.ten, "\n")] = '\0';

    // printf("Nhap tuoi: ");
    // scanf("%d", &sv1.tuoi);

    // printf("Ten: %s\n", sv1.ten);
    // printf("Tuoi: %d\n", sv1.tuoi);

    // free(sv1.ten);  // giải phóng bộ nhớ đã cấp phát
    //===============================================================

    //Programing example 2
    int n = 10;
    int *arr = (int*)calloc(10, sizeof(int));
    for(int i = 0; i < 10; i++){
        printf("arr[%d] = ", i+1);
        scanf("%d", arr+i);
    }
    in(arr, 10);
    arr = them(arr, &n);
    in(arr, n);
    arr = xoa(arr, &n, 2);
    in(arr, n);
    return 0;
}
