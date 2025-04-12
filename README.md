C
# 📖 Hướng dẫn về String trong C

Tài liệu này cung cấp kiến thức cơ bản, ví dụ thực tế và giải thích rõ ràng về **string (chuỗi)** trong lập trình C.

---

## 📚 Mục lục

- [Tổng quan](#tổng-quan)
- [Cách khai báo chuỗi](#cách-khai-báo-chuỗi)
- [Các hàm xử lý chuỗi phổ biến](#các-hàm-xử-lý-chuỗi-phổ-biến)
- [Ví dụ minh họa](#ví-dụ-minh-họa)
- [Lưu ý khi sử dụng chuỗi](#lưu-ý-khi-sử-dụng-chuỗi)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

---

## 🧠 Tổng quan

Trong ngôn ngữ lập trình C, **string** (chuỗi) là một mảng các ký tự được kết thúc bằng ký tự null (`'\0'`). Chuỗi không phải là kiểu dữ liệu riêng biệt mà được biểu diễn dưới dạng mảng ký tự.

---

## ⚙️ Cách khai báo chuỗi

### 1. Khai báo và khởi tạo trực tiếp:
```c
char str[] = "Hello, World!";
```
- Chuỗi này tự động thêm ký tự '\0' ở cuối.

### 2. Khai báo mảng ký tự:
```c
char str[20] = "Hello";
```

## 🔧 Các hàm xử lý chuỗi phổ biến

### 1. `strlen`: Tính độ dài chuỗi

Hàm `strlen` được sử dụng để tính độ dài của một chuỗi (không bao gồm ký tự null `'\0'`).

**Cú pháp**:
```c
size_t strlen(const char *str);
```
**Tham số**:
- `str`: Chuỗi cần tính độ dài.

**Trả về giá trị**:
- Độ dài của chuỗi (số ký tự, không tính **'\0'**).

**Ví dụ:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[] = "Hello";
    size_t do_dai_chuoi = strlen(chuoi);
    printf("Độ dài chuỗi = %zu\n", do_dai_chuoi);
    return 0;
}
```
### 2. `strcpy`: Sao chép chuỗi
Hàm `strcpy` được sử dụng để sao chép nội dung của một chuỗi nguồn vào một chuỗi đích.

**Cú pháp**:
```c
char *strcpy(char *dest, const char *src);
```
**Tham số**:
- `dest`: Chuỗi đích (nơi nhận nội dung).
- `src`: Chuỗi nguồn (nội dung cần sao chép).

**Trả về giá trị**:
- Con trỏ đến chuỗi đích `dest`.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char nguon[] = "Hello, World!";
    char dich[20];
    strcpy(dich, nguon);
    printf("Chuỗi đích: %s\n", dich);
    return 0;
}
```

### 3. `strcat`: Nối hai chuỗi
Hàm `strcat` được sử dụng để nối chuỗi nguồn vào cuối chuỗi đích.

**Cú pháp**:
```c
char *strcat(char *dest, const char *src);
```
**Tham số**:
- `dest`: Chuỗi đích (nơi nối thêm nội dung).
- `src`: Chuỗi nguồn (nội dung cần nối).

**Trả về giá trị**:
Con trỏ đến chuỗi đích ``dest``.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[] = ", World!";
    strcat(str1, str2);
    printf("Chuỗi sau khi nối: %s\n", str1);
    return 0;
}
```

### 4. `strcmp`: So sánh hai chuỗi
Hàm `strcmp` được sử dụng để so sánh hai chuỗi.

**Cú pháp**:
```c
int strcmp(const char *str1, const char *str2);
```
**Tham số**:
- `str1`: Chuỗi thứ nhất.
- `str2`: Chuỗi thứ hai.

**Trả về giá trị**:
- `0`: Nếu hai chuỗi bằng nhau.
- `< 0`: Nếu str1 nhỏ hơn `str2`.
- `> 0`: Nếu str1 lớn hơn `str2`.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abc";
    char str2[] = "def";
    int ket_qua = strcmp(str1, str2);
    if (ket_qua == 0) {
        printf("Hai chuỗi bằng nhau.\n");
    } else if (ket_qua < 0) {
        printf("Chuỗi str1 nhỏ hơn str2.\n");
    } else {
        printf("Chuỗi str1 lớn hơn str2.\n");
    }
    return 0;
}
```
### 5. `strchr`: Tìm ký tự trong chuỗi
Hàm `strchr` được sử dụng để tìm vị trí đầu tiên của một ký tự trong chuỗi.

**Cú pháp**:
```c
char *strchr(const char *str, int c);
```
**Tham số**:
- `str`: Chuỗi cần tìm.
- `c`: Ký tự cần tìm.

**Trả về giá trị**:
Con trỏ đến vị trí đầu tiên của ký tự trong chuỗi, hoặc `NULL` nếu không tìm thấy.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[] = "Hello, World!";
    char *vi_tri = strchr(chuoi, 'W');
    if (vi_tri != NULL) {
        printf("Ký tự 'W' được tìm thấy tại vị trí: %ld\n", vi_tri - chuoi);
    } else {
        printf("Ký tự 'W' không tồn tại trong chuỗi.\n");
    }
    return 0;
}
```
### 6. `strstr`: Tìm chuỗi con trong chuỗi
Hàm `strstr` được sử dụng để tìm vị trí đầu tiên của một chuỗi con trong chuỗi.

**Cú pháp**:
```c
char *strstr(const char *haystack, const char *needle);
```
**Tham số**:
- `haystack`: Chuỗi cần tìm.
- `needle`: Chuỗi con cần tìm.

**Trả về giá trị**:
Con trỏ đến vị trí đầu tiên của chuỗi con trong chuỗi, hoặc `NULL` nếu không tìm thấy.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[] = "Hello, World!";
    char *vi_tri = strstr(chuoi, "World");
    if (vi_tri != NULL) {
        printf("Chuỗi 'World' được tìm thấy tại vị trí: %ld\n", vi_tri - chuoi);
    } else {
        printf("Chuỗi 'World' không tồn tại trong chuỗi.\n");
    }
    return 0;
}
```
### 7. `strtok`: Tách chuỗi thành các token

Hàm `strtok` được sử dụng để tách một chuỗi thành các phần nhỏ hơn (token) dựa trên các ký tự phân tách.

**Cú pháp**:
```c
char *strtok(char *str, const char *delim);
```
**Tham số**:
- `str`: Chuỗi cần tách (chỉ cần truyền chuỗi gốc trong lần gọi đầu tiên, các lần sau truyền `NULL`).
- `delim`: Chuỗi chứa các ký tự phân tách.

**Trả về giá trị**:
- Con trỏ đến token đầu tiên tìm thấy.
- `NULL` nếu không còn token nào.

**Ví dụ**:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[] = "Hello,World,This,Is,C";
    char *token = strtok(chuoi, ",");
    
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
```

![alt text](image.png)