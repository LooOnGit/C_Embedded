#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *ten;
    int tuoi;
} sv_info_t;

int main() {
    sv_info_t sv1;
    sv1.ten = calloc(30, sizeof(char));  // cấp phát bộ nhớ

    printf("Nhap ten: ");
    fgets(sv1.ten, 30, stdin);

    // Xóa ký tự newline nếu có
    sv1.ten[strcspn(sv1.ten, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &sv1.tuoi);

    printf("Ten: %s\n", sv1.ten);
    printf("Tuoi: %d\n", sv1.tuoi);

    free(sv1.ten);  // giải phóng bộ nhớ đã cấp phát

    return 0;
}
