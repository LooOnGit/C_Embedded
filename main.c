#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[] = "Hello, World!";
    char *vi_tri = strchr(chuoi, 'W');
    if (vi_tri != NULL) {
        printf("chuoi %ld\n", chuoi);
        printf("chuoi %ld\n", vi_tri);
        printf("Ký tự 'W' được tìm thấy tại vị trí: %ld\n", vi_tri - chuoi);
    } else {
        printf("Ký tự 'W' không tồn tại trong chuỗi.\n");
    }
    return 0;
}