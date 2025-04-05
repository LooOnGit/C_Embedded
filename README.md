# 💡 Hướng dẫn Cấp phát Động trong C

Tài liệu này cung cấp kiến thức cơ bản và ví dụ thực tế về **dynamic memory allocation** (cấp phát động) trong ngôn ngữ lập trình C.

## 📚 Nội dung

- [Tổng quan](#tổng-quan)
- [So sánh với cấp phát tĩnh](#So-sánh-cấp-phát-tĩnh)
- [Các hàm cấp phát động](#các-hàm-cấp-phát-động)
- [Ví dụ cơ bản](#ví-dụ-cơ-bản)
- [Giải phóng bộ nhớ](#giải-phóng-bộ-nhớ)
- [Lưu ý khi sử dụng](#lưu-ý-khi-sử-dụng)

---

## 🧠 Tổng quan

Cấp phát động là quá trình **cấp phát bộ nhớ trong thời gian chạy (runtime)**, cho phép chương trình sử dụng bộ nhớ linh hoạt hơn.

## So sánh với cấp phát tĩnh
| Cấp phát bộ nhớ tĩnh| Cấp phát bộ nhớ động|
|-------------------------------------------|
|Bộ nhớ được cấp phát trước khi chạy  chương trình (trong qúa trình biên dịch)| Bộ nhớ được cấp phát trong quá trình chạy chương trình.|
|Không thể cấp phát hạy phân bổ lại bộ nhớ trong khii chạy chương trình| Cho phép quản lý, phân bố hay giải phóng bộ nhớ trong khi chạy chương trình|
|Vùng nhớ được cấp phát và tồn tại cho đến khi kết thúc chương trình| Chỉ cấp phát vùng nhớ khi cần sử dụng tới|
|Chương trình chạy nhanh hơn so với cấp phát động| Chương trình chạy chậm hơn so với cấp phát tĩnh|
|Tốn nhiểu không gian bộ nhớ hơn | Tiết kiệm được không gian bộ nhớ sử dụng|


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
