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