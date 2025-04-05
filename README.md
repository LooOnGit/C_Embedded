# 💡 Hướng dẫn Cấp phát Động trong C

Tài liệu này cung cấp kiến thức cơ bản và ví dụ thực tế về **dynamic memory allocation** (cấp phát động) trong ngôn ngữ lập trình C.

## 📚 Nội dung

- [Tổng quan](#tổng-quan)
- [Các hàm cấp phát động](#các-hàm-cấp-phát-động)
- [Ví dụ cơ bản](#ví-dụ-cơ-bản)
- [Giải phóng bộ nhớ](#giải-phóng-bộ-nhớ)
- [Lưu ý khi sử dụng](#lưu-ý-khi-sử-dụng)

---

## 🧠 Tổng quan

Cấp phát động là quá trình **cấp phát bộ nhớ trong thời gian chạy (runtime)**, cho phép chương trình sử dụng bộ nhớ linh hoạt hơn.

## 🛠️ Các hàm cấp phát động

| Hàm     | Chức năng                              |
|---------|----------------------------------------|
| `malloc()` | Cấp phát bộ nhớ chưa khởi tạo       |
| `calloc()` | Cấp phát bộ nhớ và khởi tạo về 0     |
| `realloc()`| Thay đổi kích thước vùng nhớ đã cấp |
| `free()`   | Giải phóng bộ nhớ đã cấp phát       |

---

## 📌 Ví dụ cơ bản

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;

    // Cấp phát bộ nhớ cho mảng 5 số nguyên
    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Cấp phát thất bại!\n");
        return 1;
    }

    // Gán và in giá trị
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]);
    }

    // Giải phóng bộ nhớ
    free(ptr);

    return 0;
}
